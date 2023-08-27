class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string selectedSubString = "";
        string remainingSubstring = "";
        
        if (strs.size() == 1) return strs[0];
        for (int i = 0; i<strs[0].length();i++) {
            bool selectString = true;
            remainingSubstring += strs[0][i];
            
            for (int j = 1; j<strs.size();j++) {
                if (strs[j].find(remainingSubstring) == std::string::npos) selectString = false;
            }
            if (selectString) selectedSubString = remainingSubstring;
        }

        return selectedSubString;
        
    }
};