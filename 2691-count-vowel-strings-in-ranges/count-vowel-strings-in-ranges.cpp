class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();
        vector<int>vowelIndices(n,0);
        int count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            string s1 = words[i];
            int len = s1.size();
            char ch1 = s1[0];
            char ch2 = s1[len-1];
            if(ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u')
            {
                if(ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u')
                {
                    count+=1;
                }
            }
            vowelIndices[i] = count;
        }
        vector<int>results;
        for(int i = 0 ; i < queries.size() ; i++)
        {
            vector<int>v1 = queries[i];
            int idx1 = v1[0];
            int idx2 = v1[1];
            if(idx1 == 0)
            {
                results.push_back(vowelIndices[idx2]);
            }
            else
            {
                int diff = vowelIndices[idx2] - vowelIndices[idx1-1];
                results.push_back(diff);
            }
        }
        return results;
    }
};