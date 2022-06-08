/**
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
 * First initialize the odd and even head and keep a copy of even head as we've to attach it to last node of odd .
 *
 * Now we know that the next to next index of odd is odd and next to next index of even is also even.
 *
 * So we just loop till even != nullptr and even->next!=nullptr
 * At last we attach even's head to odds last node and return head as it still is the starting of list. And we've not changed it in any way.
 *
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
         if(!head)return nullptr;
      
   
        ListNode* od = head;
        ListNode* ev = head->next;
        ListNode* even = head->next;
       
        
        while(ev!=NULL and od!= NULL and ev->next!=nullptr and od->next!=nullptr){
                od->next =od->next->next;
                ev->next = ev->next->next;
                od = od->next ;
                ev = ev->next;
        }
        
        od->next = even;
        
        return head;
    }
};
