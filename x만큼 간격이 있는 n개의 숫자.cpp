#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;

	long long res = 0;
	for (int i = 0; i < n; ++i)
	{
		res += x;
		answer.push_back(res);
	}
	return answer;
}