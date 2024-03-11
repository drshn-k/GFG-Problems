//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{ int n;
public:	
	bool search(vector<vector<int>>&mat,int val){
	    int i=0;
	    int j=n-1;
	    while(i<n and j>=0){
	        if(mat[i][j]==val) return 1;
	        else if(mat[i][j]<val) i++;
	        else j--;
	    }
	    return 0;
	}
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int size, int x)
	{
	    n=size;
	   // cout << search(mat2,1) << endl;
	   int count=0;
	   for(auto i:mat1){
	       for(auto j:i){
	           if(search(mat2,x-j)) count++;
	       }
	   }
	    return count;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends