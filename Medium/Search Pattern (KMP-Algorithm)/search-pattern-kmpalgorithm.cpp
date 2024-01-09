//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
              vector<int> ans;
            int n = txt.length();
            int m = pat.length();
            
            int j = 0 , i = 0;
            int previ = 0;
            while(i < n){
                if(txt[i] == pat[j]){
                    previ = i;
                    while(i<n && j<m && txt[i] == pat[j]){
                        j++;
                        i++;
                    }
                    if(j == m){
                        ans.push_back(previ+1);
                        i = previ + 1;
                        j = 0;
                    }
                    else{
                        j = 0;
                        i = previ + 1;
                    }
                }
                else{
                    i++;
                }
            }
            
            if(ans.size() == 0){
                ans.push_back(-1);
            }
            return ans;
              //code here
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends