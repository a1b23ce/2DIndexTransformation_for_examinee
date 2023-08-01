#include "common.h"

bool isInteger(const std::string& s)
{
	try
	{
		size_t pos = 0;
		std::stoi(s, &pos);
		return pos == s.length(); // �T�O��Ӧr�곣�ഫ�����
	}
	catch (const std::exception& e)
	{
		return false; // �ഫ���ѡA���O���
	}
}

bool isFloat(const std::string& s)
{
	try
	{
		size_t pos = 0;
		std::stof(s, &pos);
		return pos == s.length(); // �T�O��Ӧr�곣�ഫ���B�I��
	}
	catch (const std::exception& e)
	{
		return false; // �ഫ���ѡA���O�B�I��
	}
}