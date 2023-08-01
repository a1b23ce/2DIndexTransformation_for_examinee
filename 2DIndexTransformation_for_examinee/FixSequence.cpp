#include "FixSequence.h"
#include "common.h"

#define inputfile_path  "model.txt"				// 請替換成您的檔案路徑	(read)
#define inputfile_path2 "FormattedOutput.txt"			// 請替換成您的檔案路徑	(read)

void FixSeq(vector <element>& ELEMENT3)
{
	vector <element> ELEMENT;
	vector <element> ELEMENT2;
	
	vector <string> elements;
	string temp_line;

	ifstream file(inputfile_path);			//read file
	if (!file.is_open())
	{
		cout << "無法開啟檔案：" << inputfile_path << endl;
		return;
	}
	ifstream file2(inputfile_path2);			//read file
	if (!file.is_open())
	{
		cout << "無法開啟檔案：" << inputfile_path2 << endl;
		return;
	}

	while (getline(file, temp_line))
	{
		elements.clear();

		stringstream ss(temp_line);
		string item;
		while (getline(ss, item, '@'))		//以@符號分隔元件
			elements.push_back(item);
		/*
		if (elements.size() == 5 && item.empty())				//保險機制
			if (isInteger(elements[0]) && isFloat(elements[1]) && isFloat(elements[2]) && isFloat(elements[3]) && isFloat(elements[4]))
				ELEMENT.push_back(element(atoi(elements[0].c_str()), stof(elements[1]), stof(elements[2]), stof(elements[3]), stof(elements[4]), ""));
		*/
		if (elements.size() == 6)								//保險機制
			if (isInteger(elements[0]) && isFloat(elements[1]) && isFloat(elements[2]) && isFloat(elements[3]) && isFloat(elements[4]) && elements[5] != "(null)")
				ELEMENT.push_back(element(atoi(elements[0].c_str()), stof(elements[1]), stof(elements[2]), stof(elements[3]), stof(elements[4]), elements[5]));
	}

	while (getline(file2, temp_line))
	{
		elements.clear();

		stringstream ss(temp_line);
		string item;
		while (getline(ss, item, '@'))		//以@符號分隔元件
			elements.push_back(item);
		/*
		if (elements.size() == 5 && item.empty())				//保險機制
			if (isInteger(elements[0]) && isFloat(elements[1]) && isFloat(elements[2]) && isFloat(elements[3]) && isFloat(elements[4]))
				ELEMENT2.push_back(element(atoi(elements[0].c_str()), stof(elements[1]), stof(elements[2]), stof(elements[3]), stof(elements[4]), ""));
		*/
		if (elements.size() == 6)								//保險機制
			if (isInteger(elements[0]) && isFloat(elements[1]) && isFloat(elements[2]) && isFloat(elements[3]) && isFloat(elements[4]) && elements[5] != "(null)")
				ELEMENT2.push_back(element(atoi(elements[0].c_str()), stof(elements[1]), stof(elements[2]), stof(elements[3]), stof(elements[4]), elements[5]));
	}

	bool* placed_ELEMENT2 = new bool[ELEMENT2.size() + 15];		//已放置/未放置
	for (int i = 0; i < ELEMENT2.size() + 5; i++)
		placed_ELEMENT2[i] = false;

	for (int i = 0; i < ELEMENT.size(); i++)
	{
		for (int j = 0; j < ELEMENT2.size(); j++)
		{
			if (ELEMENT2[j].word == ELEMENT[i].word && placed_ELEMENT2[j] == false)
			{
				ELEMENT3.push_back(element(ELEMENT[i].index, ELEMENT2[j].x1, ELEMENT2[j].y1, ELEMENT2[j].x2, ELEMENT2[j].y2, ELEMENT2[j].word));
				placed_ELEMENT2[j] = true;
				break;
			}
		}
	}

	int element_num = ELEMENT.back().index + 1;
	for (int i = 0; i < ELEMENT2.size(); i++)
		if (placed_ELEMENT2[i] == false)
		{
			ELEMENT3.push_back(element(element_num, ELEMENT2[i].x1, ELEMENT2[i].y1, ELEMENT2[i].x2, ELEMENT2[i].y2, ELEMENT2[i].word));
			element_num++;
		}

	file.close();
	file2.close();
}
