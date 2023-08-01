#include "common.h"

bool isInteger(const std::string& s)
{
	try
	{
		size_t pos = 0;
		std::stoi(s, &pos);
		return pos == s.length(); // 絋玂俱﹃常锣传俱计
	}
	catch (const std::exception& e)
	{
		return false; // 锣传ア毖ぃ琌俱计
	}
}

bool isFloat(const std::string& s)
{
	try
	{
		size_t pos = 0;
		std::stof(s, &pos);
		return pos == s.length(); // 絋玂俱﹃常锣传疊翴计
	}
	catch (const std::exception& e)
	{
		return false; // 锣传ア毖ぃ琌疊翴计
	}
}