#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";

	for (int i = 0; i < seoul.size(); ++i)
	{
		if (seoul.at(i) == "Kim")
		{
			answer += "�輭���� ";
			answer += to_string(i);
			answer += "�� �ִ�";
			return answer;
		}
	}
	return answer;
}