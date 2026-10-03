class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {

      int m = grid.size();
      int n = grid[0].size();

      vector<int> ans;

      bool flag = true;

      for(int i=0;i<m;i++){
        // if(flag){
        //     for(int j = n-1;j>0;j-=2){
        //         ans.push_back(grid[i][j]);
        //     }
        // }
        // else{
        //     for(int j = 0;j<n;j+=2){
        //         ans.push_back(grid[i][j]);
        //     }
        // }
        // flag = !flag;

        if(i%2==0){
            for(int j=0;j<n;j++){
                if(flag){
                    ans.push_back(grid[i][j]);
                    flag=false;
                }
                else{
                    flag=true;
                }
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                if(flag){
                    ans.push_back(grid[i][j]);
                    flag=false;
                }
                else{
                    flag=true;
                }
            }
        }
      }
      return ans;  
    }
};