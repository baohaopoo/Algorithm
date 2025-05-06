#include<iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> numberVec;
vector<bool> visited(10, false);
vector<int> path;
vector<int> answers;
int answer = 0;

bool CheckPrimeNum(int num)
{
	if (num <= 1)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;

	for (int i = 3; i * i <= num; i += 2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void dfs(int depth)
{
	if (numberVec.size() < depth)
	{
		return;
	}
	else
	{
		string str = "";

		for (auto& iter : path)
		{
			string temp = to_string(iter);
			str += temp;
			cout << iter;
		}

		cout << endl;

		if (!str.empty())
		{
			int num = stoi(str);
			if (CheckPrimeNum(num))
			{
				answers.push_back(num);
				answer++;
			}
		}
	}


	for (int i = 0; i < numberVec.size(); ++i)
	{
		//cout << "선택된 정점 : " << numberVec[i] << endl; //1

		if (!visited[numberVec[i]])
		{
			if (visited[numberVec[i]])


				visited[numberVec[i]] = true;
			path.push_back(numberVec[i]);
			dfs(depth + 1);
			path.pop_back();
			visited[numberVec[i]] = false;
		}
	}

}

int solution(string numbers) {

	for (int i = 0; i < numbers.size(); ++i)
	{
		numberVec.push_back(numbers.at(i) - '0');
	}

	dfs(0);

	return answer;
}

int main()
{
	string str = "011";

	solution(str);

	cout << "---------------------------------" << endl;
	for (auto& iter : answers)
		cout << iter << endl;
	cout << "---------------------------------" << endl;
	cout << answer << endl;
}