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

	MMNum += typeMonth;

	if (MMNum > 12)
	{
		YYNum += MMNum / 12;
		MMNum -= 12;
	}

	if (DDNum - 1 < 1)
	{
		DDNum = 28;
		MMNum -= 1;
	}
	else
		DDNum -= 1;

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

	cout << today << endl;

	for (int j = 0; j < privacies.size(); ++j)
	{

		string PrivacyStr = privacies[j].substr(0, privacies[j].find(" ")); //2021.05.02
		int TypeMonth = standardMap[privacies[j][privacies[j].size() - 1]]; //A - 6
		string GoalStr = GetGoal(PrivacyStr, TypeMonth); //2021.06.01

		for (int i = 0; i < today.size(); ++i)
		{
			if (today[i] != GoalStr[i])
			{
				if (today[i] - '0' > GoalStr[i] - '0')
				{
					answer.push_back(j + 1);
					break;
				}
				else
					break;
			}
		}
	}

	return answer;
}