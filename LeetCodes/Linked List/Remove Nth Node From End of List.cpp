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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int size = 0;
        while (temp)
        {
            size++;
            temp = temp->next;
        }
        if (size == 1)
        {
            return NULL;
        }
        if (n == size)
        {
            return head->next;
        }
        temp = head;
        int i = 1;
        while (i < size - n)
        {
            temp = temp->next;
            i++;
        }
        ListNode *deleted = temp->next;
        temp->next = deleted->next;
        delete deleted;
        return head;
    }
};

int main()
{
    // Your code goes here

    return 0;
}