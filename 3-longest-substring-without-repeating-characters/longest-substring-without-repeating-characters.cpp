class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char,int> mp;
      int n=s.size();

      int i =0;
      int length = 0;
      int maxlength = 0;

      for(int j=0;j<n;j++){
        while(mp.count(s[j])){
            mp[s[i]]--;

            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
        }
        length = j-i+1;
        maxlength = max(maxlength , length);
        mp[s[j]]++;
      } 
      return maxlength;
    }
};