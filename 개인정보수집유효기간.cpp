#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int CalculateTotal(int YYNum, int MMNum, int DDNum, int TypeMonth)
{
	int Total = (YYNum * (28 * 12)) + (MMNum * 28) + DDNum;
	cout << Total << endl;

	Total += (TypeMonth * 28);

	return Total;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	map<char, int> standardMap;
	for (string ele : terms) //  A 6 
	{
		string day = ele.substr(ele.find(" "), ele.length());
		standardMap[ele[0]] = stoi(day);
	}

	for (int j = 0; j < privacies.size(); ++j)
	{

		string PrivacyStr = privacies[j].substr(0, 10);
		int TypeMonth = standardMap[privacies[j][privacies[j].size() - 1]]; //A - 6

		//목표 일수
		string GoalYYstr = "";

		int GoalYYNum = stoi(PrivacyStr.substr(0, 4));
		int GoalMMNum = stoi(PrivacyStr.substr(5, 2));
		int GoalDDNum = stoi(PrivacyStr.substr(8, 2));

		int GoalTotal = CalculateTotal(GoalYYNum, GoalMMNum, GoalDDNum, TypeMonth) - 1;

		//오늘 일수
		int TodayYYNum = stoi(today.substr(0, 4));
		int TodayMMNum = stoi(today.substr(5, 2));
		int TodayDDNum = stoi(today.substr(8, 2));

		int Todaytotal = CalculateTotal(TodayYYNum, TodayMMNum, TodayDDNum, 0);

		if (GoalTotal < Todaytotal)
			answer.push_back((j + 1));
	}

	return answer;
}