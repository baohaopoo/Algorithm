#include <string>
#include <vector>

using namespace std;

int GetValue(int num)
{
	int res = 0;

	for (int i = 1; i <= num; ++i)
	{
		if (num % i == 0)
			res++;
	}
	return res;

}
int solution(int left, int right) {
	int answer = 0;


	for (int i = left; i <= right; ++i)
	{
		GetValue(i) % 2 == 0 ? answer += i : answer -= i;
	}

	return answer;
}