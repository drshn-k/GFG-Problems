//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solve(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&visited, int drow, int dcol, int N, int M){
      visited[i][j]=1;
      int dr[] = {0, 0, -1, 1};  //l, r, u, d
      int dc[]={-1, 1, 0, 0};
      queue<pair<int, pair<int, int>>>q;
      q.push({0,{i, j}});       //distance, row, col
      while(q.empty()==false){
          auto it =q.front();
          int d = it.first;
         q.pop();

          if(it.second.first== drow && it.second.second==dcol)return it.first;
          
          for(int k=0;k<4;k++){
              int row = it.second.first + dr[k];
              int col = it.second.second + dc[k];
              if(row>=0 && row<N && col>=0 && col<M && !visited[row][col] && mat[row][col]){
                  q.push({d+1, {row, col}});
                  visited[row][col]=1;
              }
          }
          
          
      }
      return -1;
      
  }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)return -1;
        vector<vector<int>>visited(N, vector<int>(M, 0));
        
        return solve(0, 0, A, visited, X, Y,N, M);
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends