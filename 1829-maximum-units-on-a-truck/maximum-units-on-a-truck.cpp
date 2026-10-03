class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

       int n = boxTypes.size();
       int units = 0;

    //    vector<pair<double,int>> a;

    //    for(int i=0;i<n;i++){
    //     double ratio = (double)boxTypes[i][1]/boxTypes[i][0];
    //     a.push_back({ratio,i});
    //    } 

    //    sort(a.rbegin(),a.rend());

    //     for(auto x:a){
    //         int box = boxTypes[x.second][0];

    //         if(box <= truckSize){
    //             truckSize -= box;
    //             units += box * boxTypes[x.second][1];
    //         }
    //         else{
    //             units += truckSize * boxTypes[x.second][1];
    //             break;
    //         }
    //     }

    //    return units;
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