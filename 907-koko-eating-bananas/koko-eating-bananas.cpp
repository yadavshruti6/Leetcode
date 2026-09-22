class Solution {
public:
    bool eat(vector<int>& piles, int h,int k){

        long long hours = 0;

        for(int x:piles){
            hours += (x+k-1)/k;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

      int low = 1;
      int hi = *max_element(piles.begin(),piles.end());
      int ans = 0;

      while(low <= hi){
        int mid = low + (hi-low)/2;

        if(eat(piles,h,mid)){
            ans = mid;
            hi = mid -1;
        }
        else{
            low = mid + 1;
        }
      }  
      return ans;
    }
};