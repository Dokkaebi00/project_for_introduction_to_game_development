#include "Game.h"


Game* Game::__instance = NULL;
float Game::dt = 0.0f;
float Game::timeScale = 1.0f;

void Game::InitDirect3DX(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	
	this->hWnd = hWnd;
	
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

	if (!spriteHandler)
	{
		MessageBox(hWnd, L"Creating sprite handler failed!", L"Error", MB_OK | MB_ICONERROR);
		return;
	}

	OutputDebugString(L"[INFO] Init Direct3DX Done \n");
}

LPDIRECT3DTEXTURE9 Game::LoadTexture(LPCWSTR texturePath)
{
	return LPDIRECT3DTEXTURE9();
}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha)
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;
	rect.left = left;
	rect.top = top;
	rect.right = right;
	rect.bottom = bottom;
	spriteHandler->Draw(texture, &rect, NULL, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha)
{
	D3DXVECTOR3 p(x, y, 0);
	spriteHandler->Draw(texture, &r, NULL, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

void Game::GameInit()
{
}

void Game::Update()
{
}

void Game::Render()
{
	if (d3ddv->BeginScene())
	{
		d3ddv->ColorFill(backBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		/*if (activeScene != nullptr)
			activeScene->Render();
		*/
		spriteHandler->End();

		d3ddv->EndScene();
	}

	d3ddv->Present(NULL, NULL, NULL, NULL);
}

void Game::GameLoop()
{
	MSG msg;
	int done = 0;

	int frameStart = GetTickCount();
	int deltat = 0;

	float tickPerFrame = float(1000.0f / 120.0f);

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				done = 1;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		int now = GetTickCount();
		deltat = now - frameStart;
		dt = deltat;

		if (deltat >= tickPerFrame)
		{
			Update();
			Render();
			deltat = 0.0f;
		}
		else
		{
			Sleep(tickPerFrame - deltat);
			deltat = tickPerFrame;
		}
	}
}

void Game::GameEnd()
{
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

float Game::GetTimeScale()
{
	return 0.0f;
}

void Game::SetTimeScale()
{
}

float Game::GetDeltatTime()
{
	return 0.0f;
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
