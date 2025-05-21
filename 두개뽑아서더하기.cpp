#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[7] = { false, };
vector<int> answer;
int res = 0;

void Search(const vector<int>& numbers, int next, int sumNum)
{
	if (sumNum <= 0)
	{
		answer.push_back(res);
		return;
	}


	for (int i = 0; i < numbers.size(); ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			res += numbers[next];
			Search(numbers, i + 1, sumNum - 1);
			visited[i] = false;
			res = 0;
		}
	}
}

int main()
{
	vector<int> test = { 2,1,3,4,1 };
	Search(test, 0, 2);

	for (int ele : answer)
		cout << ele << endl;

}