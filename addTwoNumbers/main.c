#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int lenth1 = 0;
    int lenth2 = 0;
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    struct ListNode* l3 = NULL;
    l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->val = 0;
    l3->next =NULL;
    struct ListNode* count = l3;
    int i;
    int carry = 0;
    int sum = 0;
    while (1)
    {
        sum = carry;
        if(p1 != NULL) {
            sum += p1->val;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            sum += p2->val;
            p2 = p2->next;
        }
        if (sum >= 10) {
            carry = 1;
            sum -=10;
        } else {
            carry =0;
        }
        count->val = sum;
        if (p1 != NULL || p2 != NULL || carry !=0) {
            struct ListNode* nextNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            nextNode->val = 0;
            nextNode->next =NULL;
            count->next = nextNode;
            count = count->next;
        } else {
            break;
        }

    }
    return l3;

}

int main()
{
    printf("Hello world!\n");
    printf("it is a test \n");
    return 0;
}
