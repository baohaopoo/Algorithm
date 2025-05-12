#include<iostream>
#include <string>
#include <vector>
using namespace std;

//백트랙킹
vector<bool> visited;
int res = 0;
int answer = 0;

void dfs(vector<int> number, int targetdepth, int startidx)
{
	if (targetdepth == 3)
	{
		if (res == 0)
			answer++;

		return;
	}
	
	for (int i = startidx; i < number.size(); ++i)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			res += number[i];
			dfs(number, targetdepth + 1, i+1);
			res -= number[i];
			visited[i] = false;
		}
	}
}

int solution(vector<int> number) {

	visited.assign(number.size(), false); 
	dfs(number, 0, 0);

	return answer;
}

int main()
{
	vector<int> TestVec = { -2,3,0,2,-5 };
	cout << solution(TestVec) << endl;
}
