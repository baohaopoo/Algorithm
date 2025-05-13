#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	map<string, vector<string>> RelationMap;
	map<string, int> PauseMember;
	vector<string> Dot;

	for (int i = 0; i < report.size(); ++i)
	{

		string PickMemeberStr = report[i].substr(0, report[i].find(" ")); // 신고자
		string PickedMemeberStr = report[i].substr(report[i].find(" "), report[i].length()); //신고당한자

		auto iter = find(RelationMap[PickMemeberStr].begin(), RelationMap[PickMemeberStr].end(), PickedMemeberStr);
		if (iter == RelationMap[PickMemeberStr].end())
			RelationMap[PickMemeberStr].push_back(PickedMemeberStr);
	}

	for (auto iter = RelationMap.begin(); iter != RelationMap.end(); ++iter)
	{
		for (int j = 0; j < iter->second.size(); ++j)
			PauseMember[iter->second[j]]++;
	}

	for (auto iter = PauseMember.begin(); iter != PauseMember.end(); ++iter)
	{
		if (iter->second >= k)
			Dot.push_back(iter->first);
	}

	for (int i = 0; i < id_list.size(); ++i)
	{
		int cnt = 0;
		for (int j = 0; j < RelationMap[id_list[i]].size(); ++j)
		{
			auto ele = find(Dot.begin(), Dot.end(), RelationMap[id_list[i]][j]);
			if (ele != Dot.end())
				cnt++;
		}
		answer.push_back(cnt);
	}

	return answer;
}