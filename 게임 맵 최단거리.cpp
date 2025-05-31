#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
	int answer = 0;
	vector<vector<int>> distance(maps.size(), vector<int>(maps[0].size(), 0));
	vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), false));

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;
	distance[0][0] = 1;

	while (!q.empty())
	{
		auto [curx, cury] = q.front();
		q.pop();

		int dx[4] = { 1,0,-1,0 };
		int dy[4] = { 0,-1,0,1 };

		for (int i = 0; i < 4; ++i)
		{
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];

			if (nextx < 0 || nexty < 0 || nextx >= maps.size() || nexty >= maps[0].size())
				continue;

			if (visited[nextx][nexty])
				continue;

			if (maps[nextx][nexty] == 0)
				continue;


			visited[nextx][nexty] = 1;
			distance[nextx][nexty] = distance[curx][cury] + 1;
			q.push(pair(nextx, nexty));
		}

	}

	if (visited[maps.size() - 1][maps[0].size() - 1])
		answer = distance[maps.size() - 1][maps[0].size() - 1];
	else
		answer = -1;

	return answer;
}