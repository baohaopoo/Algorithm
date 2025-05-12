#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;

	double sumRes = 0;
	for (const int ele : arr)
	{
		sumRes += ele;
	}

	answer = sumRes / arr.size();
	return answer;
}