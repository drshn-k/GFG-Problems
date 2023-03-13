//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {

        // code here

        // Decrease the number of Sticks by one if its ODD

        // Reason, we cannot use odd sticks anywhere

        for (int i=0;i<N;i++) {

            if (B[i]%2 != 0)

                B[i] = B[i]-1;

        }

        long long mini = INT_MAX; // Maintain that stick which has least value

        long long sum=0; // Calculate the remaining sum

        long long count=0; // Calculate total count

        for (int i=0;i<N;i++) {

            count += B[i];

            sum += A[i]*B[i];

            if (B[i] != 0) {

                mini = min((long long)A[i],mini); // While subtracting, there is a possiblity that 

                                                 // stick having minimum value has count as "1" and 

                                                 // that decreases to zero, So it will calculate 2nd minimum automatically

            }

        }

        if (count%4 == 2) {

            sum = sum-2*mini; // Decrease the minimum stick value from the total and there is the answer.

        }

        return sum;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends