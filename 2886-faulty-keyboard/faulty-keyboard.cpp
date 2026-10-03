class Solution {
public:
    string finalString(string s) {

     string ans = "";

     for(char c:s){
        if(c != 'i'){
            ans+=c;
        }
        else{
            reverse(ans.begin(),ans.end());
        }
     }

     return ans;   
    }
};