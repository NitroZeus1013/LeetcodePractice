/*class Solution {
public:
    void dfs(Node* node,set<Node*>&vis,map<Node*,Node*>&mp){
        vis.insert(node);
        mp[node]=new Node(node->val);
        for(Node*n:node->neighbors){
            if(vis.find(n) == vis.end()){
                dfs(n,vis,mp);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        // base cases 
        if(!node)return node;
        if(node->neighbors.size() == 0)return new Node(1);
        set<Node*>vis;
        map<Node*,Node*>mp;
        dfs(node,vis,mp);
        for(pair<Node*,Node*>p:mp){
            for(Node* n:p.first->neighbors){
                p.second->neighbors.push_back(mp[n]);
            }
        }
        
        return mp[node];
    }
};

*/
class Solution {
public:
    void dfs(Node* node,Node*copy,vector<Node*>&vis){
        vis[node->val] = copy;
        
        for(Node*n:node->neighbors){
            if(vis[n->val] == nullptr){
                Node* temp = new Node(n->val);
                copy->neighbors.push_back(temp);
                dfs(n,temp,vis);
            }else{
                copy->neighbors.push_back(vis[n->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        // base cases 
        if(!node)return node;
        if(node->neighbors.size() == 0)return new Node(1);
        
        vector<Node*>vis(101,nullptr);
        Node* copy = new Node(node->val);
        
        dfs(node,copy,vis);
 
        return copy;
    }
};

