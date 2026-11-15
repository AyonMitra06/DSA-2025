class Solution {
public:

    /*Encode and Decode Strings*/

    string encode(vector<string>& strs) {
        string encodedString;
        for(string s: strs){
            encodedString += to_string(s.size()) + "#" + s;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i<s.size()){
            int j = i;

            while(s[j] != '#'){
                j++;
            }

            int destination = stoi(s.substr(i,j-i));


            i = j+1;
            string reqString = s.substr(i,destination);

            ans.push_back(reqString);
            i = i+destination;
        }



        return ans;
    }
};
