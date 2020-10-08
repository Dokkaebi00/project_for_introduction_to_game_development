#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include<signal.h>
#include<string.h>
#include<stdio.h>
#include<stdarg.h>
#include<time.h>
#include<stdlib.h>

#define _W(x)  __W(x)
#define __W(x)  L##x

#define VA_PRINTS(s) {				\
		va_list argp;				\
		va_start(argp, fmt);		\
		vswprintf_s(s, fmt, argp);	\
		va_end(argp);				\
}


class Game
{
	static Game* __instance;

	HWND hWnd;

	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddv = NULL;

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;

	int backBufferWidth = 0;
	int backBufferHeight = 0;

public:
	void Init(HWND hWnd);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom);
	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath);

	LPDIRECT3DDEVICE9 GetDirect3DDevice();
	LPDIRECT3D9 GetDirect3D();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSpriteHandler();

	int GetBackBufferWidth();
	int GetBackBufferHeight();

	void DebugOut(const wchar_t* fmt, ...);

	static Game* GetInstance();
	~Game();
};

