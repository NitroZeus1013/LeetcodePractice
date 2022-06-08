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

/*
 * Get the middle of the linked list (first middle in case of even length) 
 * reverse the second half of the linked list and attach it to next of the middle(i.e. last node of 1st half)          
 * Travse the list from original head and the middle's next (i.e 1st node of 2nd part)
 *
 *            
 */
class Solution {
public:
    ListNode* reverse(ListNode* ll){
        ListNode* prev = nullptr;
        ListNode* nextNode =nullptr ;
        ListNode* temp = ll;
        while(temp!=nullptr){
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        // when both are true then only move;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next= reverse(slow->next);
        slow = slow->next;
        
        ListNode* Head = head;
        while(slow!=nullptr && Head!=nullptr){
            if(Head->val != slow->val)return false;
            Head = Head->next;
            slow=slow->next;
            
        }
      return true;
    }
};
