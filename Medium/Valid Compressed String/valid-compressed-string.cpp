//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

  public:

    int checkCompressed(string S, string T) {

        int n=T.size();

        int i=0,d=0,c=0;

        while(i<n){

            if(T[i]=='0'){

                i++;

                continue;

            }

            else if(isdigit(T[i])){

                long long int g=0;

                while(isdigit(T[i])){

                    g=g*10+(T[i]-'0');

                    i++;

                }

                d=c+g;

                if(S[d]!=T[i]){

                   return 0; 

                }

                c=d;

            }else{

                c++;

                i++;

            }

        }

        return (c==S.size());

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends