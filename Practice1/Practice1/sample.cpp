#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);

TCHAR szClassName[] = TEXT("sample01");  // ウィンドウクラス

// Windowsプログラムのエントリーポイント
int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow) {
	MSG msg;
	BOOL bRet;

	if (!InitApp(hCurInst))
		return FALSE;
	if (!InitInstance(hCurInst, nCmdShow))
		return FALSE;

	// メッセージを取得
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) 
	{
		if (bRet == -1){
			break;
		} else {
			TranslateMessage(&msg);		// メッセージを変換
			DispatchMessage(&msg);
		}

	}

	return (int)msg.wParam;

}

// ウィンドウクラスの登録
ATOM InitApp(HINSTANCE hInst)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);			// 構造体のサイズ
	wc.style = CS_HREDRAW | CS_VREDRAW;		// クラスのスタイル
	wc.lpfnWndProc = WndProc;				// プロシージャ名
	wc.cbClsExtra = 0;						// 補助メモリ
	wc.cbWndExtra = 0;						// 補助メモリ
	wc.hInstance = hInst;					// インスタンス

	// アイコン
	wc.hIcon = (HICON)LoadImage(NULL, MAKEINTRESOURCE(IDI_APPLICATION), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);

	// カーソル
	wc.hCursor = (HCURSOR)LoadImage(NULL, MAKEINTRESOURCE(IDC_ARROW), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);

	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景ブラシ
	wc.lpszMenuName = NULL;					// メニュー名
	wc.lpszClassName = szClassName;			// クラス名
	
	// 小さいアイコン
	wc.hIconSm = (HICON)LoadImage(NULL, MAKEINTRESOURCE(IDI_APPLICATION), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);

	return (RegisterClassEx(&wc));

}

// ウィンドウの生成
BOOL InitInstance(HINSTANCE hInst, int nCmdShow)
{
	HWND hWnd;

	hWnd = CreateWindow(szClassName,				// クラス名
						TEXT("猫でもわかるWindowsプログラミング"),		// ウィンドウ名
						WS_OVERLAPPEDWINDOW,		// ウィンドウスタイル
						CW_USEDEFAULT,		// ｘ	
						CW_USEDEFAULT,		// ｙ
						CW_USEDEFAULT,		// ウィンドウ幅
						CW_USEDEFAULT,		// ウィンドウ高さ
						NULL,				// 親ウィンドウのハンドル
						NULL,				// メニューハンドル（クラスメニューを使うのでNULL）
						hInst,				// インスタンスハンドル
						NULL				// ウィンドウ作成データ
						);

	if (!hWnd)
		return FALSE;

	ShowWindow(hWnd, nCmdShow);		// ウィンドウの表示状態を認定
	UpdateWindow(hWnd);

	return TRUE;

}

// ウィンドウプロシージャ（コールバック関数）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{

	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, msg, wp, lp));

		return 0;
	}

}