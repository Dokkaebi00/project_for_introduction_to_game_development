#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"Game.h"
#include"Sprites.h"
#include"GameObject.h"
#include"Mario.h"
#include"Animations.h"
#include"Animation.h"
#include"AnimationFrame.h"

#define MAX_FRAME_RATE 60
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define WINDOW_CLASS_NAME L"Sprite_practice"
#define WINDOW_MAIN_TITLE L"main_window_title"

#define MARIO_GO_LEFT_1 1
#define MARIO_GO_LEFT_2 2
#define MARIO_GO_LEFT_3 3

#define MARIO_GO_RIGHT_1 4
#define MARIO_GO_RIGHT_2 5
#define MARIO_GO_RIGHT_3 6

#define MARIO_TEXTURE 10

Game* game;
Mario* mario;

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
		WINDOW_MAIN_TITLE,
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
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	OutputDebugString(L"[ERROR] CreateWindow success!");

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

void LoadResources()
{
	Textures* textures = Textures::GetInstance();

	textures->Add(MARIO_TEXTURE, L"textures\\mario.png", D3DCOLOR_XRGB(176, 224, 248));

	Sprites* sprites = Sprites::GetInstance();

	LPDIRECT3DTEXTURE9 texMario = textures->Get(MARIO_TEXTURE);

	sprites->Add(MARIO_GO_LEFT_1, 246, 154, 259, 181, texMario);
	sprites->Add(MARIO_GO_LEFT_2, 275, 154, 290, 181, texMario);
	sprites->Add(MARIO_GO_LEFT_3, 304, 154, 321, 181, texMario);

	sprites->Add(MARIO_GO_RIGHT_1, 186, 154, 199, 181, texMario);
	sprites->Add(MARIO_GO_RIGHT_2, 155, 154, 170, 181, texMario);
	sprites->Add(MARIO_GO_RIGHT_3, 125, 154, 140, 181, texMario);
	
	Animations* animations = Animations::GetInstance();

	LPANIMATION ani;

	ani = new Animation(100);
	ani->Add(MARIO_GO_LEFT_1);
	ani->Add(MARIO_GO_LEFT_2);
	ani->Add(MARIO_GO_LEFT_3);

	animations->Add(MARIO_GO_LEFT, ani);
	ani = new Animation(100);
	ani->Add(MARIO_GO_RIGHT_1);
	ani->Add(MARIO_GO_RIGHT_2);
	ani->Add(MARIO_GO_RIGHT_3);

	animations->Add(MARIO_GO_RIGHT, ani);
	
	mario = new Mario();
	mario->SetPosition(10.0f, 100.0f);

}

void Update(DWORD dt)
{
	mario->Update(dt);

}

void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 backBuffer = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		d3ddv->ColorFill(backBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		mario->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}

	d3ddv->Present(NULL, NULL, NULL, NULL);
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

	game = Game::GetInstance();
	game->Init(hWnd);

	LoadResources();

	Run();

	return 0;
}