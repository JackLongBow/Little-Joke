#include <windows.h>
int main()
{
	HWND hDesktopWnd;
	RECT rc;
	BOOL bSuccess;
	hDesktopWnd = GetDesktopWindow();					// 取得桌面（屏幕）窗口句柄
	bSuccess = GetWindowRect(hDesktopWnd, &rc);			// 取得窗口的矩形信息，位置，长宽
	HDC hDc = GetDC(hDesktopWnd);						// 取得窗口的设备上下文，窗口的绘制，都要在设备上下文中进行 
	while (true)										// 循环绘制永不结束，就先这么简单粗暴的来。
	{
		SetPixel(hDc, 600, 200, RGB(255, 0, 0));		// 在坐标 600,200的位置画一个一像素的红点
		for (int iy = rc.top; iy < rc.bottom; iy++)		// 在横坐标为200的地方，画一调红色的竖线
			SetPixel(hDc, 200, iy, RGB(255, 0, 0));
	}
	return 0;
}
