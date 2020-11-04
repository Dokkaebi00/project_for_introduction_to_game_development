#include "Game.h"
#include "Utils.h"

Game* Game::__instance = NULL;
float Game::deltaTime = 0.0f;

void Game::InitDirectEnvironment(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.hDeviceWindow = hWnd;

	RECT r;
	GetClientRect(hWnd, &r);

	d3dpp.BackBufferWidth = r.right + 1;
	d3dpp.BackBufferHeight = r.bottom + 1;

	d3d->CreateDevice
	(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv
	);

	if (!d3ddv)
	{
		OutputDebugString(L"[ERROR] CreateDevice failed\n");
		return;
	}

	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	D3DXCreateSprite(d3ddv, &spriteHandler);

	OutputDebugString(L"[INFO] InitGame done;\n");
}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha)
{
	D3DXVECTOR3 p(x, y, 0);
	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;
	spriteHandler->Draw(texture, &r, NULL, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha)
{
	D3DXVECTOR3 p(x, y, 0);
	spriteHandler->Draw(
		texture,
		&r,
		NULL,
		&p,
		D3DCOLOR_ARGB(alpha, 255, 255, 255)
	);
}

LPDIRECT3DTEXTURE9 Game::LoadTexture(LPCWSTR filePath)
{
	D3DXIMAGE_INFO info;

	LPDIRECT3DTEXTURE9 texture;

	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);

	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] GetImageInfoFromFile failed: %s\n", filePath);
		return NULL;
	}

	result = D3DXCreateTextureFromFileEx
	(
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
		D3DCOLOR_XRGB(255, 255, 255),
		&info,
		NULL,
		&texture
	);

	if (result != D3D_OK)
	{
		return NULL;
	}

	return texture;
}

void Game::GameInit(HWND hWnd)
{

}

void Game::Update()
{

}

void Game::Render()
{
	if (d3ddv->BeginScene())
	{
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		spriteHandler->End();
		d3ddv->EndScene();
	}

	d3ddv->Present(NULL, NULL, NULL, NULL);
}


int Game::GameLoop(HWND hWnd)
{
	MSG msg;
	int done = 0;
	float t0 = GetTickCount();
	float t = GetTickCount();
	float tickPerFrame = 1000.0f / 120;

	while (!done)
	{
		t0 = t;
		t = GetTickCount();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				done = true;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		float dt = (t - t0);
		deltaTime = dt;

		if (dt >= tickPerFrame)
		{
			Update();
			Render();
		}

		else
		{
			Sleep(tickPerFrame - dt);
			dt = tickPerFrame;
		}
	}

	return done;
}

Game* Game::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Game();
	}

	return __instance;
}

float Game::GetDeltaTime()
{
	return deltaTime;
}



Game::~Game()
{
	if (!d3d) d3d->Release();
	if (!d3ddv) d3ddv->Release();
	if (!backBuffer) backBuffer->Release();
	if (!spriteHandler) spriteHandler->Release();
}