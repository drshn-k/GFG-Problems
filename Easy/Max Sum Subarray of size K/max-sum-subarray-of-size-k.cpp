//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
       int idx = 0 , jdx = 0;
        long subsum = 0; long maxim = LONG_MIN;
        while(jdx < N){
            subsum += Arr[jdx];
            if(jdx - idx + 1 < K){
                jdx++;
            }else{
                if(jdx - idx + 1 == K){
                    maxim = max(subsum,maxim);
                    subsum = subsum - Arr[idx];
                    idx++ ; jdx++;
                }
            }
            
             
        }
        return maxim; // code here 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends