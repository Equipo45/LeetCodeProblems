class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> concatVector;
        for (int i = 0 ; i < nums.size() ;) {
            for (int frecuency = 0 ; frecuency < nums[i] ; frecuency++) {
                concatVector.push_back(nums[i+1]);
            }
            i += 2;
        }

        return concatVector;
    }
};