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

	OutputDebugString(L"[INFO] Init Direct3DX Done \n");
}

LPDIRECT3DTEXTURE9 Game::LoadTexture(LPCWSTR texturePath)
{
	D3DXIMAGE_INFO info;
	LPDIRECT3DTEXTURE9 texture;

	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &info);

	if (result != D3D_OK)
	{
		return NULL;
	}

	result = D3DXCreateTextureFromFileEx(
		d3ddv, 
		texturePath, 
		info.Width, 
		info.Height,
		1, 
		D3DUSAGE_DYNAMIC, 
		D3DFMT_UNKNOWN, 
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT, 
		D3DX_DEFAULT, 
		D3DCOLOR_XRGB(255, 0, 255),
		&info, 
		NULL, 
		&texture
	);

	if (result != D3D_OK)
	{
		return NULL;
	}
	return texture;
}

void Game::Draw(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha)
{
	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;

	D3DXVECTOR3 p(x, y, 0);
	D3DXVECTOR3 anchorPoint(anchorPointX, anchorPointY, 0);

	spriteHandler->Draw(texture, &r, &anchorPoint, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

void Game::Draw(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha)
{
	D3DXVECTOR3 p(x, y, 0);
	D3DXVECTOR3 anchorPoint(anchorPointX, anchorPointY, 0);

	spriteHandler->Draw(texture, &r, &anchorPoint, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

void Game::FlipDrawX(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha)
{
	D3DXVECTOR3 anchorPoint(anchorPointX, anchorPointY, 0);

	D3DXVECTOR2 flipVector(-1, 1);

	D3DXVECTOR3 p(x, y, 0);

	D3DXVECTOR2 position = D3DXVECTOR2(x, y);

	D3DXMATRIX beforeTransform;

	D3DXMATRIX transFormMatrix;

	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;

	spriteHandler->GetTransform(&beforeTransform);

	D3DXMatrixTransformation2D(
		&transFormMatrix,
		&position,
		0.0f,
		&flipVector,
		NULL,
		0.0f,
		NULL
	);

	spriteHandler->SetTransform(&transFormMatrix);

	spriteHandler->Draw(texture, &r, &anchorPoint, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));

	spriteHandler->SetTransform(&beforeTransform);
}

void Game::FlipDrawX(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha)
{
	D3DXVECTOR3 anchorPoint(anchorPointX, anchorPointY, 0);

	D3DXVECTOR2 flipVector(-1, 1);

	D3DXVECTOR3 p(x, y, 0);

	D3DXVECTOR2 position = D3DXVECTOR2(x, y);

	D3DXMATRIX beforeTransform;

	D3DXMATRIX transFormMatrix;

	spriteHandler->GetTransform(&beforeTransform);

	D3DXMatrixTransformation2D(
		&transFormMatrix,
		&position,
		0.0f,
		&flipVector,
		NULL,
		0.0f,
		NULL
	);

	spriteHandler->SetTransform(&transFormMatrix);

	spriteHandler->Draw(texture, &r, &anchorPoint, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));

	spriteHandler->SetTransform(&beforeTransform);
}

void Game::FlipDrawY(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha)
{
	D3DXVECTOR3 anchorPoint(anchorPointX, anchorPointY, 0);

	D3DXVECTOR2 flipVector(1, -1);

	D3DXVECTOR3 p(x, y, 0);

	D3DXVECTOR2 position = D3DXVECTOR2(x, y);

	D3DXMATRIX beforeTransform;

	D3DXMATRIX transFormMatrix;

	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;

	spriteHandler->GetTransform(&beforeTransform);

	D3DXMatrixTransformation2D(
		&transFormMatrix,
		&position,
		0.0f,
		&flipVector,
		NULL,
		0.0f,
		NULL
	);

	spriteHandler->SetTransform(&transFormMatrix);

	spriteHandler->Draw(texture, &r, &anchorPoint, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));

	spriteHandler->SetTransform(&beforeTransform);
}

void Game::FlipDrawY(float x, float y, float anchorPointX, float anchorPointY, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha)
{
	D3DXVECTOR3 anchorPoint(anchorPointX, anchorPointY, 0);

	D3DXVECTOR2 flipVector(1, -1);

	D3DXVECTOR3 p(x, y, 0);

	D3DXVECTOR2 position = D3DXVECTOR2(x, y);

	D3DXMATRIX beforeTransform;

	D3DXMATRIX transFormMatrix;

	spriteHandler->GetTransform(&beforeTransform);

	D3DXMatrixTransformation2D(
		&transFormMatrix,
		&position,
		0.0f,
		&flipVector,
		NULL,
		0.0f,
		NULL
	);

	spriteHandler->SetTransform(&transFormMatrix);

	spriteHandler->Draw(texture, &r, &anchorPoint, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));

	spriteHandler->SetTransform(&beforeTransform);
}

void Game::GameInit()
{
	OutputDebugString(L"[INFO] Load Resource");

	Textures::GetInstance()->LoadTextures();
	Sprites::GetInstance()->LoadSprites();
	Animations::GetInstance()->LoadAnimations();

	GameKeyEventHandler* keyEventHandler = new GameKeyEventHandler();
	KeyboardProcessing* keyboardProcessing = KeyboardProcessing::GetInstance();
	keyboardProcessing->SetHWND(hWnd);
	keyboardProcessing->InitKeyboard(keyEventHandler);
}

void Game::GameLoadResources()
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
		//LPDIRECT3DTEXTURE9 ex = Textures::GetInstance()->GetTexture("tex-fire-ball");
		//LPSPRITE ex = Sprites::GetInstance()->Get("spr-small-mario-walk-1");
		//ex->Draw(50.0f, 50.0f, D3DXVECTOR2(1, 1), 1);
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
	Textures::GetInstance()->~Textures();
	Sprites::GetInstance()->~Sprites();
	Animations::GetInstance()->~Animations();
	KeyboardProcessing::GetInstance()->~KeyboardProcessing();
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
	return timeScale;
}

void Game::SetTimeScale(float time)
{
	timeScale = time;
}

float Game::GetDeltatTime()
{
	return dt;
}

void Game::ReadRootXMLFile()
{
	auto filePath = "";

	TiXmlDocument file(filePath);

	if (file.LoadFile() == false)
	{
		OutputDebugString(L"[Error] can not read root file");
	}

	TiXmlElement* root = file.RootElement();

	for (TiXmlElement* element = root->FirstChildElement();
		element != nullptr;
		element = element->NextSiblingElement()
		)
	{
		string name = element->Attribute("name");
		
		unordered_map<string, string> resource;

		DebugOut(L"[INFO] Add resource name ", name);

		for (auto item = element->FirstChildElement();
			item != nullptr;
			item = item->NextSiblingElement()
			)
		{
			string id = item->Attribute("id");
			string source = item->Attribute("source");
			//resource[id] = source;
			resource.insert(make_pair(id, source));

			DebugOut(L"add source", id, " ", source);
		}

		//resources[name] = resource;
		resources.insert(make_pair(name, resource));
	}
}

string Game::GetPath(string name, string id)
{
	if (resources.find(name) != resources.end())
	{
		auto resource = resources.at(name);

		if (resource.find(id) != resource.end())
		{
			return resource.at(id);
		}
	}
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
	Textures::GetInstance()->~Textures();

	if (spriteHandler != NULL) spriteHandler->Release();
	if (backBuffer != NULL) backBuffer->Release();
	if (d3ddv != NULL) d3ddv->Release();
	if (d3d != NULL) d3d->Release();
}
