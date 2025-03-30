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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast){
            slow = slow->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        while(prev){
            if(head->val != prev->val)  return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
