//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
    
        if (k == 0) return q;
        vector<int>arr;
        queue<int> answer;
        int m = k;
        while (!q.empty() && k > 0){
            arr.push_back(q.front());
            q.pop();
            k--;
        }
        reverse(arr.begin(),arr.end());
        for (int i = 0; i < arr.size(); i++){
            answer.push(arr[i]);
        }
        while (!q.empty()){
            answer.push(q.front());
            q.pop();
        }
        return answer;  // add code here.
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends