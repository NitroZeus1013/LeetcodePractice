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
