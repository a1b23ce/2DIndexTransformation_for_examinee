#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct element
{
	element(int a, float b, float c, float d, float e, string f)
	{
		index = a;
		x1 = b;
		y1 = c;
		x2 = d;
		y2 = e;
		word = f;
		middle_x = (b + d) / 2;
		middle_y = (c + e) / 2;
	}
	int index;
	float x1;
	float y1;
	float x2;
	float y2;
	string word;
	float middle_x;
	float middle_y;
};

struct element_2D
{
	element_2D()
	{
		index = 0;
		x = 0;
		y = 0;
		word = "";
	}
	element_2D(int a, int b, int c, string d)
	{
		index = a;
		x = b;
		y = c;
		word = d;
	}
	int index;
	int x;
	int y;
	string word;
};

bool isInteger(const std::string& s);
bool isFloat(const std::string& s);