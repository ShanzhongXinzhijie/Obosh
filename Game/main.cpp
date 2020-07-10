#include "stdafx.h"
#include <charconv>
#include "DemolisherWeapon/DirectX12/DX12Test.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);

	//エンジンの初期化設定
	InitEngineParameter initparam;
	
	//TODO フルスク対応
	initparam.windowStyle = WS_POPUP | WS_BORDER ;		//ウィンドウスタイル
	initparam.screenWidth = 640;			//ウィンドウの幅
	initparam.screenHeight = 640;			//ウィンドウの高さ
	initparam.frameBufferWidth = 640;		//フレームバッファの幅。これが内部解像度。
	initparam.frameBufferHeight = 640;		//フレームバッファの高さ。これが内部解像度。
	
	initparam.frameBufferWidth3D = 640;// 1080;	//3D描画の解像度(幅)
	initparam.frameBufferHeight3D = 640;//1080;	//3D描画の解像度(高さ)
	//initparam.isAntiAliasing = false;		//アンチエイリアス無効

	initparam.SDUnityChanScale = 3.5f;		//距離スケール設定
	//0.15f

	initparam.isEnableDOF = true;
	initparam.standardFps = 60;
	initparam.limitFps = -1;
	//initparam.shadowMapSetting = enON;

	//シェーダー
	//※デバッグ用
	initparam.isShaderPathReplaceForEngineFilePath = true;
	//initparam.SSAOBufferScale = 1.0f;
	
	//エンジン初期化
	GetEngine().InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Obosh", initparam);	

	GetEngine().SetUseFpsLimiter(false);

	//DOF設定
	GetGraphicsEngine().GetDOFRender().SetFocus(0.0f);
	GetGraphicsEngine().GetDOFRender().SetFocusArea(0.0f);
	GetGraphicsEngine().GetDOFRender().SetNear(0.0f);
	GetGraphicsEngine().GetDOFRender().SetFar(30000.0f);

	//歪曲収差設定
	SetLensDistortionScale(5.0f);

	//物理ワールド設定
	GetPhysicsWorld().SetGravity({ 0.0f,-800.0f,0.0f });//重力
	//GetPhysicsWorld().GetSoftBodyWorldInfo()->air_density = 1.2f*10.0f;
	
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
		}

	private:
		int num = 0, num2 = 0;
		CFont font;
		//TestGO obj;
	};

	TestGOFactry test;

	//ゲームループ。
	GetEngine().RunGameLoop();

	//DX12Test::DeleteIns();
}