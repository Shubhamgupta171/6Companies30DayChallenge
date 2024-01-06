//Postorder traversal 
class BST {
public:
    int sum;
    int mini;
    int maxi;
    BST(int sum=0,int mini=INT_MAX,int maxi=INT_MIN) {
        this->sum=sum;
        this->mini=mini;
        this->maxi=maxi;
    }
};
int ans=0;
BST helper(TreeNode *root) {
    if(!root)
        return BST(0,INT_MAX,INT_MIN);
    auto lt=helper(root->left);
    auto rt=helper(root->right);
    if(root->val>lt.maxi && root->val<rt.mini){
        int sum=root->val+lt.sum+rt.sum;
        ans=max(ans,sum);
        return BST(sum,min(root->val,lt.mini),max(root->val,rt.maxi));
    }
       return BST(max(lt.sum,rt.sum),INT_MIN,INT_MAX);
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        ans=0;
        helper(root);
        return ans;
    }
};
