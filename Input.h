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
public://�����o�ϐ�
	//������
	void Initialize(HINSTANCE hInstance,HWND hwnd);
	//�X�V
	void Update();

	//�C�ӂ̃{�^�����������Ă���
	bool PushKey(BYTE keyNumber);
	//�C�ӂ̃{�^���������ꂽ�u��
	bool TriggerKey(BYTE keyNumber);
	//�C�ӂ̃{�^���������ꂽ�u��

private:
	 Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
	 BYTE key[256] = {};
	 BYTE keyPre[256] = {};
};

