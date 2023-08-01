#include "2DIndexTransformation.h"
#include "common.h"

#define outputfile_path "TDTrans.txt"				// 請替換成您的檔案路徑	(write)

void IndexTrans(const vector <element>& ELEMENT)
{
	vector <element_2D> ELEMENT_2D;
	vector <string> elements;
	vector <float> element_x2;	//rightmost ,水平線的LINE, edge survival method
	vector <float> element_y2;	//垂直線的LINE, edge survival method
	string temp_line;

	ofstream output_file(outputfile_path);	//write file

	for (int i = 0; i < ELEMENT.size(); i++)
	{
		element_x2.push_back(ELEMENT[i].x2);		//垂直線
		element_y2.push_back(ELEMENT[i].y2);		//水平線
		ELEMENT_2D.push_back(element_2D());			//轉換成2D
	}

	sort(element_x2.begin(), element_x2.end());	//以小到大(左到右)
	sort(element_y2.begin(), element_y2.end());	//以小到大(上到下)
	element_x2.erase(unique(element_x2.begin(), element_x2.end()), element_x2.end());	//刪除重複元素
	element_y2.erase(unique(element_y2.begin(), element_y2.end()), element_y2.end());	//刪除重複元素

	int coordinate_x = 1;
	bool* placed_ELEMENT = new bool[ELEMENT.size() + 5];		//已放置/未放置
	for (int i = 0; i < ELEMENT.size() + 5; i++)
		placed_ELEMENT[i] = false;
	for (int i = 0; i < element_x2.size(); i++)					//垂直線
	{
		bool have_element = false;
		for (int j = 0; j < ELEMENT.size(); j++)
			if (ELEMENT[j].middle_x <= element_x2[i] && placed_ELEMENT[j] == false)		//如果該元件的中心點在線的左邊，且還沒有x(未被放置)
			{
				ELEMENT_2D[j].index = ELEMENT[j].index;
				ELEMENT_2D[j].x = coordinate_x;
				ELEMENT_2D[j].word = ELEMENT[j].word;
				placed_ELEMENT[j] = true;						//已放置
				have_element = true;
			}
		if (have_element == true)
			coordinate_x++;
	}

	int coordinate_y = 1;
	for (int i = 0; i < ELEMENT.size() + 5; i++)
		placed_ELEMENT[i] = false;
	for (int i = 0; i < element_y2.size(); i++)					//水平線
	{
		bool have_element = false;
		for (int j = 0; j < ELEMENT.size(); j++)
			if (ELEMENT[j].middle_y <= element_y2[i] && placed_ELEMENT[j] == false)		//如果該元件的中心點在線的上面，且還沒有y(未被放置)
			{
				ELEMENT_2D[j].y = coordinate_y;
				placed_ELEMENT[j] = true;
				have_element = true;
			}
		if (have_element == true)
			coordinate_y++;
	}

	for (int i = 0; i < ELEMENT_2D.size(); i++)
		output_file << ELEMENT_2D[i].index << "@" << ELEMENT_2D[i].x << "@" << ELEMENT_2D[i].y << "@" << ELEMENT_2D[i].word << endl;

	output_file.close();
}

