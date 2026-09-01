class Solution {
public:
    bool divisor(vector<int>& nums, int threshold,int k){

        long long sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+k-1)/k;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
     int low = 1;
     int hi = *max_element(nums.begin(),nums.end());
     int ans=-1;

     while(low<=hi){
        int mid = low + (hi-low)/2;

        if(divisor(nums,threshold,mid)){
            ans = mid;
            hi = mid-1;
        }
        else{
            low = mid+1;
        }
     } 
     return ans;  
    }
};