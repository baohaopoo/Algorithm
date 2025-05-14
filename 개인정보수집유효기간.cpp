#include <string>
#include <vector>
#include <map>
#include<iostream>
using namespace std;


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	map<string, string> Table;

	for (int i = 0; i < terms.size(); ++i)
	{
		string standardStr = terms[i].substr(0, terms[i].find(" "));
		string MonthStr = terms[i].substr(terms[i].find(" "), terms[i].length());

		string YYstr = ""; //2021
		YYstr += standardStr[0];
		YYstr += standardStr[1];
		YYstr += standardStr[2];
		YYstr += standardStr[3];

		string MMstr = ""; //11
		MMstr += standardStr[5];
		MMstr += standardStr[6];

		string Daystr = ""; //15
		Daystr += standardStr[8];
		Daystr += standardStr[9];

		int Year = stoi(YYstr);
		int Month = stoi(MMstr);
		int Day = stoi(Daystr);

		cout << Year << "," << Month << "," << Day << endl;

		int goalYear = 0;
		int goalMonth = stoi(MMstr) + stoi(MonthStr);

		if (goalMonth >= 12)
		{
			goalYear = stoi(YYstr) + (goalMonth / 12);
		}
	
		res += to_string(goalYear);
		res += ".";

		// Table[standardStr] = //´õÇÑ °ª.
	}

	for (int i = 0; i < privacies.size(); ++i)
	{
		string standardStr = privacies[i].substr(privacies[i].find(" "), privacies[i].length());
		string PrivacyStr = privacies[i].substr(0, privacies[i].find(" "));

		for (int j = 0; j < PrivacyStr.size(); ++j)
		{
			int current = stoi(PrivacyStr);
			int Future = 0;
			if (Table.find(standardStr) != Table.end())
			{
				Future = stoi(Table[standardStr]);
			}

			if (current > Future)
			{
				answer.push_back(i);
			}
		}
	}

	return answer;
}