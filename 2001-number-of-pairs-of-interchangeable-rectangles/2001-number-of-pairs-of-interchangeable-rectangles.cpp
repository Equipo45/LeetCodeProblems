class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long count = 0;
        unordered_map<double, long long> aspectRatiosCount;

        for (int i = 0; i < rectangles.size(); i++) {
            double ratio = rectanglesDivision(rectangles[i]);
            //La primera no la contamos por que se suma 1 al map despues de contarla
            //Si nos lo volvemos a encontrar sumamos 1, es la semejanza con el siguiente
            //Si nos lo encontramos una tercera vez, sumamos dos, por que sabemos que hay dos anteriores que se repiten
            count += aspectRatiosCount[ratio];
            aspectRatiosCount[ratio]++;
        }

        return count;
    }

    double rectanglesDivision(const vector<int>& rectangle) {
        return static_cast<double>(rectangle[0]) / static_cast<double>(rectangle[1]);
    }
};