//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    // Your code goes here
    int l=0,r = len-1;
    long long CurrArea= r*min(A[l],A[r]);
    long long ans=CurrArea;
    while(l<=r){
        CurrArea=(r-l)*min(A[l],A[r]);
        ans=max(ans,CurrArea);
        if(A[l]<A[r]) l++;
        else r--;
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends