#include "pch.h"

using namespace std;
using namespace this_thread;

typedef unsigned int ui;
#define sleep(x) sleep_for(chrono::seconds(x));
#define ZERO(x) wmemset(x, 0, wcslen(x));
//---------------------------------------------


int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

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

		switch (rand() % 7)
		{
			case 0: out[i++] = 'C'; break;
			case 1: out[i++] = 'D'; break;
			case 2: out[i++] = 'E'; break;
			case 3: out[i++] = 'F'; break;
			case 4: out[i++] = 'G'; break;
			case 5: out[i++] = 'A'; break;
			case 6: out[i++] = 'B'; break;
		}
		
		x = rand() % 3;
		if (x == 1 && strchr(sharps, *out) != nullptr)
			out[i++] = '#';
		else if (x == 2 && strchr(sharps, *out) != nullptr)
			out[i++] = 'b';
			//output.append("♭/u266d");
		
		x = rand() % (seven? 3 : 2);
		if (x == 0)
			out[i++] = 'M';
		else if (x == 1)
			out[i++] = 'm';

		out[i++] = x == 2 ? '7' : rand() % 2 == 0 && seven ? '7' : 0;
		wprintf(L"%ls\n\n", out);

		i = 0;  ZERO(out); sleep(speed);
	}

	delete [] out;
}
