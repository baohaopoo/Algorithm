#include <string>
#include <vector>
#include <iostream>
using namespace std;
void SortPlayersByTarget(vector<string>& players, string& Target)
{
    for (int i = 0; i < players.size(); ++i)
    {
        if (players[i] == Target)
        {
            if (i > 0)
            {
                swap(players[i], players[i - 1]);
            }
        }
    }
}
vector<string> solution(vector<string> players, vector<string> callings) {

    //swap 정렬 
    //Players를 정렬한다.
    for (string ele : callings)
    {
        SortPlayersByTarget(players, ele);
    }

    return players;
}