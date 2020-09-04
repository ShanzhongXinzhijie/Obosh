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

		//GetSpriteBatchPMA��GetSpriteBatch�̎g�����t?
		//�t����Ȃ����ۂ�
		CSprite m_sprite, m_spriteDDS;
	};

//#ifdef DW_DX11
	TestGOFactry test;
//#endif

	//�Q�[�����[�v�B
	GetEngine().RunGameLoop();

	//DX12Test::DeleteIns();
}