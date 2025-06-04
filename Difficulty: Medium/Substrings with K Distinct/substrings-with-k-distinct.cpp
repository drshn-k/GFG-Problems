class Solution {
  public:
  long long countAtleast(string& s, int k){
        // counts substrings with atleast k distinct characters
        vector <int> freq(26, 0);
        int l = 0;
        int n = s.length();
        int cnt = 0;
        long long ans = 0;
        
        for(int r = 0; r < n; r++){
            if(freq[s[r] - 'a'] == 0) cnt++;
            freq[s[r] - 'a']++;
            
            while(cnt >= k){
                freq[s[l] - 'a']--;
                if(freq[s[l] - 'a'] == 0) cnt--;
                l++;
            }
            
            ans += l;
        }
        
        return ans;
    }
    int countSubstr(string& s, int k) {
        return countAtleast(s, k) - countAtleast(s, k+1);
        
    }
};