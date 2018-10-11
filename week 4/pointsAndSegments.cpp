/*
	Given a set of points on a line and a set of segments on
	a line. The goal is to compute, for each point,
	the number of segments that contain this point.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct Point {
	// 0 - start, 1 - point, 2 - end
	int coord;
	int name;
};

struct PointToSorted {
	int coord;
	int originalIdx;
	int answer;
};

bool cmp(Point a, Point b) {
	if (a.coord != b.coord) {
		return a.coord < b.coord;
	} else {
		// s -> p -> e
		return a.name < b.name;
	}
}

bool cmp2(PointToSorted a, PointToSorted b) {
	return a.coord < b.coord;
}

bool sortByIdx(PointToSorted a, PointToSorted b) {
	return a.originalIdx < b.originalIdx;
}

vector<int> countSegments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> res;
	// we combine and sort all three arrays
	vector<Point> allPoints;
	// it is all needed because we need to return answer
	// in the same order in which were the points
	// and points array was not sorted
	vector<PointToSorted> sortedPoints;
	int startCounter = 0;
	for (auto e : starts) {
		allPoints.push_back({e, 0});
	}
	for (auto e : ends) {
		allPoints.push_back({e, 2});
	}
	for (int i = 0; i < points.size(); i++) {
		allPoints.push_back({points[i], 1});
		sortedPoints.push_back({points[i], i, 0});
	}

	sort(allPoints.begin(), allPoints.end(), cmp);
	sort(sortedPoints.begin(), sortedPoints.end(), cmp2);

	int current = 0;
	for (auto e : allPoints) {
		if (e.name == 0) {
			startCounter++;
		} else if (e.name == 2) {
			startCounter--;
		} else {
			sortedPoints[current].answer = startCounter;
			current++;
		}
	}

	sort(sortedPoints.begin(), sortedPoints.end(), sortByIdx);

	for (auto e : sortedPoints) {
		res.push_back(e.answer);
	}

	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> starts(n), ends(n);

	for (int i = 0; i < starts.size(); i++) {
		cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (int i = 0; i < points.size(); i++) {
		cin >> points[i];
	}

	vector<int> cnt = countSegments(starts, ends, points);
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << ' ';
	}
	cout << endl;
	return 0;
}
