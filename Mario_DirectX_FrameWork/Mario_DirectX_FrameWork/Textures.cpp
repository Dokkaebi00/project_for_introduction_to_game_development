#include "Textures.h"

Textures* Textures::__instance = NULL;

Textures* Textures::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Textures();
	}
	return __instance;
}

Textures::~Textures()
{
	for (auto t : textures)
	{
		LPDIRECT3DTEXTURE9 tex = t.second;
		if (tex != NULL)
		{
			tex->Release();
		}
	}
	textures.clear();
}

void Textures::Add(string id, LPCWSTR texturePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;

	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &info);

	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] GetImageInfoFromFile failed: %s\n", texturePath);
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();
	LPDIRECT3DTEXTURE9 texture;

	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		texturePath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture
	);

	if (result != D3D_OK)
	{
		OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
		return;
	}

	textures.insert(make_pair(id, texture));
	//textures[id] = texture;

	//DebugOut(L"[INFO] Texture loaded Ok: id=%s\n", id);
	OutputDebugStringW(ToLPCWSTR("[INFO] Texture ID: " + id + "\n"));
	
	DebugOut(texturePath);
	DebugOut(L"\n");
}

LPDIRECT3DTEXTURE9 Textures::GetTexture(string id)
{
	return textures.at(id);
}

void Textures::LoadTextures()
{
	Add(MARIO_TEXTURE, L"resources\\Textures\\mario.png", D3DCOLOR_XRGB(255, 255, 255));
	Add(BBOX_TEXTURE, L"resources\\Textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	Add(ENEMY_TEXTURE, L"resources\\Textures\\enemy.png", D3DCOLOR_XRGB(255, 255, 255));
	Add(MISC_TEXTURE, L"resources\\Textures\\misc.png", D3DCOLOR_XRGB(255, 255, 255));
	Add(FIREBALL_TEXTURE, L"resources\\Textures\\fireball.png", D3DCOLOR_XRGB(255, 255, 255));
	Add(UI_TEXTURE, L"resources\\Textures\\UI.png", D3DCOLOR_XRGB(255, 255, 255));
	Add(INTRO_TEXTURE, L"resources\\Textures\\intro.png", D3DCOLOR_XRGB(255, 255, 255));

}
