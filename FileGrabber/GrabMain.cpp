#include "stdafx.h"
#include "Device.h"
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

void DeviceArrivalMain(TCHAR DriveLetter) {
	Device dv(DriveLetter);
	Device::DiskInformation info = dv.GetDiskInformation();
	SYSTEMTIME st = { 0 };
	GetLocalTime(&st);
	wstring filename;
	wstringstream ss;
	
	ss << st.wYear << L"-" << st.wMonth << L"-" << st.wDay << L"_" << setw(2) << setfill(L'0') << st.wHour << L"." << st.wMinute << L"." << st.wSecond;
	getline(ss, filename);
	wstring ws = filename + L".ige";

	FILE* file = _wfopen(ws.c_str(), L"w");
	const wchar_t* label = info.Label.c_str();
	_wsetlocale(0, L"chs");
	fwprintf(file, L"Drive Letter: %c\nLabel: %s\nSN: %lu\nFileSystem: %s\nSpace: %llu", info.DriveLetter, label,
		info.VolumeSerialNumber, info.FileSystem.c_str(), info.TotalSpace);

	fclose(file);
}

void DeviceRemovalMain(TCHAR DriveLetter) {

}