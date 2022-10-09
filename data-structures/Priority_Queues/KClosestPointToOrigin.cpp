#include<bits/stdc++.h>
using namespace std;
class Point {
public:
    int x;
    int y;
    int distance;
    Point(int x, int y, int distance) {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
};

struct comparator {
    bool operator() (Point &a, Point &b) {
        return (b.distance > a.distance);
    }
};

class KClosestPointToOrigin {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, comparator> maxHeap;

        for(int i = 0; i < k; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int distance = x*x + y*y;
            Point p = Point(x, y, distance);
            maxHeap.push(p);
        }

        for(int i = k; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];
            int distance = x*x + y*y;
            if(distance < maxHeap.top().distance) {
                maxHeap.pop();
                maxHeap.push(Point(x, y, distance));
            }
        }

        vector<vector<int>> ans(k,{0,0});
        int i = 0;
        while(!maxHeap.empty()) {
            Point p = maxHeap.top();
            maxHeap.pop();
            ans[i][0] = p.x;
            ans[i][1] = p.y;
            i += 1;
        }
        return ans;

    }
};
