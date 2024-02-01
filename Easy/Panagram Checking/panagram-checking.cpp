//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
 string convertToLowercaseToUppercase(const string& input) {
    string result = input;

    for (char& c : result) {
        if (islower(c)) {
            c = toupper(c);
        }
    }

    return result;
}

bool checkPangram(string s) {
     bool check[26];
        fill(check,check+26,0);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                check[s[i]-'a']=1;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                check[s[i]-'A']=1;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(check[i]==0)
            {
                return 0;
            }
        }
        return 1;
}

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends