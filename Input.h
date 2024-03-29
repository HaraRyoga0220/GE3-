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
public://メンバ変数
	//初期化
	void Initialize(HINSTANCE hInstance,HWND hwnd);
	//更新
	void Update();

private:
	 Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
};

