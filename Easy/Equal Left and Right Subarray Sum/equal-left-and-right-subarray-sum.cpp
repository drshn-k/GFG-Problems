//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int n, vector<int> &A) {
        // code here
        
        vector<int> pre , suf;
        
        int sum = A[0];
        pre.push_back(sum);
        for(int i = 1 ; i < n ; i++ ){
            
            sum = sum + A[i];
             pre.push_back(sum);
            
        }
        sum = A[n-1];
        suf.push_back(sum);
        for(int i = n-2 ; i >= 0 ; i-- ){
            
            sum = sum + A[i];
             suf.push_back(sum);
            
        }
        
        reverse(suf.begin() , suf.end());
        for(int i = 0 ;i < n ; i++){
            if(pre[i] == suf[i])return i+1;
        }
        
return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends