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
    ListNode* reversed;
    ListNode* reverse_ll(ListNode* head)
    {
        ListNode* n1;
        if(head == NULL)
        return NULL;

        if(head->next == NULL)
        {
            reversed = head;
            return head;
        }
        n1 = reverse_ll(head->next);
        n1->next = head;
        head->next = NULL;
        return head;
    }
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int size_of_ll = 0;
        int sum = 0;
        while(temp)
        {
            temp = temp->next;
            size_of_ll++;
        }
        temp = head;
        for(int i = 1 ; i < (size_of_ll/2) ; i++)
        {
            temp = temp->next;
        }

        reverse_ll(temp->next);
        temp->next = NULL;

        temp = head;
        while(temp)
        {
            sum =  max(sum , temp->val + reversed->val);
            temp = temp->next;
            reversed = reversed->next;
        }

        return sum;
    }
};
