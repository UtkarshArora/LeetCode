class Solution {
public:

    bool isSubSeq(string s, string p)
    {
        int sIndex = 0, pIndex = 0;
        while(sIndex < s.size() && pIndex < p.size())
        {
            if(s[sIndex] == p[pIndex])
                pIndex++;
            sIndex++;
        }
        if(pIndex < p.size())
            return false;
        return true;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int res = 0;
        int start = 0, end = removable.size() - 1;

        int mid = -1;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            string temp = s;
            for(int i = start; i <= mid ; i++)
            {
                int index = removable[i];
                temp[index] = '0';
            }
            bool ans = isSubSeq(temp, p);
            
            res = (ans)? (res + mid - start + 1) : res; 
            if(!ans)
                end = mid - 1;
            else
            {
                start = mid+1;
                s = temp;
            }
        }
        return res;
    }
};