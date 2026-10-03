class Solution {
public:
    int solve(int flag,int red,int blue,int level){
        if(flag==1){
            if(red<level) return 0;

            red-=level;

            return 1+solve(0,red,blue,level+1);
            
        }
        else{
            if(blue<level) return 0;
            
            blue-=level;
            return 1+solve(1,red,blue,level+1);
        }

        

    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(1,red,blue,1),solve(0,red,blue,1));
    }
};