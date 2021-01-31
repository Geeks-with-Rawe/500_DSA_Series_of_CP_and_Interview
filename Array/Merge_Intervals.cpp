class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        //If Input is Empty
        if(intervals.size() == 0){
            return result;
        }
        //Sort the Array
        sort(intervals.begin(),intervals.end());
        
        vector<int> temp(2);
        temp[0] = intervals[0][0]; //1
        temp[1] = intervals[0][1]; //3
        
        for(int i = 1; i < intervals.size() ; i++){
            
            //upper Bound >= Lower Bound -> Merge Possible
            // else -> Merge Not Possible
            
            if(temp[1] >= intervals[i][0]){
                //Lower Bound
                temp[0] = min(temp[0],intervals[i][0]);
                
                //Upper Bound 
                temp[1] = max(temp[1],intervals[i][1]);    
            }
            else{// When merge is not possible
                result.push_back(temp);
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }   
        }
        result.push_back(temp);
        
        return result;
        
    }
};