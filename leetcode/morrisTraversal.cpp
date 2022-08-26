/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        TreeNode* currNode = root;
        // try while currNode is not null
        while(root){
            // if currNode has left that means we can find it's predecessor and attach it to currNode.
            // it is necessary to return to currNode from left subtree.
            if(root->left){
                TreeNode* predec = root->left;
                // to find predecessor first go left one step and then go to right as much as possible .
                // but if you've the link to currNode already you'll get stuck in infinite loop so check for that.
                while(predec->right and predec->right!=root){
                    predec = predec->right;
                }
                // if you've already connected predecessor store the ans disconnect it this means entire left subtree is done and we are on currNode and now we'll move to right of currNode.
                // if currNode is not connected to predecessor then just connect it and move to left as in inorder traversal;
                if(predec->right == nullptr){
                     predec->right = root;
                    root = root->left;
                }else{
                    ans.push_back(root->val);
                    predec->right = nullptr;
                    root = root->right;
                }
            }else{
                // if no left for currNode that means we can now add it to result and move to right subtree.
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};
