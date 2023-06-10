//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {  queue<int>pos;
            queue<int>neg;
            for(int i=0;i<n;i++){
                if(arr[i]<0)
                neg.push(arr[i]);
                else
                pos.push(arr[i]);
            }
            int k=0;
            while(!neg.empty()){
                arr[k]=neg.front();
                neg.pop();
                k++;
            }
             while(!pos.empty()){
                arr[k]=pos.front();
                pos.pop();
                k++;
            }
            // Your code goes here
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends