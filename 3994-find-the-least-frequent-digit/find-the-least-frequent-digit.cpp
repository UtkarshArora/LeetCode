class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int>map1;
        while(n!=0)
        {
            int digit = n%10;
            map1[digit]++;
            n = n / 10;
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto p : map1){
            pq.push(make_pair(p.second, p.first));
        }
        return pq.top().second;
    }
};