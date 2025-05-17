#include <string>
#include <vector>
#include<algorithm>

using namespace std;
void CheckPronounce(string& str, const string& target)
{
	auto TargetIter = search(str.begin(), str.end(), target.begin(), target.end());

	if (TargetIter == str.end())
		return;

	if (str.end() != TargetIter)
	{
		str.replace(TargetIter, TargetIter + target.size(), "@");

		CheckPronounce(str, target);
	}
}

int solution(vector<string> babbling) {
	int answer = 0;

	for (string ele : babbling)
	{
		CheckPronounce(ele, "aya");
		CheckPronounce(ele, "ye");
		CheckPronounce(ele, "woo");
		CheckPronounce(ele, "ma");

		int cnt = 0;
		for (auto e : ele)
		{
			if (e == '@')
				cnt++;
		}

		if (cnt == ele.size())
			answer++;

	}
	return answer;
}