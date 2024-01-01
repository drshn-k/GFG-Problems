//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
          if (nums.size() % 2)
            return false; 
        unordered_map<int, int> mp; 
        for(auto &x: nums){
            if (mp[(k - x % k) % k] > 0){
                mp[(k - x % k) % k]--; 
            }
            else{
                mp[x % k]++; 
            }
        }
        for(auto &x: mp){
            if (x.second > 0)
                return false; 
        }
        return true;  // Code here.
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends