#pragma once

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

#include"instance.h"
#include"instanceManager.h"
#include "Utils.h"

#define MAX_FRAME_RATE 120
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

class Game
{
	static Game* __instance;

	static float dt;
	static float timeScale;

	HWND hWnd;

	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddv = NULL;

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;

public:
	void InitDirect3DX(HWND hWnd);

	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);

	void GameInit();
	
	void Update();
	void Render();
	void GameLoop();
	
	void GameEnd();

	LPDIRECT3DDEVICE9 GetDirect3DDevice();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSpriteHandler();

	static float GetTimeScale();
	static void SetTimeScale();

	float GetDeltatTime();

	static Game* GetInstance();
	~Game();
};

