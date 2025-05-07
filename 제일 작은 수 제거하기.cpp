#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	
	arr.erase(min_element(arr.begin(), arr.end()));
	if (arr.empty())
		arr.push_back(-1);

	return arr;
}

int main()
{
	vector<int> arr = { 1,0,2,5,4};
	vector<int> ans = solution(arr);
	for (auto& iter : ans)
		cout << iter << endl;
}