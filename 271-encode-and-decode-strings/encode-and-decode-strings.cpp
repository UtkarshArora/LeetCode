class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {

        string curr = "";
        for(string s1 : strs)
        {
            int len = s1.size();
            curr = curr + to_string(len) + "@" + s1;
        }
        return curr;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        int index = 0;
        vector<string>ans;
        while(index < s.size())
        {
            int pos = s.find_first_of('@', index);
            int len = stoi(s.substr(index, pos - index));
            index = pos + 1;
            ans.push_back(s.substr(index, len));
            index+=len;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));