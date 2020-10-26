#pragma once

#include"Scene.h"

class PlayScene : public Scene
{
public:

	void KeyState(BYTE* state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	void LoadResources();
	void Update(DWORD dt);
	void Render();

	void InitPlayScene();
	void ResetPlayScene();

	void LoadMap();

	void CheckCollision();

	void CheckMarioCollisionWithItem();

	void CheckMarioCollisionWithEnemy();

	void CheckMarioCollisionWithHiddenPortal();

	void CheckMarioCollisionWithEndBrick();

	void CheckMarioCollisionWithBrick();

	void CheckAttackCollisionWithEnemy();


	PlayScene();
	~PlayScene();
};

