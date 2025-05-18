#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

	//swap 정렬 
	//Players를 정렬한다.
	//calling에서 value값이 players 몇번째 문자열인지  찾아냄.

	for (int i = 0; i < callings.size(); ++i)
	{
		auto iter = find(players.begin(), players.end(), callings[i]);
		iter_swap(iter, iter - 1);
	}

	return players;
}

//버전 투 도 시간초과남.