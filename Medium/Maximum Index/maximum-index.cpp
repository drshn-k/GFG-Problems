//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int helper(vector<int>&stack, int &n, int &val, int orig[] ){
        
        int low = 0;
        int high = n-1;
        
        
        int ans = -1;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(orig[stack[mid]] >= val){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }
        
        
        
        return ans;
        
    }
    
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        vector<int>stack;
        int sz = 0;
        stack.push_back(n-1);
        sz++;
        
        int ans = 0;
        
        for(int i = n-2; i >= 0; i--){
            int val = arr[i];
            
            if(val <= arr[stack[sz-1]]){
                int temp = helper(stack, sz,val,arr);
                
                ans = max(ans, (stack[temp] - i));
                
            }
            else{
                //this is the greatest
                stack.push_back(i);
                sz++;
            }
            
        }
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends