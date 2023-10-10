#pragma once
#include<windows.h>
#include <dinput.h>
#define DIRECTINPUT_VERSION    0x0800
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#include <wrl.h>
//using namespace Microsoft::WRL;


class Input
{
public://ƒƒ“ƒo•Ï”
	//‰Šú‰»
	void Initialize(HINSTANCE hInstance,HWND hwnd);
	//XV
	void Update();

private:
	 Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
};

