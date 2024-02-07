#pragma once
#include<Windows.h>
#include <string>
#include <wrl.h>
#include<dxcapi.h>
#include"DirectXCommon.h"
#include <d3d12.h>

class SpriteCommon
{
	private:
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	void Initialize(DirectXCommon*dxCommon);

	ID3D12RootSignature* GetRootSignature() { return rootSignature.Get(); }
	ID3D12PipelineState* GetPipelineState() { return pipelineState.Get(); }

private:
 static	IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t*profile,
		IDxcUtils*dxcUtils,
		IDxcCompiler3*dxcCompiler,
		IDxcIncludeHandler*includeHandler
		);

private:

	DirectXCommon* dxCommon_ = nullptr;

		ComPtr<ID3D12RootSignature>rootSignature;
		ComPtr<ID3D12PipelineState>pipelineState;
};

