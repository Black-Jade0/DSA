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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
        {
            return head;
        }
        int rounds = 0;
        ListNode *temp = head;
        ListNode *result_head = NULL;
        while (rounds < k - 1)
        {
            temp = temp->next;
            rounds++;
        }
        result_head = temp;
        temp = head;
        rounds = 0;
        while (temp)
        {
            temp = temp->next;
            rounds++;
        }
        rounds = rounds / k;
        temp = head;
        ListNode *helper = new ListNode(0, head);
        for (size_t i = 0; i < rounds; i++)
        {
            for (size_t j = 0; j < k - 1; j++)
            {
                ListNode *forward = temp->next;
                temp->next = forward->next;
                forward->next = helper->next;
                helper->next = forward;
            }
            helper = temp;
            temp = temp->next;
        }
        return result_head;
    }
};

// BONITA

int main()
{
    // Your code goes here

    return 0;
}