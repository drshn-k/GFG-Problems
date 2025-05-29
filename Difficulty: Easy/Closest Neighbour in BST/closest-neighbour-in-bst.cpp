/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
 int help(Node* root,int& x)
    {
        //base case
        if(!root)
        return 0;
        
        //recursive calls
        //and small calculation
        if(root->data==x)
        return x;
        
        int a;
        if(root->data<x)
        a=help(root->right,x);
        else
        a=help(root->left,x);
        
        if(max(root->data,a)<=x)
        return max(root->data,a);
        else
        return min(root->data,a);
    }
    int findMaxFork(Node* root, int n) {
        int ans=help(root,n);
        return ans==0 ? -1:ans;
    }
};