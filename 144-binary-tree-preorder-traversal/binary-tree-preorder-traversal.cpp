class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;

       TreeNode* curr= root;

       while(curr){
        if(curr->left){
            TreeNode* prev = curr->left;

            while(prev->right && prev->right != curr){
                prev=prev->right;
            }

            if(!prev->right){
                ans.push_back(curr->val);
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }

        }
        else{
            ans.push_back(curr->val);
            curr=curr->right;
        }
       } 
       return ans;
    }
};