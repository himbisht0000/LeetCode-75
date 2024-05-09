/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current,*next,*temp;
        if(head == NULL)
        return head;

        current = NULL;
        next = head;

        while(next!=NULL)
        {
            temp = next->next;
            next->next = current;

            current = next;
            next = temp;
        }

        return current;
    }
};
