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

    // Traverse the linked list until fast is at NULL or last node
    while( fast != NULL && fast->next != NULL )
    {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    
    //update the link of node before middle node
    prev->next = slow->next;
    // if linked list has single element then
    if(slow == head)
    {
        head = NULL;
    }
    delete slow;
    
    //Tc: O(N) N is the number of nodes in linked list
    return head;
    
    }
};
