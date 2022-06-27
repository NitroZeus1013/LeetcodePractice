/*
 * //Two Stack solution implemented using vector.
class MinStack {
    // int mx = INT_MAX;
    vector<int>minInd;

    vector<int>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.size() == 0){
            minInd.push_back(val);
        }else{
            
        minInd.push_back(min(minInd.back(),val));
        }
        st.push_back(val);
    }
    
    void pop() {
  

        st.pop_back();
        minInd.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        
        return minInd.back();
    }
};
*/


// little bit optimized solution
class Node{
 public:
  int mn;
  int val;
 
  Node* next  = nullptr;
    
    Node(int val, int mn,Node* next){
        this->val =val;
        this->mn = mn;
        this->next = next;
    }
    
};
class MinStack {
    Node* head ;
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if(!head){
            head = new Node(val,val,nullptr);
        }else{
            head = new Node(val,min(head->mn,val),head);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->mn;
    }
};
