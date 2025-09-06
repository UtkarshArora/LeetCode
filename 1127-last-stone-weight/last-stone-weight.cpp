class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int stone : stones)
        {
            pq.push(stone);
        }
        while(pq.size()>=2)
        {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            if(stone1!=stone2)
            {
                int diff = stone1 - stone2;
                pq.push(diff);
            }
        }
        return (pq.empty())? 0 : pq.top();
    }
};