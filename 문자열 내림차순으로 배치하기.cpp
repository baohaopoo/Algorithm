
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "";

	//대문자 < 소문자
	vector<char> big;
	vector<char> small;

	for (char c : s)
	{
		if (c >= 'a' && c <= 'z')
			small.push_back(c);
		else if (c >= 'A' && c <= 'Z')
			big.push_back(c);
	}

	sort(small.begin(), small.end(), [](char a, char b) {return a > b; });
	sort(big.begin(), big.end(), [](char a, char b) {return a > b; });

	for (char s : small)
		answer += s;

	for (char b : big)
		answer += b;

	return answer;
}
