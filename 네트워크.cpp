#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	vector<vector<bool>> visited{ computers.size(),vector<bool>(computers[0].size(), false) };
	queue<pair<int, int>> q;

	q.push({ 0,0 });

	while (!q.empty())
	{
		auto [curx, cury] = q.front();
		q.pop();
		visited[curx][cury] = 1;
		computers[curx][cury] = 2;

		int dx[4] = { 0,1,0,-1 };
		int dy[4] = { -1,0,1,0 };

		for (int i = 0; i < 4; ++i)
		{
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];

			if (nextx < 0 || nexty < 0 || nextx >= computers[0].size() || nexty >= computers[0].size())
				continue;

			if (visited[nextx][nexty] == true)
				continue;

			if (computers[nextx][nexty] == 1)
			{
				q.push({ nextx,nexty });
			}

		}
	}

	set<int> answers;

	for (int i = 0; i < computers.size(); ++i)
	{
		for (int j = 0; j < computers[0].size(); ++j)
		{
			if (computers[i][j] != 0)
				answers.insert(computers[i][j]);
		}
	}

	answer = answers.size();

	return answer;
}