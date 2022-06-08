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
    ListNode* removeElements(ListNode* head, int val) {

        if(!head)return nullptr;
        
        ListNode* temp = removeElements(head->next,val);
        if(head->val == val)return temp;
        head->next = temp;
        return head;
 /*
  * In while loop we are checking like we're standing on a node and cheking if the next node has value == val . 
  * If the value == val we bypass that node and we don't move ahead because if the next node after bypassing has the value == val then we've bypass that node also
  * if the value != val then we move ahead.
  * And as we've never checked for head's value at last we do that check
  *
  *
  */       
//         ListNode* newHead = head;
//         if(!head)return head;
//         while(head->next!=nullptr){
//             if(head->next->val == val){
//                 head->next= head->next->next;
//             }
        
//             else{
                
//                 head=head->next;
//             }
            
//         }
//        if(newHead->val==val)
//            newHead = newHead->next;
        
//         return newHead;
    }
};
