/*
    Given a set of segments mark as few points as possible
    so that each segment contains at least one marked point
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
    int start, end;
};

vector<int> optimalPoints(vector<Segment>& segments) {
    int currentPoint = segments[0].end;
    vector<int> points = {currentPoint};

    for (size_t i = 1; i < segments.size(); i++) {
        if (segments[i].start > currentPoint) {
            currentPoint = segments[i].end;
            points.push_back(currentPoint);
        }
    }
    return points;
}

bool cmp(Segment a, Segment b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); i++) {
        cin >> segments[i].start >> segments[i].end;
    }

    sort(segments.begin(), segments.end(), cmp);

    vector<int> points = optimalPoints(segments);

    cout << points.size() << endl;
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
    cout << endl;
    return 0;
}
