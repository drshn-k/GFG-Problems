//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   int removeStudents(int H[], int N) {
        vector<int>ans;
        for(int i=0;i<N;++i){
            int it =lower_bound(ans.begin(),ans.end(),H[i])-ans.begin();
            if(it==ans.size()){
                ans.push_back(H[i]);
            }
            else 
            ans[it]=H[i];
    }
    return N-ans.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends