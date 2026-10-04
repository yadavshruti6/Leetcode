class Solution {
public:
    string capitalizeTitle(string title) {

       int n = title.size();
       string ans="";

       int i=0;
       int j=0;

       while(j<n){
        while(j<n && title[j]!=' ')j++;

        int length = j-i;
        string s;
        s = title.substr(i, length);
        for(char &c : s) {
            c = tolower(c);
            }

        if(length>2){
          s[0] = toupper(s[0]); 
        }

        ans+=s;
        if(j!=n){
            ans+=" ";
        }

        while(j<n && title[j]==' ')j++;
        i=j;
       } 
       return ans;
    }
};