//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
vector<int> findSubarray(int a[], int n) {

     // code here

     int cnt = 0;

     for(int i = 0 ; i < n ; i++){

         if(a[i]<0){

             cnt++;

         }

     }

     if(cnt == n){

         return {-1};

     }

     vector<int> ans;

     vector<pair<int,vector<int>>> temp;

     int sum = 0;

     int ans1 =0;

     for(int i = 0 ; i < n ; i++){

         if(a[i] >=0 ){

             if(sum == -1){

                 sum = 0;

             }

             sum += a[i];

             ans.push_back(a[i]);

         }else{

             if(sum >= 0){

               temp.push_back({sum,ans});

               ans.clear();

               sum = -1;

             }

         }

     }

     if(sum >= 0){

         temp.push_back({sum,ans});

         ans.clear();

     }

     sort(temp.begin(),temp.end());

     int prev = 0;

     int ps = 0;

     for(int i = temp.size() - 1 ; i >= 0 ; i--){

         int sz = temp[i].second.size();

         if(temp[i].first > ps){

             ps = temp[i].first;

             if(sz > prev){

                 ans = temp[i].second;

                 prev = sz;

             }

         }else{

             break;

         }

         

     }

     return ans;  

     

 }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends