#include "DxLib.h"
#include "Vector2.h"
#include "Vector3.h"
#include "cmath"

//関数
//球の描画
int DrawSphere3D(const Vector3& CenterPos,const float r,const int DivNum,
	const unsigned int DifColor,const unsigned int SpcColor,const int FillFlag);

//線分の描画
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned Color);

int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,	//カメラの位置
	const Vector3& cameraTarget,	//カメラの注視点
	const Vector3& cameraUp	//カメラの上の向き
);

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2B_02_アスマ_ショウタ";

// ウィンドウ横幅
const int WIN_WIDTH = 1024;

// ウィンドウ縦幅
const int WIN_HEIGHT = 576;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0, 0, 64);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);

	//		クリップ面
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
	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
	Vector2 position(10, 100);
	Vector2 velocity(+1.0f, +0.5f);
	Vector3 position(0, 0, 0);
	Vector3 velocity(0.0f, 0.0f, 0.5f);
	SetUseZBufferFlag(true);
	SetWriteZBufferFlag(true);

	// 最新のキーボード情報用
	char keys[256] = {0};

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = {0};

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		Vector3 v(cameraTarget.x - cameraPosition.x, cameraTarget.y - cameraPosition.y, cameraTarget.z - cameraPosition.z);
		v.normalize();

		unsigned color = GetColor(255, 255, 255);

		if(v < 0)

		// 描画処理
		ClearDrawScreen();
		DrawSphere3D(position,80.0f,32,GetColor(255,0,0),GetColor(255,255,255),true);

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}

//オーバーロード関数
//表示位置にベクトル(Vector2)を指定できるようにする
int DrawCircle(Vector2 vec, int r, unsigned int color)
{
	return DrawCircle(static_cast<int>(vec.x), static_cast<int>(vec.y), r, color);
}
