#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
	string answer = "";

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ')
			answer += ' ';
		else
		{
			if (i & 1)
			{
				if ('A' <= s[i] && 'Z' >= s[i])
					answer += (int(s[i]) + 26);
				else
					answer += s[i];
			}
			else
			{
				if ('a' <= s[i] && 'z' >= s[i])
					answer += (int(s[i]) - 32);
				else
					answer += s[i];
			}
		}
	}
	return answer;
}

int main()
{
	string test = "try hello world";
	cout<<solution(test);
}