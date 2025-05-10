#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
	string answer = "";
	bool bIsEvenNum = true;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ')
		{
			answer += ' ';
			bIsEvenNum = true;
		}
		else
		{
			if (!bIsEvenNum)
			{
				if ('A' <= s[i] && 'Z' >= s[i])
					answer += (int(s[i]) + 32);
				else
					answer += s[i];

				bIsEvenNum = true;
			}
			else
			{
				if ('a' <= s[i] && 'z' >= s[i])
					answer += (int(s[i]) - 32);
				else
					answer += s[i];

				bIsEvenNum = false;
			}
		}
	}
	return answer;
}

int main()
{
	string test = "try hello world"; //Aa A Aa
	cout<<solution(test);
}