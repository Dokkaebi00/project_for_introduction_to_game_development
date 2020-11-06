#pragma once

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

#include"instance.h"
#include"instanceManager.h"
#include "Utils.h"
#include "Textures.h"
#include "Sprites.h"
#include "Animations.h"
#include "tinyxml.h"
#include "KeyboardProcessing.h"
#include "GameKeyEventHandler.h"
#include "KeyEventHandler.h"

#define MAX_FRAME_RATE 120
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

//Game contains d3d environment and GameComponent(Resource for game (texture, map, logic (Update function)))

class Game
{
	//singlton for Game
	static Game* __instance;

	//dt (time between 2 frame, define a dt variable in Game class so that we can use this dt 
	//for all object in game like GameObject, Scene, more easy to handle than each update have an invidual dt
	static float dt;
	static float timeScale;

	//hWnd (handle window, where game shows on it)
	HWND hWnd;

	//d3d environment
	LPDIRECT3D9 d3d = NULL;
	//d3d device - Graphic Card
	LPDIRECT3DDEVICE9 d3ddv = NULL;
	//backBuffer-where we draw our game
	LPDIRECT3DSURFACE9 backBuffer = NULL;
	//a library use to draw sprite on backBuffer
	LPD3DXSPRITE spriteHandler = NULL;

	//we can understand like this
	//d3d a picture frame
	//d3ddv is tool box
	//backBuffer is a drawing paper
	//spriteHandler is a pencil

	//in game have alot of resource like texture, map, animation, sprite,...
	//each resource have alot of sub resource and we need to use in a map
	//for example, at class Textures we need a map to store all the texture
	//for easy to process and handle, we use and map which stores map to handle the resource
	unordered_map<string, unordered_map<string, string>> resources;

public:
	void InitDirect3DX(HWND hWnd);

	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath);

	void Draw(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void Draw(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);

	void FlipDrawX(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void FlipDrawX(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);

	void FlipDrawY(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void FlipDrawY(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);

	void GameInit();

	void GameLoadResources();

	void Update();
	void Render();
	void GameLoop();
	
	void GameEnd();

	LPDIRECT3DDEVICE9 GetDirect3DDevice();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSpriteHandler();

	static float GetTimeScale();
	static void SetTimeScale(float time);

	float GetDeltatTime();

	void ReadRootXMLFile();
	string GetPath(string name, string id);

	static Game* GetInstance();
	~Game();
};

