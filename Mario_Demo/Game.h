#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <unordered_map>



class Game
{
	static Game* __instance;

	static float deltaTime;

	HWND hWnd;

	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddv = NULL;

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;

public:

	void InitDirectEnvironment(HWND hWnd);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);
	
	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR filePath);

	void GameInit(HWND hWnd);
	
	void Update();
	void Render();

	int GameLoop(HWND hWnd);

	static Game* GetInstance();
	static float GetDeltaTime();
	static float FixedDeltaTime();

	~Game();
};

