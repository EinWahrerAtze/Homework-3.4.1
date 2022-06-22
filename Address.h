#include <string>
#pragma once

class Address
{
public:
	std::wstring get_output_string(void) const;
	void show(void) const;
	Address();
	Address(const std::wstring &m_city,
			const std::wstring &m_street,
			const unsigned short m_build_num,
			const unsigned short m_flat_num);
	~Address();
private:
	std::wstring city;
	std::wstring street;
	unsigned short build_num;
	unsigned short flat_num;
};