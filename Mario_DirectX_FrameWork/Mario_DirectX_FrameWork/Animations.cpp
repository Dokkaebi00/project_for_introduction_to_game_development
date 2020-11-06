#include "Animations.h"

Animations* Animations::__instance = NULL;

Animations::Animations()
{
}

Animations* Animations::GetInstance()
{
    if (__instance == NULL)
    {
        __instance = new Animations();
    }
    return __instance;
}

void Animations::AddAnimation(string id, LPANIMATION ani)
{
    //animations[id] = ani;
    animations.insert(make_pair(id, ani));
}

void Animations::LoadAnimations()
{
    Game* game = Game::GetInstance();
    LoadResource(MARIO_TEXTURE,"resources/Animations/MarioAnim.xml");
    LoadResource(ENEMY_TEXTURE,"resources/Animations/EnemyAnim.xml");
    LoadResource(FIREBALL_TEXTURE,"resources/Animations/MiscAnim.xml" );
}

int Animations::LoadResource(string textureName, string filePath)
{
    TiXmlDocument file(filePath.c_str());
    if (!file.LoadFile())
    {
        OutputDebugString(L"[ERROR] can not read file \n");
        OutputDebugString(ToLPCWSTR(filePath));
        return 0;
    }

    TiXmlElement* root = file.RootElement();

    for (
        TiXmlElement* info = root->FirstChildElement();
        info != nullptr;
        info = info->NextSiblingElement()
        )
    {
        string gameObjectID = info->Attribute("gameObjectId");
        string textureID = info->Attribute("textureId");
        if (textureID != textureName)
        {
            continue;
        }

        LPDIRECT3DTEXTURE9 tex = Textures::GetInstance()->GetTexture(textureID);

        if (tex != NULL)
        {
            OutputDebugString(L"Create Animation from Texture file: \n");
            OutputDebugString(ToLPCWSTR(filePath));
            OutputDebugString(L"\n");
        }
        else
        {
            OutputDebugString(L"[ERROR] Can not create Animation from Texture file: \n");
            OutputDebugString(ToLPCWSTR(filePath));
            OutputDebugString(L"\n");
            return 0;
        }

        for (
            TiXmlElement* node = info->FirstChildElement();
            node != nullptr;
            node = node->NextSiblingElement()
            )
        {
            string aniId = node->Attribute("aniId");
            int frameTime;
            node->QueryIntAttribute("frameTime", &frameTime);
            string name = node->Attribute("name");
            LPANIMATION animation = new Animation(aniId, frameTime);

            for (
                TiXmlElement* sprNode = node->FirstChildElement();
                sprNode != nullptr;
                sprNode = sprNode->NextSiblingElement()
                )
            {
                string id = sprNode->Attribute("id");
                LPSPRITE sprite = Sprites::GetInstance()->Get(id);
                animation->Add(sprite, D3DXVECTOR2(0.0f, 0.0f), frameTime);
            }

            AddAnimation(aniId, animation);
        }
        return 1;

    }
}

LPANIMATION Animations::Get(string id)
{
    LPANIMATION ani = animations.at(id);
    if (ani == NULL)
    {
        DebugOut(L"[ERROR] Failed to find animation id: %d\n", id);
        return nullptr;
    }
    return ani;
}

LPANIMATION Animations::Clone(string id)
{
    LPANIMATION oriAni = Get(id);
    LPANIMATION copiedAni = new Animation(*oriAni);
    return copiedAni;
}

Animations::~Animations()
{
    for (auto x : animations)
    {
        LPANIMATION ani = x.second;
        delete ani;
    }
    animations.clear();
}
