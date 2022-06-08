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
 *Here we're trying to maintain a distance of n between slow and fast . As when fast reaches to end slow will be n steps behind fast and then we'll delete the node. If the distance between fast and slow exceeds n. we will maintain it by moving slow forward.
 * 				
 *
 *
 *
 *
 *
 *
 * 
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = n;
        // if(head->next == nullptr)return nullptr;
        // n++;
        ListNode* fast= head;
        ListNode* slow = head;
        int len = 1;
        int distance = 0 ;
        while(fast->next!=nullptr){
             // if(n>0)n--;
            // n--;
            distance++;
            len++;
            fast = fast->next;
           
//             if(n < 0){
//                 slow = slow->next;
//             }
            
            if(distance > n){
                slow = slow->next;
                distance--;
            }
           
        }
      
        if(len == k and slow == head ){
            head = head->next;
        }else{
            
        slow->next = slow->next->next;
        }
        
        return head;
    }
};
