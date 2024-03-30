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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* current_node = NULL;
        ListNode* prev_node = NULL;
        ListNode* new_ll_head = NULL;
        ListNode* new_ll_tail = NULL;

        if(head == NULL)
        return NULL;
        
        prev_node = head;
        current_node = head->next;
        while(current_node != NULL )
        {   
            prev_node->next = current_node->next;
            if(new_ll_head == NULL)
            {
                current_node->next = NULL;
                new_ll_head = new_ll_tail = current_node;
    
            }
            else
            {
                current_node->next = NULL;
                new_ll_tail->next = current_node;
                new_ll_tail = current_node;
            }
            if(prev_node->next == NULL )
            {
                current_node = NULL;
                continue;
            }
            else
            {
                prev_node = prev_node->next;
            }
            if(prev_node->next == NULL)
            current_node = NULL;
            else
            current_node = prev_node->next;
            
        }
        prev_node->next = new_ll_head;

        return head;
    }
};
