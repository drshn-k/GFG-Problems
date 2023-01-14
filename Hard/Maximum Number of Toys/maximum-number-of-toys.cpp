//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      // code here
      vector<vector<int>> arr(N);
      
      for(int i=0; i<N; i++){
          arr[i] = {A[i],i};
      }
      sort(arr.begin(),arr.end());
      multimap<int,int> mpp;
      vector<long long> nums(N);
      long long sum = 0;
      for(int i=0; i<N; i++){
          sum += arr[i][0];
          nums[i] = sum;
          mpp.insert({arr[i][0],i});
      }

      vector<int> ans(Q);
      for(int i=0; i<Q; i++){
          vector<int> temp = Queries[i];
          int amount = temp[0];
          if(amount < nums[0]){
              ans[i] = 0;
              continue;
          }
          int idx = lower_bound(nums.begin(),nums.end(),amount) - nums.begin();
          if(idx == N or nums[idx] != amount){
              idx--;
              amount = nums[idx];
          }
        //   cout<<idx<<"AKLS"<<endl;
          int cnt = idx+1;
          unordered_set<int> st;
          if(temp[1] != 0){
              for(int j=2; j<temp.size(); j++){
                  --temp[j];
                  auto it = mpp.find(A[temp[j]]);
                  if(it->second > idx){
                    //   cout<<temp[j]<<"aksal"<<endl;
                      st.insert(temp[j]);
                  }
                  else{
                    //   cout<<A[temp[j]]<<"ASKLLA"<<endl;
                      amount -= A[temp[j]];
                      cnt--;
                  }
              }
          }
          
          idx++;
          while(idx < N and amount + arr[idx][0] <= temp[0]){
            //   cout<<amount<<idx<<arr[idx][1]<<endl;
              if(st.find(arr[idx][1]) == st.end()){
                  amount += arr[idx][0];
                  cnt++;
              }
              idx++;
          }
        //   cout<<cnt<<endl;
          ans[i] = cnt;
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends