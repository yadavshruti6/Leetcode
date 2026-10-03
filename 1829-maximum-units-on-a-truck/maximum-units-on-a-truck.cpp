class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

    int n = boxTypes.size();
    int units = 0;

    auto cmp=[](auto& a,auto& b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]>b[1];
    };

    sort(boxTypes.begin(),boxTypes.end(),cmp);

    for(auto& ele:boxTypes){
        int box = ele[0];

            if(box <= truckSize){
                truckSize -= box;
                units += box * ele[1];
            }
            else{
                units += truckSize * ele[1];
                break;
            }
    }
    return units;
    }
};