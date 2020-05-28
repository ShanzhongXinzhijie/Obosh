#include "stdafx.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);

	//�G���W���̏������ݒ�
	InitEngineParameter initparam;
	
	//TODO �t���X�N�Ή�
	initparam.windowStyle = WS_POPUP | WS_BORDER ;		//�E�B���h�E�X�^�C��
	initparam.screenWidth = 640;			//�E�B���h�E�̕�
	initparam.screenHeight = 640;			//�E�B���h�E�̍���
	initparam.frameBufferWidth = 640;		//�t���[���o�b�t�@�̕��B���ꂪ�����𑜓x�B
	initparam.frameBufferHeight = 640;		//�t���[���o�b�t�@�̍����B���ꂪ�����𑜓x�B
	
	initparam.frameBufferWidth3D = 640;// 1080;	//3D�`��̉𑜓x(��)
	initparam.frameBufferHeight3D = 640;//1080;	//3D�`��̉𑜓x(����)
	//initparam.isAntiAliasing = false;		//�A���`�G�C���A�X����

	initparam.SDUnityChanScale = 3.5f;		//�����X�P�[���ݒ�
	//0.15f

	initparam.isEnableDOF = true;
	//initparam.standardFps = 25;
	//initparam.limitFps = 25;
	//initparam.shadowMapSetting = enON;

	//�V�F�[�_�[
	//���f�o�b�O�p
	initparam.isShaderPathReplaceForEngineFilePath = true;
	//initparam.SSAOBufferScale = 1.0f;
	
	//�G���W��������
	GetEngine().InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "���ɍ����̃f�X�z�g�P", initparam);	

	//DOF�ݒ�
	GetGraphicsEngine().GetDOFRender().SetFocus(0.0f);
	GetGraphicsEngine().GetDOFRender().SetFocusArea(0.0f);
	GetGraphicsEngine().GetDOFRender().SetNear(0.0f);
	GetGraphicsEngine().GetDOFRender().SetFar(30000.0f);

	//�c�Ȏ����ݒ�
	SetLensDistortionScale(5.0f);

	//�������[���h�ݒ�
	GetPhysicsWorld().SetGravity({ 0.0f,-800.0f,0.0f });//�d��
	//GetPhysicsWorld().GetSoftBodyWorldInfo()->air_density = 1.2f*10.0f;
	
	//����\��
	//SetPhysicsDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);

	//�f�o�b�O�\���E���́A�펞�L����
	//SetIsDebugDraw(true);
	//SetIsDebugInput(true);

	//�Q�[�����[�v�B
	GetEngine().RunGameLoop();

}