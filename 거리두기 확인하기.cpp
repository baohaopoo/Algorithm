#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	queue<pair<int, int>> q;
	int idxX = 0;
	int idxY = 0;

	q.push({ idxX,idxY });

	while (!q.empty())
	{
		auto [curx, cury] = q.front();
		q.pop();

		int mzonex[8] = { 0,2,2,2,0,-2,-2,-2 };
		int mzoney[8] = { -2,-2,0,2,2,2,0,-2 };

		int pzonex[8] = { 0,1,1,1,0,-1,-1,-1 };
		int pzoney[8] = { -1,-1,0,1,1,1,0,-1 };

		for (int i = 0; i < 8; ++i)
		{
			int nextx = curx + mzonex[i];
			int nexty = cury + mzoney[i];

			if (nextx < 0 || nexty < 0 || nextx >= 5 || nexty >= 5)
				continue;

			if (places[curx][cury] != "P" || places[curx][cury] == "X")
				continue;

			if (places[nextx][nexty] == "P")
			{
				//맨해튼존에 사람 있으면 파티션존 검사
				for (int j = 0; j < 8; ++j)
				{
					int partx = curx + pzonex[j];
					int party = cury + pzoney[j];
					if (places[partx][partx] == "X")
						continue;
					else
					{
						answer.push_back(0);
						break;
					}

				}

			}
			else
				continue;
		}
	}


	return answer;
}
