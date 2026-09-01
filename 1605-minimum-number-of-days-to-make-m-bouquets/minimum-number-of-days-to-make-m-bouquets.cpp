class Solution {
public:
    bool bloom(vector<int>& bloomDay, int m, int k,int days){

        int bouquets = 0;
        int flowers = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                flowers++;
                if(flowers==k){
                    bouquets++;
                    flowers=0;
                }
            }
            else{
                flowers=0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

      if((long long)m*k > bloomDay.size()){
        return -1;
      }  

      int low = 1;
      int hi = *max_element(bloomDay.begin(),bloomDay.end());
      int ans=0;

      while(low<=hi){
        int mid = low + (hi-low)/2;

        if(bloom(bloomDay,m,k,mid)){
            ans=mid;
            hi = mid -1;
        }
        else{
            low = mid+1;
        }
      }
      return ans;
    }
};