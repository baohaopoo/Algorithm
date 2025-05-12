#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;

	vector<int> HorizonVec;
	vector<int> VerticalVec;

	for (int i = 0; i < sizes.size(); ++i)
	{
		HorizonVec.push_back(sizes[i][0]);
		VerticalVec.push_back(sizes[i][1]);
	}

	int HorizonMax = *max_element(HorizonVec.begin(), HorizonVec.end());
	int VecticalMax = *max_element(VerticalVec.begin(), VerticalVec.end());


	if (HorizonMax >= VecticalMax)
	{

		VerticalVec.erase(std::remove(VerticalVec.begin(), VerticalVec.end(), VecticalMax));
		VecticalMax = *max_element(VerticalVec.begin(), VerticalVec.end());
	}
	else
	{
		HorizonVec.erase(std::remove(HorizonVec.begin(), HorizonVec.end(), HorizonMax));
		HorizonMax = *max_element(HorizonVec.begin(), HorizonVec.end());
	}

	cout << HorizonMax << "," << VecticalMax;

	answer = HorizonMax * VecticalMax;
	return answer;
}