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
    ListNode* deleteMiddle(ListNode* head) {
    // using fast and slow pointer we can implement this
    ListNode* fast = NULL;
    ListNode* slow = NULL;
    ListNode* prev = NULL;
    prev = fast = slow = head;

    while( fast != NULL && fast->next != NULL )
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    prev->next = slow->next;
    // if linked list has single element then
    if(slow == head)
    {
        head = NULL;
    }
    delete slow;
    
    return head;
    
    }
};
