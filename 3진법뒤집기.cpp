#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0;
	string remainderStr;

	while (n != 0)
	{
		remainderStr += to_string(n % 3);
		n /= 3;
	}

	for (int i = 0; i < remainderStr.size(); ++i)
	{
		int remainderele = remainderStr[i] - '0';
		int multiValue = pow(3, remainderStr.size() - 1 - i);

		answer += remainderele * multiValue;
	}

	return answer;
}