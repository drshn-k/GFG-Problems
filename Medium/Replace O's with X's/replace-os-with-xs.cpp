//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int delta[5] = {-1,0,+1,0,-1};
    void dfs(int row,int col,vector<vector<char>> &mat){
        int n = mat.size() , m = mat[0].size();
        mat[row][col] = '#';
        for(int d=0;d<4;d++){
            int nRow = row + delta[d];
            int nCol = col + delta[d+1];
            if(min(nRow,nCol) >= 0 && nRow < n && nCol < m && mat[nRow][nCol] == 'O')
                dfs(nRow,nCol,mat);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        for(int row=0;row<n;row++){
            for(int col : {0,m-1}){
                if(mat[row][col] == 'O') dfs(row,col,mat);
            }
        }
        for(int col=0;col<m;col++){
            for(int row : {0,n-1}){
                if(mat[row][col] == 'O') dfs(row,col,mat);
            }
        }
        for(int row=0;row<n;row++)
            for(int col=0;col<m;col++) 
                if(mat[row][col] == 'O') mat[row][col] = 'X';
                else if(mat[row][col] == '#') mat[row][col] = 'O';
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends