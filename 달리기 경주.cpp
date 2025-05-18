#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

	map<string, int> map;

	int cnt = 0;
	for (string ele : players)
	{
		map.insert(pair(ele, cnt));
		cnt++;
	}

	for (int i = 0; i < callings.size(); ++i)
	{
		int index = map[callings[i]];
		if (index > 0)
		{
			map[players[index - 1]] = index;
			map[players[index]] = index - 1;
			swap(players[index], players[index - 1]);
		}
	}
	return players;
}