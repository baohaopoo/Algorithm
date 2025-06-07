#include <string>
#include <vector>
#include <queue>
using namespace std;
void BFS(queue<pair<int, int>>& q, int& answer, vector<vector<bool>>& visited)
{
	//시작 지점을 찾았다는 얘기.
	auto [curx, cury] = q.front();


}
int solution(vector<string> maps) {
	int answer = 0;

	vector<vector<char>> MapV;
	vector<char> LowV;

	for (int i = 0; i < maps.size(); ++i)
	{
		for (int j = 0; j < maps[i].size(); ++j)
		{
			LowV.clear();
			LowV.push_back(maps[i][j]);
		}
		MapV.push_back(LowV);
	}

	vector<vector<bool>> visited(MapV.size(), vector<bool>(MapV[0].size(), false));
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };

	while (!q.empty())
	{
		auto [curx, cury] = q.front();
		q.pop();
		visited[curx][cury] = true;

		if (MapV[curx][cury] != 'S')
		{
			for (int i = 0; i < 4; ++i)
			{
				int nextx = curx + dx[i];
				int nexty = cury + dy[i];

				if (MapV[nextx][nexty] == 'S')
				{
					queue<pair<int, int>> nextq;
					nextq.push({ nextx,nexty });
					BFS(nextq, answer, visited);
				}

			}
			continue;
		}
		else
		{
			for (int i = 0; i < 4; ++i)
			{
				int nextx = curx + dx[i];
				int nexty = cury + dy[i];

				queue<pair<int, int>> nextq;
				nextq.push({ nextx,nexty });
				BFS(nextq, answer, visited);
			}
		}
	}
	return answer;
}