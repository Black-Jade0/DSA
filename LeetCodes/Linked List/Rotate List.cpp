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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *temp = head;
        int size = 0;
        ListNode *last;
        while (temp)
        {
            size++;
            last = temp;
            temp = temp->next;
        }

        if (size == 0 || size == 1 || k % size == 0)
        {
            return head;
        }
        temp = head;
        for (size_t i = 0; i < size - (k % size) - 1; i++)
        {
            temp = temp->next;
        }
        ListNode *first = temp->next;
        temp->next = NULL;
        last->next = head;
        return first;
    }
};

int main()
{
    // Your code goes here

    return 0;
}