class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool>haveKey(n, false);
        haveKey[0] = true;
        queue<int>q;
        q.push(0);
        int count = 1;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(int num : rooms[room]){
                if(!haveKey[num]){
                    q.push(num);
                    count+=1;
                    haveKey[num] = true;
                }
            }
        }
        return count == rooms.size();   
    }
};