#include "DxLib.h"
#include "Vector2.h"
#include "Vector3.h"
#include "cmath"

//�֐�
//���̕`��
int DrawSphere3D(const Vector3& CenterPos,const float r,const int DivNum,
	const unsigned int DifColor,const unsigned int SpcColor,const int FillFlag);

//�����̕`��
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned Color);

int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,	//�J�����̈ʒu
	const Vector3& cameraTarget,	//�J�����̒����_
	const Vector3& cameraUp	//�J�����̏�̌���
);

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "LE2B_02_�A�X�}_�V���E�^";

// �E�B���h�E����
const int WIN_WIDTH = 1024;

// �E�B���h�E�c��
const int WIN_HEIGHT = 576;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0, 0, 64);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);

	//		�N���b�v��
	SetCameraNearFar(1.0f, 1000.0f);
	SetCameraScreenCenter(WIN_WIDTH / 2.0f, WIN_HEIGHT / 2.0f);

	Vector3 cameraPosition(0.0f, 0.0f, -30.0f);
	Vector3 cameraTarget(0.0f, 0.0f, 0.0f);
	Vector3 cameraUp(0.0f, 1.0f, 0.0f);
	SetCameraPositionAndTargetAndUpVec(cameraPosition, cameraTarget, cameraUp);

	Vector3 A(3, -1, 2);
	Vector3 B(1,  5,-4);
	Vector3 C(-1, 7, 6);

	Vector3 AB(B.x - A.x, B.y - A.y, B.z - A.z);
	Vector3 BC(C.x - B.x, C.y - B.y, C.z - B.z);

	Vector3 n(AB.y * BC.z - AB.z * BC.y, AB.z * BC.x - AB.x * BC.z, AB.x * BC.y - AB.y * BC.x);
	n.normalize();
	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	Vector2 position(10, 100);
	Vector2 velocity(+1.0f, +0.5f);
	Vector3 position(0, 0, 0);
	Vector3 velocity(0.0f, 0.0f, 0.5f);
	SetUseZBufferFlag(true);
	SetWriteZBufferFlag(true);

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = {0};

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = {0};

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		Vector3 v(cameraTarget.x - cameraPosition.x, cameraTarget.y - cameraPosition.y, cameraTarget.z - cameraPosition.z);
		v.normalize();

		unsigned color = GetColor(255, 255, 255);

		if(v < 0)

		// �`�揈��
		ClearDrawScreen();
		DrawSphere3D(position,80.0f,32,GetColor(255,0,0),GetColor(255,255,255),true);

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}

//�I�[�o�[���[�h�֐�
//�\���ʒu�Ƀx�N�g��(Vector2)���w��ł���悤�ɂ���
int DrawCircle(Vector2 vec, int r, unsigned int color)
{
	return DrawCircle(static_cast<int>(vec.x), static_cast<int>(vec.y), r, color);
}
