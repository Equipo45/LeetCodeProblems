class Solution {
public:
    string reversePrefix(string word, char ch) {
        int indexCh = word.find(ch);
        string totalWord = "";
        for (int i = indexCh; i >= 0 ; i--) {
            totalWord += word[i];
        }
        //We exclude the proper character, so we start in the following one
        return totalWord + word.substr(indexCh + 1);
    }
};