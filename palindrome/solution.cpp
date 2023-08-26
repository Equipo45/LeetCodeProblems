class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        std::string numberToString = std::to_string(x);
        int xLength = numberToString.length();

        int initialPosition = 0;

        for (int i = 0; i < xLength;i++) {
            if (numberToString[initialPosition] != numberToString[xLength-1]) return false;
            initialPosition++;
            xLength--;
        } 

        return true;
     
    }
};