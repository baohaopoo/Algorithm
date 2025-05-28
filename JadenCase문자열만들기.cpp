#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";

	for (int i = 0; i < s.size(); ++i)
	{
		if (i == 0 && 'a' <= s[0] && 'z' >= s[0])
			s[i] -= 32;

		if (s[i] == ' ')
		{

			if ('a' <= s[i + 1] && 'z' >= s[i + 1])
				s[i + 1] -= 32;
		}
		else
		{
			if ('A' <= s[i + 1] && 'Z' >= s[i + 1])
				s[i + 1] += 32;
		}
	}

	answer = s;

	return answer;
}