#include <string>
#include <vector>

using namespace std;

//11 6���� 7���� number.size() -1  10-4
//9 5���� 6����  8-4
string solution(string phone_number) {
	string answer = "";

	for (int i = 0; i <= phone_number.size() - 1; ++i)
	{
		if (phone_number.size() > 4 && i <= phone_number.size() - 5)
			answer += '*';
		else
			answer += phone_number.at(i);
	}

	return answer;
}