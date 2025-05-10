#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
	long long answer = 0;

	string nStr = to_string(n);
	vector<long long> nStrVec;

	for (char ele : nStr)
		nStrVec.push_back(ele - '0');

	sort(nStrVec.begin(), nStrVec.end(), [](long long a, long long b) {return a > b; });

	string answerStr;
	for (long long ele : nStrVec)
		answerStr += to_string(ele);

	answer = stol(answerStr);

	return answer;
}