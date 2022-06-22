#include <iostream>
#include <fstream>
#include <string>
#include "Address.h"

int main()
{
	wchar_t in_filename[] = L"in.txt";
	std::wifstream fin(in_filename);

	if (!fin.is_open())
	{
		std::wcout << L"Could not open " << in_filename << L" for reading.\n";
		std::wcout << L"Programm terminating.\n";
		exit(EXIT_FAILURE);
	}

	unsigned short size = 0;
	fin >> size;

	Address *addresses = new Address[size];
	std::wstring city;
	std::wstring building;
	unsigned short build_num = 0;
	unsigned short flat_num = 0;

	for (int i = 0; i < size; ++i)
	{
		fin >> city >> building >> build_num >> flat_num;
		addresses[i] = Address(city, building, build_num, flat_num);
		addresses[i].show();
	}
	
	if (fin.eof())
	{
		std::wcout << L"\nEnd of file reached.\n";
	}
	else if (fin.fail())
	{
		std::wcout << L"\nInput terminated by data mismatch.\n";
	}
	else
	{
		std::wcout << L"\nInput terminated by unknown reason.\n";
	}

	fin.close();
	wchar_t out_filename[] = L"out.txt";
	std::wofstream fout(out_filename);

	if (!fout.is_open())
	{
		std::wcout << L"Could not open " << out_filename << L" for writing.\n";
		std::wcout << L"Programm terminating.\n";
		exit(EXIT_FAILURE);
	}

	fout << size << std::endl;

	for (int i = size - 1; i >= 0; --i)
	{
		fout << addresses[i].get_output_string();
	}

	if (fout.good())
	{
		std::wcout << L"File " << out_filename << L" successfully written.\n";
	}
	else if (fout.fail())
	{
		std::wcout << L"Output terminated by data mismatch.\n";
	}
	else
	{
		std::wcout << L"Output terminated by unknown reason.\n";
	}

	fout.close();
	delete[] addresses;
	return 0;
}