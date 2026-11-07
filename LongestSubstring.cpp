class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        Longest Substring Without Repeating Characters

        Soln:
        It will push each element to a new vector until an occurence occurs and then it will remove that element and will keep on pushing elements inside the vector
        In the end we will display the size of the vector
        */
        char pointer;
        vector<char>subString;
        int maxLength = 0;
        for(int i = 0; i<s.size(); i++){
            pointer = s[i];
            auto duplicate = find(subString.begin(), subString.end(), pointer);
            
            if (duplicate != subString.end()){
                subString.erase(subString.begin(),duplicate+1);
            }
            subString.push_back(pointer);

            maxLength =  max((int)subString.size(), maxLength);
        }

        return maxLength;
        
    }
};
