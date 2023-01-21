//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {

        // code here

        int y=__builtin_popcount(b);

        int z=__builtin_popcount(a);

        int sub=abs(y-z);

        if(sub==0){

            return a;

            

        }

        else if(z>y){

            while(sub>0){

                a=a&(a-1);

                sub--;

            }

            

        }

        else{

            while(sub>0){

                a=a|(a+1);

                sub--;

            }

        }

        return a;

        

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends