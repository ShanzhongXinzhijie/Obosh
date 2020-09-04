#include "stdafx.h"
//#include <charconv>
//#include "DemolisherWeapon/GraphicsAPI/DirectX12/DX12Test.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);

	//エンジンの初期化設定
	InitEngineParameter initparam;
	
	//TODO フルスク対応
	//initparam.windowStyle = WS_POPUP | WS_BORDER ;		//ウィンドウスタイル

	//解像度
	//initparam.screenWidth = initparam.frameBufferWidth = initparam.frameBufferWidth3D = 1920;
	//initparam.screenHeight = initparam.frameBufferHeight = initparam.frameBufferHeight3D = 1080;

	initparam.useFpsLimiter = false;
	initparam.useVSync = false;
	initparam.isWindowMode = true;

	//シェーダー
	//※デバッグ用
	initparam.isShaderPathReplaceForEngineFilePath = true;
	
	//エンジン初期化
	GetEngine().InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Obosh", initparam);	
	
	//判定表示
	//SetPhysicsDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);

	//デバッグ表示・入力、常時有効化
	SetIsDebugDraw(true);
	SetIsDebugInput(true);

	class TestGO :public IGameObject {
	};

	class TestGOII :public IGameObject {
	public:
		bool Start() override {
			return true;
		}
		void PreLoopUpdate() override {
		}
		void PreUpdate() override {
		}
		void Update() override {
		}
		void PostUpdate()override {
		}
		void PostLoopUpdate()override {
		}
		void PostLoopPostUpdate()override {
		}
		void Pre3DRender(int num)override {
		}
		void HUDRender(int HUDNum)override {
		}
		void PostRender()override {
		}
	};

	class TestGOFactry :public IGameObject {
	public:
		bool Start()override {
			m_sprite.Init(L"smoke.png"); 
			m_spriteDDS.Init(L"smoke.dds");
			return true;
		}
		void Update()override {
			if (GetKeyDown(VK_SPACE)) {
				for (int i = 0; i < 10000; i++) {
					new TestGOII;
					num2++;
				}
			}
			if (GetKeyDown(VK_RETURN)) {
				for (int i = 0; i < 10000; i++) {
					new TestGO;
					num++;
				}
			}
		}
		void PostRender()override {
			wchar_t stg[256];
			swprintf_s(stg, 256, L"TGO:%d \n"
								 L"TGO2:%d",
			num, num2);
			//std::to_chars(std::begin(stg),std::end(stg),num);
			font.Draw(stg, 0.5f);

			m_sprite.Draw({ 0.0f,0.0f }, 0.05f, 0.0f, 0.0f, { 1.0f,1.0f ,1.0f ,1.0f });
			m_spriteDDS.Draw({ 0.8f,0.0f }, 0.05f, 0.0f, 0.0f, { 1.0f,1.0f ,1.0f ,1.0f });
		}

	private:
		int num = 0, num2 = 0;
		CFont font;
		//TestGO obj;

		//GetSpriteBatchPMAとGetSpriteBatchの使い方逆?
		//逆じゃないっぽい
		CSprite m_sprite, m_spriteDDS;
	};

//#ifdef DW_DX11
	TestGOFactry test;
//#endif

	//ゲームループ。
	GetEngine().RunGameLoop();

	//DX12Test::DeleteIns();
}