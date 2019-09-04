#include "pch.h"

using namespace std;
using namespace this_thread;

typedef unsigned int ui;
#define sleep(x) sleep_for(chrono::milliseconds(x));
#define ZERO(x) wmemset(x, 0, wcslen(x));
//---------------------------------------------


int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 35;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("mode 650");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	ui max, seed, seven, x, i = 0;
	float speed;
	wchar_t *out = new wchar_t[5]();
	const char* sharps = "CDFGA";
	const char* flats = "EDBAG";

	wprintf(L"%s", L"Amount of Chords: "); wscanf_s(L"%u", &max);
	wprintf(L"%s", L"Speed in Seconds: "); wscanf_s(L"%f", &speed);
	wprintf(L"%s", L"Seed: "); wscanf_s(L"%u", &seed);
	wprintf(L"%s", L"With 7th chords? "); wscanf_s(L"%u", &seven);
	srand(seed);
	
	wprintf(L"%s", L"Here we go!\n");
	for (int i = 3; i >= 1; i--) wprintf(L"%d\n", i), sleep(1);
	wprintf(L"------------------------------------------\n");

	while (max--) {
		x = rand();

		switch (x % 7)
		{
			case 0: out[i++] = 'C'; break;
			case 1: out[i++] = 'D'; break;
			case 2: out[i++] = 'E'; break;
			case 3: out[i++] = 'F'; break;
			case 4: out[i++] = 'G'; break;
			case 5: out[i++] = 'A'; break;
			case 6: out[i++] = 'B'; break;
		}
		
		x = rand();
		if (x % 3 == 1 && strchr(sharps, *out) != nullptr)	out[i++] = '#';
		else if (x % 3 == 2 && strchr(flats, *out) != nullptr)	out[i++] = 'b';
		
		if (x %= (seven ? 3 : 2), x == 0) out[i++] = 'M';
		else if (x == 1) out[i++] = 'm';

		out[i++] = x == 2 ? '7' : rand() % 2 == 0 && seven ? '7' : 0;
		wprintf(L"%ls\n\n", out);
		i = 0;  ZERO(out); sleep((ui)(speed*1000));
	}

	//wprintf(L"♭");
	delete [] out;
}
