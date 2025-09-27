 class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0.0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double x1 = points[i][0], y1 = points[i][1];
                    double x2 = points[j][0], y2 = points[j][1];
                    double x3 = points[k][0], y3 = points[k][1];

                    double a = hypot(x2 - x1, y2 - y1);
                    double b = hypot(x3 - x2, y3 - y2);
                    double c = hypot(x1 - x3, y1 - y3); // fixed: distance between i and k

                    double s = (a + b + c) / 2.0;
                    double heron = sqrt( s * (s - a) * (s - b) * (s - c));

                    result = max(result, heron);
                }
            }
        }
        return result;
    }
 };
