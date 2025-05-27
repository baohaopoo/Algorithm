#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> tmpqueue;
    for (int ele : arr)
    {
        if (tmpqueue.empty())
        {
            tmpqueue.push(ele);
            answer.push_back(ele);
        }
        else
        {
            if (tmpqueue.front() != ele)
            {
                answer.push_back(ele);
            }
            tmpqueue.pop();
            tmpqueue.push(ele);
        }

    }

    return answer;
}