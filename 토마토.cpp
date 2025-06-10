#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int M = 6;
	int N = 4;

	int day = 0;
	vector<vector<int>> box = { {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,1}};

	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<pair<int, int>> q;

	q.push({0,0});

	while (!q.empty())
	{
		auto [curx, cury] = q.front();
		q.pop();
		visited[curx][cury] = true;
		
		int dx[4] = { 0,1,0,-1 };
		int dy[4] = { -1,0,1,0 };
		int nextx = 0;
		int nexty = 0;

		for (int i = 0; i < 4; ++i)
		{
			nextx = curx + dx[i];
			nexty = cury + dy[i];

			if (nextx < 0 || nexty < 0 || nextx >= box.size() || nexty >= box[0].size())
				continue;

			if (visited[nextx][nexty])
				continue;

			if (box[nextx][nexty] == -1)
				continue;

			if (box[nextx][nexty] == 0)
			{
				day++;
				cout << nextx << "," << nexty << endl;
				q.push({ nextx,nexty });
				break;
			}
		}
	}


	cout << day << endl;
}