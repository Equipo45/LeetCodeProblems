class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) { return s.length(); }

        std::string stringTotal = "";
        std::map<char, int> charIndex;
        int maxCharacter = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i ++) {
            char caracter = s[i];

            if (charIndex.find(caracter) != charIndex.end() && charIndex[caracter] >= start) {
                start = charIndex[caracter] + 1;
            }
            
            charIndex[caracter] = i;
            int currentChar = charIndex[caracter] - start + 1;
            if (maxCharacter < currentChar) {
                maxCharacter = currentChar;
            }

        }

        return maxCharacter;
    }
};