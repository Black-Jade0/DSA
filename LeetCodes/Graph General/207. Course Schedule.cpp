#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

// class Solution
// {
// public:
//     set<int> not_done;
//     set<int> done;
//     unordered_map<int, vector<int>> unlock;
//     bool dfs(int a, int &n)
//     {
//         if (n == done.size())
//         {
//             return true;
//         }
//         for (size_t i = 0; i < unlock[a].size(); i++)
//         {
//             done.insert(unlock[a][i]);
//             if (dfs(unlock[a][i], n))
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         if (prerequisites.size() == 0)
//         {
//             return true;
//         }
//         for (size_t i = 0; i < prerequisites.size(); i++)
//         {
//             not_done.insert(prerequisites[i][0]);
//             unlock[prerequisites[i][1]].push_back(prerequisites[i][0]);
//         }
//         for (size_t i = 0; i < numCourses; i++)
//         {
//             if (not_done.find(i) == not_done.end())
//             {
//                 done.insert(i);
//             }
//         }
//         for (int it : done)
//         {
//             if (dfs(it, numCourses))
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

//  ITS WRONG AS U ARE SEEING ........OK I DONT KNOW, JUST IT SMELLS WRONG, U CREATE AN UNORDEREMAP AND THEN HAD THE COURSES THAT U CAN DO AS KEYS
//  AND THE COURSES THAT WILL BE OPEN TO U AFTER DOING THIS COURSE BUT WHAT IF U NEED DO TO MORE THAN ONE COURSE FOR A PARTICULAR ONE

//  THATS WHY GO THE OTHER WAY AROUND, CREATE AN ARRAY OF VECTOR, WITH THE COURSE AS INDEX AND THEN A VECTOR STORING THE COURSES U NEED TO DO BEFORE THIS
//  AN INDEGREE VECTR STORING THE DEGREE OF EVERY COURSE (MEANS HOW MANY COURSES HAVE THIS COURSE AS A PREREQ) THEN DO A BFS WITH THE COURSE WITH 0 DEGREES
//  U WANT TO FIND IF THERE IS A CYCLE IN THERE
//  MANY WAYS
//  WE KEEP ON DECREMENTING THE DEGREE OF THE NODE WE VISIT, WHEN ITS 0 WE PUSH IT INTO THE QUEUE
//  IF NOT WE JUST SKIP IT
//  IN THE END IF ANS SIZE IF EQUAL TO N, MEANS WE TRAVELED ALL THE COURSES TO YUPS, NO CYCLE, HENCE TRUE!



//  COMPARING THIS APPROACH AND COURSE SCHEDULE II APPROACH:

// First Code (canFinish):
// Graph direction: We go from the course to its prerequisites.
// Each course points to the courses that must be completed before it (i.e., its prerequisites).

// Indegree meaning: The indegree array tells us how many courses this course is a prerequisite for.

// Second Code (findOrder):
// Graph direction: We go from the prerequisite to the course that can be taken after it.
// Each prerequisite points to the courses that it unlocks (i.e., the courses that can be taken after this prerequisite).

// Indegree meaning: The indegree array tells us how many prerequisites this course has.

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> ans;

        for (auto x : prerequisites)
        {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            auto t = q.front();
            ans.push_back(t);
            q.pop();

            for (auto x : adj[t])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        return ans.size() == n;
    }
};

int main()
{
    // Your code goes here

    return 0;
}