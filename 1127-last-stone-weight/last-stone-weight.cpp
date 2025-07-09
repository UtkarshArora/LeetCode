class Solution {
public:

   

    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq(stones.begin(), stones.end());
        while(pq.size() >= 2)
        {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();

            if(x!= y)
            {
                int diff = y - x;
                pq.push(diff);
            }
        }
        return (pq.size() == 0)? 0 : pq.top();
    }
};