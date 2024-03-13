//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<int> ans;
         int sum = 0;
         int n = mat.size();
         while(sum<=2*(n-1)){
            if(sum%2==0){
                int i = min(sum,n-1);
                int j = sum - i;
                while(i>-1 && j<n){
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }else{
                int j = min(sum,n-1);
                int i = sum - j;
                while(i<n && j>-1){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
            sum++;
         }
         return ans;  //Your code here
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends