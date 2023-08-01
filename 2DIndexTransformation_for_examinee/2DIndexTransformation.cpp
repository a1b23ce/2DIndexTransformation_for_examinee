#include "2DIndexTransformation.h"
#include "common.h"

#define outputfile_path "TDTrans.txt"				// �д������z���ɮ׸��|	(write)

void IndexTrans(const vector <element>& ELEMENT)
{
	vector <element_2D> ELEMENT_2D;
	vector <string> elements;
	vector <float> element_x2;	//rightmost ,�����u��LINE, edge survival method
	vector <float> element_y2;	//�����u��LINE, edge survival method
	string temp_line;

	ofstream output_file(outputfile_path);	//write file

	for (int i = 0; i < ELEMENT.size(); i++)
	{
		element_x2.push_back(ELEMENT[i].x2);		//�����u
		element_y2.push_back(ELEMENT[i].y2);		//�����u
		ELEMENT_2D.push_back(element_2D());			//�ഫ��2D
	}

	sort(element_x2.begin(), element_x2.end());	//�H�p��j(����k)
	sort(element_y2.begin(), element_y2.end());	//�H�p��j(�W��U)
	element_x2.erase(unique(element_x2.begin(), element_x2.end()), element_x2.end());	//�R�����Ƥ���
	element_y2.erase(unique(element_y2.begin(), element_y2.end()), element_y2.end());	//�R�����Ƥ���

	int coordinate_x = 1;
	bool* placed_ELEMENT = new bool[ELEMENT.size() + 5];		//�w��m/����m
	for (int i = 0; i < ELEMENT.size() + 5; i++)
		placed_ELEMENT[i] = false;
	for (int i = 0; i < element_x2.size(); i++)					//�����u
	{
		bool have_element = false;
		for (int j = 0; j < ELEMENT.size(); j++)
			if (ELEMENT[j].middle_x <= element_x2[i] && placed_ELEMENT[j] == false)		//�p�G�Ӥ��󪺤����I�b�u������A�B�٨S��x(���Q��m)
			{
				ELEMENT_2D[j].index = ELEMENT[j].index;
				ELEMENT_2D[j].x = coordinate_x;
				ELEMENT_2D[j].word = ELEMENT[j].word;
				placed_ELEMENT[j] = true;						//�w��m
				have_element = true;
			}
		if (have_element == true)
			coordinate_x++;
	}

	int coordinate_y = 1;
	for (int i = 0; i < ELEMENT.size() + 5; i++)
		placed_ELEMENT[i] = false;
	for (int i = 0; i < element_y2.size(); i++)					//�����u
	{
		bool have_element = false;
		for (int j = 0; j < ELEMENT.size(); j++)
			if (ELEMENT[j].middle_y <= element_y2[i] && placed_ELEMENT[j] == false)		//�p�G�Ӥ��󪺤����I�b�u���W���A�B�٨S��y(���Q��m)
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

