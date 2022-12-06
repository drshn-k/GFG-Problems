//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	     if(grid.size()==0)
            return grid;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,INT_MAX-100000));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)
                    v[i][j] = 0;
                else{
                    if(i>0)
                        v[i][j] = min(v[i][j], v[i-1][j]+1);
                    if(j>0)
                        v[i][j] = min(v[i][j], v[i][j-1]+1);
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i<n-1)
                    v[i][j] = min(v[i][j], v[i+1][j]+1);
                if(j<m-1)
                    v[i][j] = min(v[i][j], v[i][j+1]+1);
            }
        }
        return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends