#include "Textures.h"


Textures* Textures :: __instance = NULL;

Textures::Textures()
{
}

void Textures::Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);

	if (result != D3D_OK)
	{
		OutputDebugString(L"Cannot Get Info from Image");
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();
	LPDIRECT3DTEXTURE9 texture;
	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		filePath,
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
		OutputDebugString(L"Cannot Get Info from Image");
		return;
	}

	textures[id] = texture;
}

void Textures::Clear()
{
	textures.clear();
}

LPDIRECT3DTEXTURE9 Textures::Get(unsigned int id)
{
	return textures[id];
}

Textures* Textures::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Textures();
	}
	return __instance;
}
