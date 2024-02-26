//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private: 
  void powerSet(int index, int n, string s, string & t, vector < string > & res) {
    if (index >= n) {
      if (t != "")
        res.push_back(t);
      return;
    }
    t.push_back(s[index]);
    powerSet(index + 1, n, s, t, res);
    t.pop_back();
    powerSet(index + 1, n, s, t, res);
  }
  public: 
  vector < string > AllPossibleStrings(string s) {
    vector < string > res;
    string t = "";
    powerSet(0, s.size(), s, t, res);
    sort(res.begin(), res.end());
    return res;
  }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends