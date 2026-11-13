#include <map>
class Solution {
public:
/*
Group Anagrams
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for(string s : strs){
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto entry : mp){
            ans.push_back(entry.second);
        }
        return ans;
    }
};
