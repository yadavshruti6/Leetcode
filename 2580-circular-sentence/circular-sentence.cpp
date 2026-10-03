class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        int n = sentence.size();
        int i=0;
        int j=0;

        while(j<n){
            while(j<n && sentence[j] != ' ')j++;

            if(j==n){
                return sentence[0] == sentence[n-1];
            }

            i=j-1;

            while(j<n && sentence[j] == ' ')j++;

            if(sentence[i] != sentence[j]){
                return false;
            }

        }

        
        return true;
    }
};