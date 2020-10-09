#include"Game.h"
#include"Mario.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAX_FRAME_RATE 60

#define WINDOW_CLASS_NAME L"test-sprite"

#define MAIN_WINDOW_TITLE L"sprites"

#define _W(x)  __W(x)
#define __W(x)  L##x

#define VA_PRINTS(s) {				\
		va_list argp;				\
		va_start(argp, fmt);		\
		vswprintf_s(s, fmt, argp);	\
		va_end(argp);				\
}

Game* game;

Mario* mario;
#define MARIO_TEX 00
#define MARIO_GO_RIGHT_1 1
#define MARIO_GO_RIGHT_2 2
#define MARIO_GO_RIGHT_3 3
#define MARIO_GO_LEFT_1 4
#define MARIO_GO_LEFT_2 5
#define MARIO_GO_LEFT_3 6

void DebugOut(const wchar_t* fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	wchar_t dbg_out[4096];
	vswprintf_s(dbg_out, fmt, argp);
	va_end(argp);
	OutputDebugString(dbg_out);
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
	Textures* textures = Textures::GetInstance();

	textures->Add(MARIO_TEX, L"textures\\mario.png", D3DCOLOR_XRGB(0, 0, 0));

	Sprites* sprites = Sprites::GetInstance();

	LPDIRECT3DTEXTURE9 texMario = textures->Get(MARIO_TEX);
	bool a = texMario == NULL;
	if (a)
	{
		DebugOut(L"[INFO] can not get mario_texture");
	}
	else
	{
		DebugOut(L"[INFO] can get mario_texture");
	}

	sprites->Add(MARIO_GO_RIGHT_1, 246, 154, 259, 181, texMario);
	sprites->Add(MARIO_GO_RIGHT_2, 275, 154, 290, 181, texMario);
	sprites->Add(MARIO_GO_RIGHT_3, 304, 154, 321, 181, texMario);

	sprites->Add(MARIO_GO_LEFT_1, 186, 154, 199, 181, texMario);
	sprites->Add(MARIO_GO_LEFT_2, 155, 154, 170, 181, texMario);
	sprites->Add(MARIO_GO_LEFT_3, 125, 154, 140, 181, texMario);

	Animations* animations = Animations::GetInstance();
	LPANIMATION ani;

	ani = new Animation(100);
	ani->Add(MARIO_GO_RIGHT_1);
	ani->Add(MARIO_GO_RIGHT_2);
	ani->Add(MARIO_GO_RIGHT_3);
	
	a = ani == NULL;

	animations->Add(MARIO_GO_RIGHT, ani);

	ani = new Animation(100);
	ani->Add(MARIO_GO_LEFT_1);
	ani->Add(MARIO_GO_LEFT_2);
	ani->Add(MARIO_GO_LEFT_3);

	a = ani == NULL;

	animations->Add(MARIO_GO_LEFT, ani);

	if (animations == NULL)
	{
		DebugOut(L"[INFO] can not get mario_texture");
	}

	mario = new Mario();
	mario->SetPosition(10.0f, 10.0f);

}


HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);

	wc.hInstance = hInstance;
	wc.style = CS_HREDRAW | CS_VREDRAW;

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
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
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
	game = Game::GetInstance();

	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	game->Init(hWnd);

	LoadResources();
	Run();

	return 0;
}