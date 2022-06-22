#include <iostream>
#include <string>
#include "Address.h"

std::wstring Address::get_output_string(void) const
{
	std::wstring output_string = city + L", " + street + L", " + std::to_wstring(build_num) + L", " + std::to_wstring(flat_num) + L"\n";
	return output_string;
}

void Address::show(void) const
{
	std::wcout << city << L", " << street << L", " << build_num << L", " << flat_num << std::endl;
}

Address::Address()
{
	city = L"none";
	street = L"none";
	build_num = 0;
	flat_num = 0;
}

Address::Address(const std::wstring &m_city,
				 const std::wstring &m_street,
				 const unsigned short m_build_num,
				 const unsigned short m_flat_num)
{
	city = m_city;
	street = m_street;
	build_num = m_build_num;
	flat_num = m_flat_num;
}

Address::~Address()
{
}