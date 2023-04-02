//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
  
int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
    
      int n = arr.size();
      int m = arr[0].size();
      
      // used to store the maximum points we can store in ith step
      vector<int> stpoints(n*m,0);
      
      // so that no cell visited twice
      vector<vector<int>> visited(n,vector<int>(m,0));
      
      
      // used for bfs traversal
      queue<pair<int,pair<int,int>>>q;
      
      
      
      //      {steps,{x,y}}
      q.push({0,{start_x,start_y}});
      
      visited[start_x][start_y] = true;


    // these are the points on which knight can jump from i,j
    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8] = { 1, 2,  2,  1, -1, -2,-2,-1 };
    
    
    
    //bfs traversal
      while(q.size()!=0){
          
          int steps = q.front().first;
          int x = q.front().second.first;
          int y = q.front().second.second;
          
         
          stpoints[steps]+=arr[x][y];
          q.pop();
          
          for(int i =0;i<8;i++){
              int nx = x+dx[i]; 
              int ny = y+dy[i];
              
            
              if(nx<n and ny<m and nx>=0 and ny>=0 and visited[nx][ny] == false){
                  
                
                  visited[nx][ny] = true;
                  q.push({steps+1,{nx,ny}});
              }
          }
          
      }
      
       int ans = -1;
       int maxx = INT_MIN;
       
       // now we have maximum points in ith steps in vector stpoint
       
       // now we solve question by satisfying the future condition given in the question
       
       
       for(int i =0;i<n*m;i++){
           
           int x = i;
           int points =0;
           
           while(x<m*n){
               
               if(stpoints[x] == 0)break;
               points += stpoints[x];
               x = x+stpoints[x];
               
           }
           
           stpoints[i] = points;
           if(maxx<points){
               maxx = points;
               ans = i;
           }
           
       }
         
      
      return ans;
      
      // https://youtu.be/tA92ACLjH0I
    
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends