#include "pch.h"

using namespace std;
using namespace this_thread;

typedef unsigned int ui;
#define sleep(x) sleep_for(chrono::seconds(x));
#define ZERO(x) wmemset(x, 0, wcslen(x));
//---------------------------------------------


int wmain()
{
	//_setmode(_fileno(stdout), _O_U16TEXT);
	setlocale(LC_ALL, "en_US.UTF-8");
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	cfi.dwFontSize.X = 25;
	cfi.dwFontSize.Y = 50;
	cfi.nFont = 12;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


	ui max, speed, seed, seven, x, i = 0;
	wchar_t *out = new wchar_t[5]();
	const char* sharps = "CDFGA";
	const char* flats = "EDBAG";

	wprintf(L"%s", L"Amount of Chords: "); wscanf_s(L"%ud", &max);
	wprintf(L"%s", L"Speed in Seconds: "); wscanf_s(L"%ud", &speed);
	wprintf(L"%s", L"Seed: "); wscanf_s(L"%ud", &seed);
	wprintf(L"%s", L"With 7th chords? "); wscanf_s(L"%ud", &seven);
	srand(seed);

	wprintf(L"%s", L"Here we go!\n");
	for (int i = 3; i >= 1; i--) wprintf(L"%d\n",i);
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
		//output.append("♭/u266d");
		
		if (x %= (seven ? 3 : 2), x == 0) out[i++] = 'M';
		else if (x == 1) out[i++] = 'm';

		out[i++] = x == 2 ? '7' : rand() % 2 == 0 && seven ? '7' : 0;
		wprintf(L"%ls\n\n", out);
		
		i = 0;  ZERO(out); sleep(speed);
	}

	wprintf(L"♭");
	delete [] out;
}
