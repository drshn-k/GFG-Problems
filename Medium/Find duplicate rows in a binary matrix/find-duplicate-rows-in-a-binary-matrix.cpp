//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
   class node {
    public:
    node *left;
    node *right;
    int occ;
    node() {
        left = NULL;
        right = NULL;
        occ = 0;
    }
    };

    vector<int> res;
    bool insert(vector<int> row, node *head, int n) {
        node *curr = head;
        for (int i = 0; i < n; i++) {
            if (row[i] == 0) {
                if (!curr->left) curr->left = new node();
                curr = curr->left;
            }
            else {
                if (!curr->right) curr->right = new node();
                curr = curr->right;
            }
        }
        if (curr->occ) return true;
        curr->occ = 1;
        return false;
    }
    
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        node *head = new node();
        res.clear();
        for (int i = 0; i < M; i++) {
            if (insert(matrix[i],head,N)) res.push_back(i);
        }
        return res;
    } 

 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends