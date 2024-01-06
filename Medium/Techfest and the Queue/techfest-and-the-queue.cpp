//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
int sumOfPowersOfPrime(int n){  //function which finds out prime factors for any number
        int count = 0;
        
        while(n%2==0){
            count++;
            n/=2;
        }
        
        for(int i = 3; i<=sqrt(n);i++){
            while(n%i==0){
                count++;
                n/=i;
            }
        }
        
        if(n>2){
            count++;
        }
        
        return count;
    }
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans = 0;
	    for(int i = a; i<=b;i++){
	        ans+=sumOfPowersOfPrime(i);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends