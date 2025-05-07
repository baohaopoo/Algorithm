#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;

	int pCnt = 0;
	int yCnt = 0;

	for (char ch : s)
	{
		if (ch == 'p' || ch == 'P') pCnt++;
		else if (ch == 'y' || ch == 'Y') yCnt++;
	}

	if (pCnt == 0 && yCnt == 0) return true;
	pCnt == yCnt ? answer = true : answer = false;

	return answer;
}