#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
string GetGoal(string& Privacy, int typeMonth)
{
	string GoalStr = "";

	string YYstr = "";
	YYstr += Privacy[0];
	YYstr += Privacy[1];
	YYstr += Privacy[2];
	YYstr += Privacy[3];
	int YYNum = stoi(YYstr);

	string MMstr = "";
	MMstr += Privacy[5];
	MMstr += Privacy[6];
	int MMNum = stoi(MMstr);

	string DDstr = "";
	DDstr += Privacy[8];
	DDstr += Privacy[9];
	int DDNum = stoi(DDstr);

	//cout<<YYNum<<","<<MMNum<<","<<DDNum<<endl;

	MMNum += typeMonth;

	YYNum += MMNum / 12;
	DDNum -= 1;

	if (MMNum > 12)
		MMNum -= 13;

	if (DDNum < 1)
	{
		MMNum -= 1;
		DDNum = 28;
	}

	//cout<<YYNum<<","<<MMNum<<","<<DDNum<<endl;

	GoalStr += to_string(YYNum);
	GoalStr += ".";
	if (MMNum < 10)
		GoalStr += "0";
	GoalStr += to_string(MMNum);
	GoalStr += ".";
	if (DDNum < 10)
		GoalStr += "0";
	GoalStr += to_string(DDNum);
	return GoalStr;

}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	map<char, int> standardMap;
	for (string ele : terms) //  A 6 
	{
		string day = ele.substr(ele.find(" "), ele.length());
		standardMap[ele[0]] = stoi(day);
	}

	for (string ele : privacies)
	{
		string PrivacyStr = ele.substr(0, ele.find(" ")); //2021.05.02
		int TypeMonth = standardMap[ele[ele.size() - 1]]; //A - 6
		string GoalStr = GetGoal(PrivacyStr, TypeMonth); //2021.06.01

		//cout<<PrivacyStr<<endl;
		//cout<<GoalStr<<endl;
		//cout<<"-----------------------"<<endl;


		cout << today << endl;
		cout << GoalStr << endl;

		for (int i = 0; i < today.size(); ++i)
		{
			if (today[i] - '0' > GoalStr[i] - '0')
			{
				continue;
			}
		}
		//cout<<endl;
	}

	return answer;
}