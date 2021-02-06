#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto courses : prerequisites)
        {
            indegree[courses[0]]++;
            graph[courses[1]].push_back(courses[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        if (q.empty())
            return false;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            for (int nextCourse : graph[course])
            {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0)
                    q.push(nextCourse);
            }
        }
        for (auto i : indegree)
            if (i != 0)
                return false;
        return true;
    }
};

int main()
{
    int numCourses;
    cin >> numCourses;
    vector<vector<int>> prequisites;
    int dependencies;
    cin >> dependencies;
    while (dependencies--)
    {
        int u, v;
        cin >> u >> v;
        prequisites.push_back({u, v});
    }
    cout << Solution().canFinish(numCourses, prequisites);
}