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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *new_head = head;
        while (new_head && new_head->val >= x)
        {
            new_head = new_head->next;
        }
        if (!new_head)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *insert_low = new ListNode(0, head);
        ListNode *prev = insert_low;
        while (temp)
        {
            if (temp->val >= x)
            {
                prev = temp;
                temp = temp->next;
            }
            else
            {
                if (temp != insert_low->next)
                {
                    prev->next = temp->next;
                    ListNode *help = insert_low->next;
                    insert_low->next = temp;
                    temp->next = help;
                    insert_low = temp;
                    temp = prev->next;
                }
                else
                {
                    insert_low = temp;
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
        return new_head;
    }
};

int main()
{
    // Your code goes here

    return 0;
}