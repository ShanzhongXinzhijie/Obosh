#include "stdafx.h"
//#include <charconv>
//#include "DemolisherWeapon/GraphicsAPI/DirectX12/DX12Test.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);

	//�G���W���̏������ݒ�
	InitEngineParameter initparam;
	
	//TODO �t���X�N�Ή�
	//initparam.windowStyle = WS_POPUP | WS_BORDER ;		//�E�B���h�E�X�^�C��

	//�𑜓x
	//initparam.screenWidth = initparam.frameBufferWidth = initparam.frameBufferWidth3D = 1920;
	//initparam.screenHeight = initparam.frameBufferHeight = initparam.frameBufferHeight3D = 1080;

	initparam.useFpsLimiter = false;
	//initparam.limitFps = 15;
	initparam.useVSync = false;
	initparam.isWindowMode = true;

	//�V�F�[�_�[
	//���f�o�b�O�p
	initparam.isShaderPathReplaceForEngineFilePath = true;
	
	//�G���W��������
	GetEngine().InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Obosh", initparam);	
	
	//����\��
	//SetPhysicsDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);

	//�f�o�b�O�\���E���́A�펞�L����
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

			m_model.Init(L"tettou.cmo");
			//m_model.SetPos({ 0,1000,-800 });
			m_modeltkm.Init(L"testNonSkin.tkm");
			m_modeltkm.SetIsDrawBoundingBox(true);

			for (auto& m : m_insM) {
				m.Init(100, L"testNonSkin.tkm");
				m.SetPos({ 100 - 200 * CMath::RandomZeroToOne(), 100 - 200 * CMath::RandomZeroToOne(), 100 - 200 * CMath::RandomZeroToOne() });
			}

			cpos = { 0,0,-200 };
			ctar = m_cam.GetTarget();
			m_cam.SetFar(100000);
			m_cam.SetPos(cpos);
			SetMainCamera(&m_cam);

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

			if (GetKeyInput('W')) {
				cpos.z += 1.0f;
				ctar.z += 1.0f;
			}
			if (GetKeyInput('S')) {
				cpos.z -= 1.0f;
				ctar.z -= 1.0f;
			}
			if (GetKeyInput('A')) {
				cpos.y += 1.0f;
				ctar.y += 1.0f;
			}
			if (GetKeyInput('D')) {
				cpos.y -= 1.0f;
				ctar.y -= 1.0f;
			}
			m_cam.SetPos(cpos);
			m_cam.SetTarget(ctar);
		}
		/*
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
		*/

	private:
		int num = 0, num2 = 0;
		CFont font;
		//TestGO obj;

		//GetSpriteBatchPMA��GetSpriteBatch�̎g�����t?
		//�t����Ȃ����ۂ�
		CSprite m_sprite, m_spriteDDS;

		GameObj::CSkinModelRender m_model, m_modeltkm;
		GameObj::CInstancingModelRender m_insM[100];
		GameObj::PerspectiveCamera m_cam;
		CVector3 cpos, ctar;
	};

#ifdef DW_DX11
	TestGOFactry test;
#endif

	//�Q�[�����[�v�B
	GetEngine().RunGameLoop();

	//DX12Test::DeleteIns();
}