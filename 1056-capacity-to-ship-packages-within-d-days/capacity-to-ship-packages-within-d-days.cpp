class Solution {
public:
    bool ship(vector<int>& weights, int days, int capacity){

        long long weight=weights[0];
        int d=1;
        for(int i=1;i<weights.size();i++){
            if(weights[i] + weight <= capacity){
                weight+=weights[i];
            }
            else{
                d++;
                weight=weights[i];
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

       int low = *max_element(weights.begin(),weights.end());
       int hi = accumulate(weights.begin(),weights.end(),0LL);
       int ans =0 ;

       while(low<=hi){
        int mid = low + (hi-low)/2;

        if(ship(weights,days,mid)){
            ans = mid;
            hi = mid -1;
        }
        else{
            low = mid +1;
        }
       }
       return ans;
    }
};