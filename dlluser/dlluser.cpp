#include <windows.h>
#include <stdio.h>

typedef void(__cdecl *DLLHELLO)(void);

int main(void)
{
	HINSTANCE hLib;
	DLLHELLO Hello;
	BOOL libSuccess = FALSE;

	// ��������� DLL-����������
	hLib = LoadLibrary(L"DLL.dll");

	// ���� ���������� �������, ����� ����� ������� � �������� ��
	if (hLib != NULL)
	{
		Hello = (DLLHELLO)GetProcAddress(hLib, "Hello");
		printf("Address of Hello = %08x\n", (unsigned)Hello);
		printf("Address of main = %08x\n", (unsigned)main);

		// ���� ����� ����������, ������� �������
		if (NULL != Hello)
		{
			libSuccess = TRUE;
			Hello();
		}
		// ���������� DLL-����������
		FreeLibrary(hLib);
	}
	if (!libSuccess) printf("Error loading library DLL.dll\n");
	return 0;
}
