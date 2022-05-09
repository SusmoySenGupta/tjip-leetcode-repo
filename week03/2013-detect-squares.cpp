class DetectSquares
{
private:
    unordered_map<long long, int> points;
    int BASE = 1e9 + 7;

    long long getSerializedValue(pair<int, int> point)
    {
        return (1LL * point.first * BASE) + point.second;
    }

public:
    DetectSquares()
    {
        points.clear();
    }

    void add(vector<int> point)
    {
        int X = point[0];
        int Y = point[1];
        points[getSerializedValue({X, Y})]++;
    }

    int count(vector<int> qpoint)
    {
        int total = 0;

        for (auto point : points)
        {
            int x2 = qpoint[0];
            int y2 = qpoint[1];
            int x4 = point.first / BASE;
            int y4 = point.first % BASE;

            if (x2 == x4 || abs(x2 - x4) != abs(y2 - y4))
                continue;

            long long X2Y4 = getSerializedValue({x2, y4});
            long long X4Y2 = getSerializedValue({x4, y2});

            if (points.count(X2Y4) && points.count(X4Y2))
            {
                total += points[X2Y4] * points[X4Y2] * point.second;
            }
        }

        return total;
    }
};
