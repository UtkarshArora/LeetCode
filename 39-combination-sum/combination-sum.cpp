class Solution {
public:

    vector<vector<int>>res;

    void combination(vector<int>& candidates, vector<int>&curr, int target, int currSum, int index)
    {
        // find sum = target for different combination of values
        if(currSum == target)
        {
            res.push_back(curr);
            return;
        }
        if(currSum > target)
        {
            return;
        }
        int n = candidates.size();
        for(int i = index ; i < n ; i++)
        {
            //cout<<"candidates[i] :"<<candidates[i]<<endl;
            if((currSum + candidates[i]) <= target){
                curr.push_back(candidates[i]);
                combination(candidates, curr, target, currSum+candidates[i], i);
                curr.pop_back();
            }
            else{
                break;
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          
        int n = candidates.size();
        //vector<int>curr;
        sort(candidates.begin(), candidates.end());
        for(int i = 0 ; i < n ; i++){
            vector<int>curr = {candidates[i]};
            combination(candidates, curr, target, candidates[i], i);
        }
        return res;
    }
};