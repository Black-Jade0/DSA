#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *merge(ListNode *first, ListNode *second)
    {
        if (!first)
            return second; 
        if (!second)
            return first; 

        ListNode *dummy = first->val <= second->val ? first : second;
        ListNode *prev = nullptr;

        if (dummy == second)
        {
            ListNode *temp = first;
            first = second;
            second = temp;
        }

        prev = dummy;
        first = first->next;

        while (first && second)
        {
            if (first->val > second->val)
            {
                prev->next = second;
                second = second->next;
                prev = prev->next;
                prev->next = first; 
            }
            else
            {
                prev = first;
                first = first->next;
            }
        }

        if (second)
        {
            prev->next = second;
        }

        return dummy;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};

//  LEETCODES TOP: USING PRIORITY QUE

// class Solution
// {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         if (lists.empty())
//         {
//             return nullptr;
//         }

//         priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

//         for (int i = 0; i < lists.size(); i++)
//         {
//             if (lists[i] == nullptr)
//             {
//                 continue;
//             }
//             pq.push({lists[i]->val, lists[i]});
//         }
//         ListNode *dn = new ListNode(-1);
//         ListNode *t1 = dn;
//         while (!pq.empty())
//         {
//             auto p = pq.top();
//             pq.pop();
//             if (p.second->next)
//             {
//                 pq.push({p.second->next->val, p.second->next});
//             }
//             t1->next = p.second;
//             t1 = t1->next;
//         }
//         return dn->next;
//     }
// };

int main()
{
    // Your code goes here

    return 0;
}