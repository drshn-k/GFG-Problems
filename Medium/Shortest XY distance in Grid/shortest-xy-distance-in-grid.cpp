//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        // code here
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='X'){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int res=1e9;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m
                    && grid[nx][ny]!='X' && dist[nx][ny]>dist[x][y]+1){
                        
                        dist[nx][ny]=dist[x][y]+1;
                        q.push({nx,ny});
                        if(grid[nx][ny]=='Y')
                            res=min(res,dist[nx][ny]);
                    }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends