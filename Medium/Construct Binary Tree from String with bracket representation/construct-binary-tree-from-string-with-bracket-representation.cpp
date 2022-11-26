//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    
    Node* solve(string str, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int i = start;
        while(i <= end){
            char c = str[i];
            if(c -'0' >= 0 && c -'0' <= 9){
                i++;
            }
            else{
                break;
            }
        }
        int node = stoi(str.substr(start, i-start));
        Node* root = new Node(node);
        
        int j = i;
        stack<char> stk;
        while(j <= end){
            char c = str[j];
            if(c == ')'){
                stk.pop();
            }
            else if(c == '('){
                stk.push('(');
            }
            if(stk.empty())
                break;
            j++;
        }
        root->left = solve(str, i+1, j-1);
        if(j+2 < end){
            root->right = solve(str, j+2, end-1);
        }
        
        return root;
    }

    // function to construct tree from string
    Node *treeFromString(string str){
        if(str == "")
            return NULL;
        
        return solve(str, 0, str.length()-1);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends