#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	int budgetTmp = budget;

	vector<int> answers;

	for (int i = 0; i < d.size(); ++i)
	{
		budgetTmp = budget;
		budgetTmp -= d[i];
		for (int j = i + 1; j < d.size(); ++j)
		{
			budgetTmp -= d[j];
			for (int k = j + 1; k < d.size(); ++k)
			{
				budgetTmp -= d[k];

				if (budgetTmp >= 0)
				{
					answer++;
					cout << d[i] << "," << d[j] << "," << d[k] << endl;
				}

				budgetTmp += d[k];
			}
			budgetTmp += d[j];
		}
		budgetTmp += d[i];

	}

	for (auto& iter : answers)
	{
		cout << iter << endl;
	}

	return answer;
}

int main()
{
	vector<int> d = { 1,3,2,5,4 };
	solution(d, 9);
}