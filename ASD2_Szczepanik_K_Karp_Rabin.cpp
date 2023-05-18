#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

//constexpr auto MAX_INPUT_LENGTH = 100000;
//std::wstring ReadUTF8FromConsole()
//{
//	wchar_t wstr[MAX_INPUT_LENGTH];
//	unsigned char mb_str[MAX_INPUT_LENGTH * 3 + 1];
//	
//	unsigned long read;
//	void* con = GetStdHandle(STD_INPUT_HANDLE);
//	ReadConsole(con, wstr, MAX_INPUT_LENGTH, &read, NULL);
//	int size = WideCharToMultiByte(CP_UTF8, 0, wstr, read, (LPSTR)mb_str, sizeof(mb_str), NULL, NULL);
//	mb_str[size] = 0;
//	std::wstring Final = L"";
//	int i = 0;
//	/*for (i = 0; i < MAX_INPUT_LENGTH; ++i)
//	{
//		if (mb_str[i] == 13)break;
//		Final += mb_str[i];
//	}*/
//	for (i = 0; i < MAX_INPUT_LENGTH; ++i)
//	{
//		if (wstr[i] == 13)break;
//		Final += wstr[i];
//	}
//	return Final;
//	//std::printf("ENTERED: %s\n", mb_str);
//}

std::vector <int >KarpRabin(std::vector<unsigned char>& Data, std::wstring Pattern, int base, int Prime)
{
	std::vector <int>Result;
	int m = Pattern.size();
	int n = Data.size();
	//long long  h = pow(base, m - 1);
	//h = h % Prime;
	int i=0,j = 0;
	long long h = 1;
	for (i = 0; i < m-1 ; ++i)
		h = (h * base) % Prime;
	long long  p = 0;
	long long t0 = 0;
	for (size_t i = 0; i < m; ++i)
	{
		p = (base * p + Pattern[i]) % Prime;
		t0 = (base * t0 + Data[i]) % Prime;
	}
	for (size_t s = 0; s < (n - m); ++s)
	{
		if (p == t0)
		{
			for (j = 0; j < m; ++j) 
			{
				if (Data[s + j] != Pattern[j]) 
				{
					break;
				}
			}
				if (j == m) {
					Result.push_back(s);
				}
		
		}
	
			t0 = (base * (t0 - Data[s] * h) + Data[s + m]) % Prime;

			//if (t0 < 0)
			t0 = (t0 + Prime);
		
	}
	
		return Result;
}

int main()
{
	//SetConsoleOutputCP(CP_UTF8);
	//SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(1250);
	SetConsoleCP(1250);
	


	int result;
	int CasesNo = 0;
	std::cin >> CasesNo;
	std::cin.ignore();
	std::vector<std::vector<int>>Result;
	Result.reserve(CasesNo);
	for (size_t i = 0; i < CasesNo; ++i)
	{
	
		std::vector<unsigned char>Data;
		std::wstring FileName;
		std::wstring Pattern;
		//FileName = ReadUTF8FromConsole();
		//Pattern = ReadUTF8FromConsole();

		std::getline(std::wcin, FileName);
		std::getline(std::wcin, Pattern);

		std::fstream File;	
		File.open(FileName, std::ios::in);
		if (File.is_open())
		{

			std::streampos begin, end;
			begin = File.tellg();
			File.seekg(0, std::ios::end);
			end = File.tellg();
			int size = end - begin;
			File.seekg(0, std::ios::beg);
			Data.reserve(size);	
			bool doubleByte = false;
			while (!File.eof())

			{
				char ch2;
				File.get(ch2);
				int ch =static_cast<unsigned char>( ch2);
			/*	if (ch == 195||ch==196||ch==197)
				{
					doubleByte = true;
					continue;
				}*/
				/*if (doubleByte)
				{

				//UTF8
					doubleByte = false;
					if (ch == 132)ch = 260;
					else if (ch == 133)ch = 261;

					else if (ch == 134)ch = 262;
					else if (ch == 135)ch = 263;

					else if (ch == 152)ch = 280;
					else if (ch == 153)ch = 281;

					else if (ch == 129)ch = 321;
					else if (ch == 130)ch = 322;

					else if (ch == 147)ch = 211;
					else if (ch == 179)ch = 243;


					else if (ch == 154)ch = 346;
					else if (ch == 155)ch = 347;

					else if (ch == 185)ch = 377;
					else if (ch == 186)ch = 378;

					else if (ch == 187)ch = 379;
					else if (ch == 188)ch = 380;

					
				}*/


				//ANSI
				//A ą
				//if (ch == 161)ch = 260;
				//else if (ch == 177)ch = 261;
				////Ć ć
				//else if (ch == 198)ch = 262;
				//else if (ch == 230)ch = 263;

				////Ę ę
				//else if (ch == 202)
				//{
				//	ch = 280;
				//}
				//else if (ch == 234)ch = 281;

				////Ł ł
				//else if (ch == 163)ch = 321;
				//else if (ch == 179)ch = 322;

				////Ń ń
				//else if (ch == 209)ch = 323;
				//else if (ch == 241)ch = 324;

				////Ó ó
				//else if (ch == 211)ch = 211;
				//else if (ch == 243)ch = 243;

				////Ś ś
				//else if (ch == 166)ch = 346;
				//else if (ch == 182)ch = 347;

				////Ź ź 
				//else if (ch == 172)ch = 377;
				//else if (ch == 188)ch = 378;

				////Ż ż
				//else if (ch == 175)ch = 379;
				//else if (ch == 191)ch = 380;



			 Data.push_back(ch);
			}
			Data.pop_back();
			Result.push_back(KarpRabin(Data, Pattern, 256, 277));//13399
			File.close();
		}
		else std::cout << "problem z otworzeniem pliku\n";



	}

	for (auto& current : Result)
	{
		for (auto& i : current)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";
	}


	std::cin.get();
}


