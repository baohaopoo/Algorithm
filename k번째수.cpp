#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> res;
	for (int i = 0; i < commands.size(); ++i)
	{
		for (int j = commands[i][0]; j <= commands[i][1]; ++j)
			res.push_back(array[j - 1]);

		sort(res.begin(), res.end());

		answer.push_back(res[commands[i][2] - 1]);
		res.clear();
	}

	return answer;
}