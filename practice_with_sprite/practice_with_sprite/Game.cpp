#include "Game.h"

Game* Game::__instance = NULL;

void Game::Init(HWND hWnd)
{
	LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);

	this->hWnd = hWnd;

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;

	RECT r;
	GetClientRect(hWnd, &r);

	d3dpp.BackBufferWidth = r.right + 1;
	d3dpp.BackBufferHeight = r.bottom + 1;

	backBufferWidth = r.right + 1;
	backBufferHeight = r.bottom + 1;

	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv
	);

	if (d3ddv == NULL)
	{
		OutputDebugString(L"[ERROR] CreateDevice failed\n");
		return;
	}

	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	D3DXCreateSprite(d3ddv, &spriteHandler);

	OutputDebugString(L"[INFO] InitGame done;\n");

}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom)
{
	D3DXVECTOR3 p(x, y, 0);

	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;

	spriteHandler->Draw(texture, &r, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
}

LPDIRECT3DTEXTURE9 Game::LoadTexture(LPCWSTR texturePath)
{
	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();

	LPDIRECT3DTEXTURE9 texture;

	D3DXIMAGE_INFO info;

	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &info);

	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] GetImageInfoFromFile failed: %s\n", texturePath);
		return NULL;
	}

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
		D3DCOLOR_XRGB(255, 255, 255),
		&info,
		NULL,
		&texture
	);

	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] CreateTextureFromFile failed. File: %s\n", texturePath);
		return NULL;
	}

	DebugOut(L"[INFO] Texture loaded Ok: %s \n", texturePath);

	return texture;
}

void Game::DebugOut(const wchar_t* fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	wchar_t dbg_out[4096];
	vswprintf_s(dbg_out, fmt, argp);
	va_end(argp);
	OutputDebugString(dbg_out);
}

LPDIRECT3D9 Game::GetDirect3D()
{
	return this->d3d;
}

LPDIRECT3DDEVICE9 Game::GetDirect3DDevice()
{
	return this->d3ddv;
}

LPDIRECT3DSURFACE9 Game::GetBackBuffer()
{
	return this->backBuffer;
}

LPD3DXSPRITE Game::GetSpriteHandler()
{
	return this->spriteHandler;
}

int Game::GetBackBufferWidth()
{
	return this->backBufferWidth;
}

int Game::GetBackBufferHeight()
{
	return this->backBufferHeight;
}

Game* Game::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Game();
	}
	return __instance;
}

Game::~Game()
{
	if (spriteHandler != NULL) spriteHandler->Release();
	if (backBuffer != NULL) backBuffer->Release();
	if (d3ddv != NULL) d3ddv->Release();
	if (d3d != NULL) d3d->Release();
}
