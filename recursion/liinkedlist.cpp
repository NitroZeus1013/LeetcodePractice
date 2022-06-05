
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
    ListNode* swapNodes(ListNode* head, int k) {
         head = new ListNode(-1,head);
        ListNode *prev1 = head, *prev2 = head, *curr = head;
            
        while(--k){
            prev1 = prev1->next;
            curr = curr->next;
        }
        
        curr = curr->next;
        
        while(curr->next){
        
            prev2 = prev2->next;
            curr= curr->next ;
        
        }
        cout<<prev1->val<<" "<<prev2->val;
        
        if(prev2->next == prev1){
   

            
            return head->next;
            
        }
        
      
        curr = prev1->next;
        prev1->next = prev2->next;
        prev2->next = curr;
        curr = prev1->next->next;
        prev1->next->next = prev2;
        prev2->next->next= curr;
        
        return head->next;
        
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head){
        
        if(head == nullptr)return head;
        
        while(head->next){
            
            if(head->child!=nullptr){
                Node* nextHead = head->next;
                
                Node* end = solve(head->child); 
                
                head->next = head->child;
                head->child->prev = head;
                
                end->next = nextHead;
                nextHead->prev = end;
                
                head->child = nullptr;
                head =  nextHead;
               
            }else
            {
                head = head->next;  
                
            }
          
        }
        
        if(head->child){
            Node* temp = solve(head->child);
            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;
        }        
        return head;
    }
   
    
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};