#include <string>
#include <vector>

using namespace std;

int GetValue(int n)
{
	int answer = 0;
	while (n != 0)
	{
		if (n % 2 == 1)
			answer++;
		n /= 2;
	}
	return answer;
}
int solution(int n) {
	int answer = 0;

	int nValue = GetValue(n);
	while (answer == 0)
	{
		++n;

		if (nValue == GetValue(n))
		{
			answer = n;
			break;
		}

	}
	return answer;
}