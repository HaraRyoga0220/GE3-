﻿#include"Input.h"
#include"WinApp.h"
#include"DirectXCommon.h"
#include"Sprite.h"
#include"SpriteCommon.h"

#include"ImGuiManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    //ポインタ置き場
    Input* input_ = nullptr;
    WinApp* winApp_ = nullptr;
    DirectXCommon* dxCommon_ = nullptr;
#pragma region WindowsAPI初期化処理
    winApp_ = new WinApp();
    winApp_->Initialize();
#pragma endregion

#pragma region DirectX初期化処理
    dxCommon_ = new DirectXCommon();
    dxCommon_->Initialize(winApp_);
#pragma endregion
    //Input生成、初期化
    input_ = new Input();
    input_->Initialize(winApp_);

    ImGuiManager* imgui = ImGuiManager::Create();
    ImGuiManager::Initialize(winApp_->GetHwnd(), dxCommon_);

    //スプライトこもん
    SpriteCommon* common = new SpriteCommon();
    common->Initialize(dxCommon_);
    //スプライト
    Sprite* sprite = new Sprite();
    sprite->Initialize(dxCommon_,common);


    // ゲームループ
    while (true) {
        if (winApp_->Update() == true) {
            break;
      }
        ImGuiManager::NewFrame();
        imgui->ShowDemo();

        input_->Update();
    
        ImGuiManager::CreateCommand();
        dxCommon_->PreDraw();

        sprite->Draw();

        ImGuiManager::CommandsExcute(dxCommon_->GetCommandList());
        dxCommon_->PostDraw();

        // DirectX毎フレーム処理　ここまで

    }
    delete sprite;
    delete common;
    delete imgui;
    delete input_;
    delete dxCommon_;
    winApp_->Finalize();
    delete winApp_;
   

    return 0;
}
