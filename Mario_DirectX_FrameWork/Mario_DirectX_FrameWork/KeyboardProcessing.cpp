#include "KeyboardProcessing.h"


KeyboardProcessing* KeyboardProcessing::__instance = NULL;

KeyboardProcessing* KeyboardProcessing::GetInstance()
{
    if (__instance == NULL)
    {
        __instance = new KeyboardProcessing();
    }
    return __instance;
}

void KeyboardProcessing::InitKeyboard(LPKEYEVENTHANDLER handler)
{
    HRESULT hr = DirectInput8Create(
        (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
        DIRECTINPUT_VERSION,
        IID_IDirectInput8,
        (VOID**)&di,
        NULL
    );

    if (hr != DI_OK)
    {
        DebugOut(L"[ERROR] DirectInput8 Create failed!\n");
        return;
    }

    hr = di->CreateDevice(GUID_SysKeyboard, &didv, NULL);

    if (hr != DI_OK)
    {
        DebugOut(L"[ERROR] CreateDevice failed!\n");
        return;
    }

    hr = didv->SetDataFormat(&c_dfDIKeyboard);

    hr = didv->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

    DIPROPDWORD dipdw;

    dipdw.diph.dwSize = sizeof(DIPROPDWORD);
    dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    dipdw.diph.dwObj = 0;
    dipdw.diph.dwHow = DIPH_DEVICE;
    dipdw.dwData = KEYBOARD_BUFFER_SIZE; 

    hr = didv->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);

    hr = didv->Acquire();

    if (hr != DI_OK)
    {
        DebugOut(L"[ERROR] DINPUT8::Acquire failed!\n");
        return;
    }
    this->keyHandler = handler;

    DebugOut(L"[INFO] Keyboard has been initialized successfully\n");
}

void KeyboardProcessing::ProcessKeyboard()
{
    HRESULT hr;

    hr = didv->GetDeviceState(sizeof(keyStates), keyStates);

    if (FAILED(hr))
    {
        if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
        {
            HRESULT h = didv->Acquire();
            if (h == DI_OK)
            {
                DebugOut(L"[INFO] Keyboard re-acquired!\n");
            }
            else return;
        }
        else
        {
            DebugOut(L"[ERROR] DINPUT::GetDeviceState failed. Error: %d\n", hr);
            return;
        }
    }

    if (keyHandler == nullptr)
    {
        return;
    }

    DWORD dwElements = KEYBOARD_BUFFER_SIZE;
    hr = didv->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvents, &dwElements, 0);
    if (FAILED(hr))
    {
        DebugOut(L"[ERROR] DINPUT::GetDeviceData failed. Error: %d\n", hr);
        return;
    }

    for (DWORD i = 0; i < dwElements; i++)
    {
        int KeyCode = keyEvents[i].dwOfs;
        int KeyState = keyEvents[i].dwData;
        if ((KeyState & 0x80) > 0)
        {
            keyHandler->OnKeyDown(KeyCode);
        }
        else
        {
            keyHandler->OnKeyUp(KeyCode);
        }
        keyHandler->KeyState();

    }
}

void KeyboardProcessing::SetHWND(HWND hWnd)
{
    this->hWnd = hWnd;
}

int KeyboardProcessing::GetKeyDown(int keycode)
{
    return (keyStates[keycode] & 0x80) > 0;
}

int KeyboardProcessing::GetKeyUp(int keycode)
{
    return (keyStates[keycode] & 0x80) <= 0;
}

KeyboardProcessing::~KeyboardProcessing()
{
    if (di != NULL) di->Release();
    if (didv != NULL)
    {
        didv->Unacquire();
        didv->Release();
    }
}
