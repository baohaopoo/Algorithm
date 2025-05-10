#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
	string answer = "";

	for (char c : s)
	{
		if (c == ' ')
			answer += ' ';
		else
		{
			if (((c >= 97 && c <= 122) && (c + n > 'z')) || ((c >= 65 && c <= 90) && (c + n > 'Z')))
				c -= 26;

			char res = c + n;
			answer += res;
		}
	}
	return answer;
}