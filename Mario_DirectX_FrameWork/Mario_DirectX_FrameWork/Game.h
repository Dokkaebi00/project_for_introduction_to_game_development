#pragma once



#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

#include "Time.h"
#include "MonoBehaviour.h"
#include "Utils.h"
#include "Textures.h"
#include "Sprites.h"
#include "Animations.h"
#include "tinyxml.h"
#include "KeyboardProcessing.h"
#include "PlayerKeyEventHandler.h"
#include "KeyEventHandler.h"
#include "Object.h"
//#include "Camera.h"

#define MAX_FRAME_RATE 120
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

class Object;
class CMario;

using namespace std;

class Game : public MonoBehaviour
{
	//singlton for Game
	static Game* __instance;

	//dt (time between 2 frame, define a dt variable in Game class so that we can use this dt 
	//for all object in game like GameObject, Scene, more easy to handle than each update have an invidual dt
	//static float dt;

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

	//GameObject* go; //this is for debug

	//we can understand like this
	//d3d a picture frame
	//d3ddv is tool box
	//backBuffer is a drawing paper
	//spriteHandler is a pencil

	//this is for debug
	//Camera* camera;

	CMario* mario;


public:
	//init direct3d environment
	void InitDirect3DX(HWND hWnd);

	//load texture from the texture-path
	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath);

	//draw a sprite from the texture
	void Draw(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void Draw(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);

	//draw a sprite and flip it with x coordinate (use it with animation on the left)
	void FlipDrawX(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void FlipDrawX(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);

	//draw a sprite and flip it with y coordinate (use it with die animation of the enemy)
	void FlipDrawY(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void FlipDrawY(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);

	//load resources for game (texture, sprite, map, ...)
	virtual void Awake() override;

	//update logic for game
	virtual void Update() override;
	//render textures for game
	virtual void Render() override;
	//need this to run game
	void GameLoop();
	//clear database, disable keyboard of game
	void GameEnd();

	LPDIRECT3DDEVICE9 GetDirect3DDevice();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSpriteHandler();

	//get deltatime of game and use it for another object like GameObject,...
	float GetDeltaTime();

	float GetFixedDeltaTime();

	void SetTimeScale(float ts);
	float GetTimeScale();

	//Time GetTime();

	//singleton
	static Game* GetInstance();
	~Game();
};

