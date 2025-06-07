#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<string> maps) {
	int answer = 0;

	vector<vector<char>> MapV;
	vector<char> LowV;

	for (int i = 0; i < maps.size(); ++i)
	{
		LowV.clear();
		for (int j = 0; j < maps[i].size(); ++j)
		{
			LowV.push_back(maps[i][j]);
		}
		MapV.push_back(LowV);
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	char target = 'S';

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };

	while (!q.empty())
	{
		auto [curx, cury] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];

			char nextTarget;

			if (target == 'S')
				nextTarget = 'L';
			if (target == 'L')
				nextTarget = 'E';
			if (target == 'E')
				return answer;

			if (nextx < 0 || nexty < 0 || nextx >= MapV[0].size() || nexty >= MapV[0].size())
				continue;

			if (MapV[nextx][nexty] == 'X')
				continue;

			if (MapV[curx][cury] == target || MapV[curx][cury] == 'O')
			{
				if (MapV[curx][cury] == target && target != 'S')
					answer++;
				target = nextTarget;
				q.push({ nextx,nexty });
			}

		}
	}


	return answer;
}