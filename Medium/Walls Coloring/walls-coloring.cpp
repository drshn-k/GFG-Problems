//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
           int paintinlesscost(vector<vector<int>> &colors, int N)

        {   

        if(N==0)

        {

     return 0;

        }

        //p=0,b=1,y=2

        //Now we have to paint the each wall by checking the min cost in the walls

        vector<vector<int>> store_the_cost_of_color(N,vector<int>(3,0));

        //Pink

        store_the_cost_of_color[0][0] = colors[0][0];

        //Black

        store_the_cost_of_color[0][1] = colors[0][1];

        //Yellow

        store_the_cost_of_color[0][2] = colors[0][2];

        //{wall 1 = {14,2,11} = {PINK,BLACK,YELLOW}}

        

        for(int i=1;i<N;i++)

        {

        //Now the first wall has been painted

        store_the_cost_of_color[i][0] = min(store_the_cost_of_color[i-1][1],store_the_cost_of_color[i-1][2])+ colors[i][0];

        store_the_cost_of_color[i][1] = min(store_the_cost_of_color[i-1][0],store_the_cost_of_color[i-1][2])+ colors[i][1];

        store_the_cost_of_color[i][2] = min(store_the_cost_of_color[i-1][1],store_the_cost_of_color[i-1][0])+ colors[i][2];

        }

        return min(store_the_cost_of_color[N-1][0],min(store_the_cost_of_color[N-1][1],store_the_cost_of_color[N-1][2])); 

    }

    int minCost(vector<vector<int>> &colors, int N) {

        return paintinlesscost(colors,N);

    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends