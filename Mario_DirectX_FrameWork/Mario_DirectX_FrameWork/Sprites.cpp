#include "Sprites.h"


Sprites* Sprites::__instance = NULL;

Sprites::Sprites()
{
}

void Sprites::LoadSprites()
{
	Game* game = Game::GetInstance();
	CreateSprite(MARIO_TEXTURE, "resources/Sprites/MarioDB.xml");
	CreateSprite(ENEMY_TEXTURE, "resources/Sprites/EnemyDB.xml");
	CreateSprite(MISC_TEXTURE, "resources/Sprites/MiscDB.xml");
	//CreateSprite(FIREBALL_TEXTURE, )
	//CreateSprite(UI_TEXTURE, "resources/Sprites/UiDB.xml");
}

void Sprites::Add(string id, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 texture, int xPivot)
{
	LPSPRITE s = new Sprite(id, xPivot, left, top, width, height, texture);
	
	//sprites[id] = s;
	sprites.insert(make_pair(id, s));
}

int Sprites::CreateSprite(string textureName, string filePath)
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
		TiXmlElement* texture = root->FirstChildElement();
		texture != nullptr;
		texture = texture->NextSiblingElement()
		)
	{
		string textureID = texture->Attribute("id");
		if (textureID != textureName)
		{
			continue;
		}
		OutputDebugString(ToLPCWSTR(textureID));
		OutputDebugString(L"\n");
		LPDIRECT3DTEXTURE9 tex = Textures::GetInstance()->GetTexture(textureID);

		if (tex != NULL)
		{
			OutputDebugString(L"Create Sprite from Texture file: \n");
			OutputDebugString(ToLPCWSTR(filePath));
			OutputDebugString(L"\n");
		}
		else
		{
			OutputDebugString(L"[ERROR] Can not create sprite from Texture file: \n");
			OutputDebugString(ToLPCWSTR(filePath));
			OutputDebugString(L"\n");
			return 0;
		}

		for (TiXmlElement* node = texture->FirstChildElement(); node != nullptr; node = node->NextSiblingElement())
		{
			string spriteID = node->Attribute("id");
			int left;
			int top;
			int width;
			int height;
			int pivotX;
		
			node->QueryIntAttribute("left", &left);
			node->QueryIntAttribute("top", &top);
			node->QueryIntAttribute("width", &width);
			node->QueryIntAttribute("height", &height);

			if (node->QueryIntAttribute("xPivot", &pivotX) != TIXML_SUCCESS)
			{
				pivotX = -1;
			}
			pivotX *= 3;

			Add(spriteID, left, top, width, height, tex, pivotX);
		}
		return 1;
	}
}

LPSPRITE Sprites::Get(string id)
{
	//return sprites.at(id);
	return sprites[id];
}

Sprites* Sprites::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Sprites();
	}
	return __instance;
}

Sprites::~Sprites()
{
	for (auto x : sprites)
	{
		LPSPRITE s = x.second;
		delete s;
	}

	sprites.clear();
}
