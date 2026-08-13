class Solution {
public:

    unordered_map<int,int>freqMap;
    vector<int>unique;
    
    int partition(int left, int right, int pivot_index){

        int pivot_freq = freqMap[unique[pivot_index]];
        swap(unique[pivot_index], unique[right]);

        int store_index = left;
        for(int i = left ; i <=right ; i++)
        {
            if(freqMap[unique[i]] < pivot_freq)
            {
                swap(unique[i], unique[store_index]);
                store_index++;
            }
        }
        swap(unique[right], unique[store_index]);
        return store_index;
    }

    void quickselect(int left, int right, int k_smallest)
    {
        if(left >= right){
            return;
        }
        int pivot_index = left + rand()%(right - left + 1);
        int index = partition(left, right, pivot_index);
        if(index == k_smallest){
            return;
        }
        else if(index < k_smallest){
            quickselect(index+1, right, k_smallest);
        }
        else{
            quickselect(left, index-1, k_smallest);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {

        for(int num : nums) 
        {
            freqMap[num]+=1;
        }   
        for(auto p : freqMap)
        {
            unique.push_back(p.first);
        }
        int n = unique.size();
        quickselect(0, n-1, n-k);
        vector<int>res;
        for(int i = n-k ; i < n ; i++)
        {
            res.push_back(unique[i]);
        }
        return res;
    }
};