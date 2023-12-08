//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
             int result=0;
       int data=0;
       for(int i=0;i<N;i++)
        data+=arr[i];
        if(data==1) return 1;
       
       for(int i=2;i<=(data+result)/2;i++){
         if((data+result)%i==0){
             result++;
             i=2;
          }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends