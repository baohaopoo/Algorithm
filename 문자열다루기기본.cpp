#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
	bool answer = true;

	if (s.size() != 4 && s.size() != 6)
		return false;

	for (char iter : s)
	{
		if (iter - '0' > 9 || iter - '0' < 0)
			return false;
		else answer = true;

	}
	return answer;

}