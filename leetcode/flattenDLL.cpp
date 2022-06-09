/*
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
    Node* flatten(Node* head) {
        
        
    Node* temp = head;
    
        while(temp){
            
            if(temp->child){
                // Node* nextHead= temp->next;//not needed.
                Node* end  = temp->child;
                while(end->next){
                    end = end->next;    
                }
                
                //parent == temp
                //temp == child
                temp->child->prev = temp;
                end->next = temp->next;
                temp->next = temp->child;
                
                
                // end->next = nextHead;
                if(end->next)
                    end->next->prev= end;

                // temp->next = temp->child;
                // temp->child->prev = temp;
                
                
                temp->child =nullptr; //very important
                
            }
            
            else{
                temp = temp->next;
                continue;
            }
            
        }
        
        return head;
    
        
    }
};
