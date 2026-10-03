class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {

        int n = nums.size();

        int i = 0;
        int j = n-1;

        long long x = 0;

        while(i<=j){
            string a  = "";
            a+= to_string(nums[i]);
            if(i!=j){
            a+= to_string(nums[j]);
            }

            i++;
            j--;

            x += stoll(a);
            
        }  
        return x; 
    }
};