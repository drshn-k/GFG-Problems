//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
            int n = matrix.size(), len = 2*n-1, index = 0;
        vector<int> antiDiagonalPatternMatrix(n*n);
        for(int col=0; col<len; col++) {
            int start = (col<n? 0 : col-n+1), end = (col<n ? col+1 : n);
            for(int row=start; row<end; row++) {
                antiDiagonalPatternMatrix[index++] = matrix[row][col-row];
            }
        }
        return antiDiagonalPatternMatrix; // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends