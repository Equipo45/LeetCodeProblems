class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long count = 0;
        unordered_map<double, long long> aspectRatiosCount;

        for (int i = 0; i < rectangles.size(); i++) {
            double ratio = rectanglesDivision(rectangles[i]);
            count += aspectRatiosCount[ratio];
            aspectRatiosCount[ratio]++;
        }

        return count;
    }

    double rectanglesDivision(const vector<int>& rectangle) {
        return static_cast<double>(rectangle[0]) / static_cast<double>(rectangle[1]);
    }
};