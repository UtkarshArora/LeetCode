class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>pq(stones.begin(), stones.end());
        while(pq.size() > 1)
        {
            int num1 = pq.top(); pq.pop();
            int num2 = pq.top(); pq.pop();
            if(num1 != num2)
            {
                pq.push(num1-num2);
            }
        }
        return pq.empty()? 0 : pq.top();
    }
};