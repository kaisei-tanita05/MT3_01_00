#include <Novice.h>
#include <Function.h>
#include <Matrix4x4.h>
#include <Vector3.h>



const char kWindowTitle[] = "LE2C_20_タニタ_カイセイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Function* function = new Function();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		Matrix4x4 orthographicMatrix = function->MakeOrthographicMatrix(-160.0f, 160.0f, 200.0f, 300.0f, 0.0f, 1000.0f);

		Matrix4x4 perspectiveFovMatrix = function->MakePerspectiveFovMatrix(0.63f, 1.33f, 0.1f, 1000.0f);

		Matrix4x4 MakeViewViewportMatrix = function->MakeViewportMatrix(100.0f, 200.0f, 600.0f, 300.0f, 0.0f, 1.0f);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(0, 0, "orthographicMatrix");
		function->MatrixScreenPrintf(0, 20, orthographicMatrix, "orthographicMatrix");

		Novice::ScreenPrintf(0, 100, "perspectiveFovMatrix");
		function->MatrixScreenPrintf(0, 120, perspectiveFovMatrix, "perspectiveFovMatrix");

		Novice::ScreenPrintf(0, 200, "MakeViewViewportMatrix");
		function->MatrixScreenPrintf(0, 220, MakeViewViewportMatrix, "MakeViewViewportMatrix");


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
