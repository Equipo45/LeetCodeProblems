class Solution {
public:
    string reversePrefix(string word, char ch) {
        string totalWord = "";
        for (int i = word.find(ch); i >= 0 ; i--) {
            totalWord += word[i];
        }
        //We exclude the proper character, so we start in the following one
        return totalWord + word.substr(word.find(ch) + 1);
    }
};