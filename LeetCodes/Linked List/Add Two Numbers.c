#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int len(int x)
{
    int a = 0;
    if (x == 0)
    {
        return 1;
    }
    while (x != 0)
    {
        x = x / 10;
        a++;
    }
    return a;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int num1 = 0;
    int num2 = 0;

    int carry = 0;

    int sum = 0;
    int digit = 0;

    struct ListNode *result = NULL;
    struct ListNode *temp = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        if (l1 != NULL)
        {
            num1 = l1->val;
            l1 = l1->next;
        }
        else
        {
            num1 = 0;
        }
        if (l2 != NULL)
        {
            num2 = l2->val;
            l2 = l2->next;
        }
        else
        {
            num2 = 0;
        }

        sum = num1 + num2 + carry;

        digit = sum - ((sum / 10) * 10);
        carry = sum / 10;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;

        if (result == NULL)
        {
            result = newNode;
            temp = result;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return result;
}

void linkedlistTraversal(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d \n", ptr->val);
        ptr = ptr->next;
    }
}

int main()
{

    struct ListNode *head;
    struct ListNode *second;
    struct ListNode *third;
    struct ListNode *fourth;

    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    second = (struct ListNode *)malloc(sizeof(struct ListNode));
    third = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->val = 1;
    second->val = 2;
    third->val = 3;
    fourth->val = 4;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    struct ListNode *head2;
    struct ListNode *second2;
    struct ListNode *third2;
    struct ListNode *fourth2;
    struct ListNode *fifth2;

    head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    second2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    third2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    fifth2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    head2->val = 1;
    second2->val = 2;
    third2->val = 3;
    fourth2->val = 4;
    fifth2->val = 5;

    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = fifth2;
    fifth2->next = NULL;

    struct ListNode *suml = addTwoNumbers(head, head2);
    linkedlistTraversal(suml);
    return 0;
}