//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
         vector<bool>isvisited(leaves+1,false); //No leaves visited yet
         int count=0;
         for(int i=0;i<N;++i){
              if(isvisited[frogs[i]]==false){ //if yet not visited
                    for(int j=frogs[i];j<=leaves;j=j+frogs[i]){  //then visit the required one
                        isvisited[j]=true;  //mark true if visited;
                    }
              }
         }
         for(int i=1;i<leaves+1;++i){
             if(isvisited[i]==false)count++; //count if not visited
         }
         return count;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends