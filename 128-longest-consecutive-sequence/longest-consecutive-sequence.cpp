class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sorting-> time: O(nlogn), space: O(1)
        // store all numbers in the set, check for the longest inc sequence from that number

        // for each number, I check if num-1 exists, then skip, otherwise find longest from this number, time-> O(N), O(N)
        
        unordered_set<int>set1;
        int maxCons = 0;
        for(int num : nums){
            set1.insert(num);
        }
        for(int num : set1){
            if(set1.find(num-1)!=set1.end()){
                continue;
            }
            else{
                int cons = 1;
                while(set1.find(num+1)!=set1.end())
                {
                    cons++;
                    num++;
                }
                maxCons = max(cons, maxCons);
            }
        }
        return maxCons;
    }
};