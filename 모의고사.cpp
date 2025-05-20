#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<int> stu1 = { 1,2,3,4,5 };
	vector<int> stu2 = { 2,1,2,3,2,4,2,5 };
	vector<int> stu3 = { 3,3,1,1,2,2,4,4,5,5 };

	vector<int> StuCntVec = { 0,0,0 };

	for (int i = 0; i < answers.size(); ++i)
	{
		int stu1Index = i % stu1.size();
		int stu2Index = i % stu2.size();
		int stu3Index = i % stu3.size();

		if (stu1[stu1Index] == answers[i])
			StuCntVec[0]++;
		if (stu2[stu2Index] == answers[i])
			StuCntVec[1]++;
		if (stu3[stu3Index] == answers[i])
			StuCntVec[2]++;
	}

	int max = *max_element(StuCntVec.begin(), StuCntVec.end());

	for (int i = 0; i < StuCntVec.size(); ++i)
	{
		if (StuCntVec[i] == max)
			answer.push_back(i + 1);
	}

	return answer;
}