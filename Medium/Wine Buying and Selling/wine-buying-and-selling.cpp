//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      //Code here.
      
      int buy = 0 ;
      int sell = 0 ;
      long long int ans = 0 ;
      int m = 1e9 + 7;
      
      while(buy < N and sell < N){
          
          while(Arr[buy] <= 0){
              buy++;
              if(buy == N) return ans;
          }
          while(Arr[sell] >= 0){
              sell++;
              if(sell == N) return ans;
          }
          
          if(Arr[buy] >= abs(Arr[sell])){
              int x = (abs(buy - sell)%m* abs(Arr[sell])%m)%m;
              ans = ans + x;
              Arr[buy] = abs(Arr[buy] + Arr[sell]);
              Arr[sell] = 0;
              
          }
          
          if(Arr[buy] < abs(Arr[sell])){
              int x = (abs(buy - sell)%m* abs(Arr[buy])%m)%m;
              ans = ans + x;
              Arr[sell] = Arr[buy] + Arr[sell];
              Arr[buy] = 0;
          }
          
          
          }
          
          return ans;
          
          
      }
  
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends