#include <windows.h>
int main()
{
	HWND hDesktopWnd;
	RECT rc;
	BOOL bSuccess;
	hDesktopWnd = GetDesktopWindow();					// ȡ�����棨��Ļ�����ھ��
	bSuccess = GetWindowRect(hDesktopWnd, &rc);			// ȡ�ô��ڵľ�����Ϣ��λ�ã�����
	HDC hDc = GetDC(hDesktopWnd);						// ȡ�ô��ڵ��豸�����ģ����ڵĻ��ƣ���Ҫ���豸�������н��� 
	while (true)										// ѭ����������������������ô�򵥴ֱ�������
	{
		SetPixel(hDc, 600, 200, RGB(255, 0, 0));		// ������ 600,200��λ�û�һ��һ���صĺ��
		for (int iy = rc.top; iy < rc.bottom; iy++)		// �ں�����Ϊ200�ĵط�����һ����ɫ������
			SetPixel(hDc, 200, iy, RGB(255, 0, 0));
	}
	return 0;
}
