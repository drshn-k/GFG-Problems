//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
          int num = 0,sign = 1,ind=0;
        if(s[0] == '-') ind++,sign = -1;
        
        while(ind < s.size()){
            if(s[ind]>='0' && s[ind] <= '9')
                num = num*10 + s[ind++]-'0';
            else
                return -1;
        }
        
        return sign*num;  //Your code here
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends