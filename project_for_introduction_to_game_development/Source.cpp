#include"Game.h"
#include"GameObject.h"
#include"Mario.h"

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include<vector>

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define WINDOW_CLASS_NAME L"Game Window"
#define MAIN_WINDOW_TITLE L"01 - Skeleton"
#define WINDOW_ICON_PATH L"brick.ico"

#define BRICK_TEXTURE_PATH L"brick.png"
#define MARIO_TEXTURE_PATH L"mario.png"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)

Mario* mario;
LPDIRECT3DTEXTURE9 texMario = NULL;
#define MARIO_START_X 0.0f
#define MARIO_START_Y 130.0f
#define MARIO_VX 0.1f

GameObject* brick;
LPDIRECT3DTEXTURE9 texBrick = NULL;
#define BRICK_X 0.1f
#define BRICK_Y 0.1f
#define BRICK_WIDTH 16.0f

vector<LPGAMEOBJECT> brickFloor;
int n = (int)SCREEN_WIDTH / BRICK_WIDTH;
#define BRICK_FLOOR_X 0.0f
#define BRICK_FLOOR_Y 158.0f

vector<LPMARIO> alotofmario;

#define _W(x)  __W(x)
#define __W(x)  L##x

#define VA_PRINTS(s) {				\
		va_list argp;				\
		va_start(argp, fmt);		\
		vswprintf_s(s, fmt, argp);	\
		va_end(argp);				\
}

void DebugOut(const wchar_t* fmt, ...)
{
	wchar_t s[4096];
	VA_PRINTS(s);
	OutputDebugString(s);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

void LoadResources()
{
	Game* game = Game::GetInstance();
	texMario = game->LoadTexture(MARIO_TEXTURE_PATH);
	texBrick = game->LoadTexture(BRICK_TEXTURE_PATH);

	mario = new Mario(MARIO_START_X, MARIO_START_Y, MARIO_VX,texMario);
	brick = new GameObject(BRICK_X, BRICK_Y, texBrick);

	for (int i = 0; i < n; i++)
	{
		float newx =  BRICK_FLOOR_X + i*BRICK_WIDTH;
		GameObject* newbrick = new GameObject(newx, BRICK_FLOOR_Y, texBrick);
		brickFloor.push_back(newbrick);
	}

	for (int i = 0; i < 10; i++)
	{
		float newx = MARIO_START_X + i * MARIO_WIDTH;
		Mario* newmario = new Mario(newx, 200, MARIO_VX,texMario);
		alotofmario.push_back(newmario);
	}
}

void Update(DWORD dt)
{
	mario->Update(dt);
	brick->Update(dt);
	for (int i = 0; i < n; i++)
	{
		brickFloor[i]->Update(dt);
	}

	for (int i = 0; i < 10; i++)
	{
		alotofmario[i]->Update(dt);
	}
}

void Render()
{
	Game* game = Game::GetInstance();
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 backBuffer = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		d3ddv->ColorFill(backBuffer, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		mario->Render();
		brick->Render();

		for (int i = 0; i < n; i++)
		{
			brickFloor[i]->Render();
		}

		for (int i = 0; i < 10; i++)
		{
			alotofmario[i]->Render();
		}

		spriteHandler->End();
		d3ddv->EndScene();
	}

	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd = CreateWindow(
		WINDOW_CLASS_NAME,
		MAIN_WINDOW_TITLE,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		ScreenWidth,
		ScreenHeight,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	
	if (!hWnd)
	{
		DWORD ErrCode = GetLastError();
		DebugOut(L"[ERROR] CreateWindow failed! ErrCode: %d\nAt: %s %d \n", ErrCode, _W(__FILE__), __LINE__);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

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

		DWORD now = GetTickCount();
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			Update(dt);
			Render();
		}
		else
		{
			Sleep(tickPerFrame - dt);
		}
	}

	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	Game* game = Game::GetInstance();

	game->Init(hWnd);

	LoadResources();
	Run();
	
	return 0;
}