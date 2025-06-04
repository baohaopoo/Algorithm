#include <string>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& computers, vector<bool>& visited)
{
    for (int i = 0; i < computers[node].size(); ++i)
    {
        if (!visited[node] && !visited[i])
        {
            if (computers[node][i] == 1)
                visited[i] = true;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, computers, visited);
            answer++;
        }
    }

    return answer;
}