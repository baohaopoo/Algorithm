#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

	//swap ���� 
	//Players�� �����Ѵ�.
	//calling���� value���� players ���° ���ڿ�����  ã�Ƴ�.

	for (int i = 0; i < callings.size(); ++i)
	{
		auto iter = find(players.begin(), players.end(), callings[i]);
		iter_swap(iter, iter - 1);
	}

	return players;
}

//���� �� �� �ð��ʰ���.