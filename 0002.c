#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * 
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *temp = l1;
    int nextValue = 0;
    int t;
    for (;;)
    {
        t = temp->val + nextValue;
        if (l2 != NULL)
            t += l2->val;
        nextValue = t / 10;
        t = t % 10;
        temp->val = t;
        if (temp->next == NULL && l2 != NULL)
        {
            temp->next = l2->next;
            l2->next = NULL;
        }
        if (temp->next == NULL)
        {
            if (nextValue > 0)
            {
                temp->next = malloc(sizeof(struct ListNode));
                temp->next->val = nextValue;
                temp->next->next = NULL;
            }
            break;
        }
        else
        {
            temp = temp->next;
        }
        if (l2 != NULL)
            l2 = l2->next;
    }
    return l1;
}