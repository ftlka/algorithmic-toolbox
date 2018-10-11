/*
	Finds the closest pair of points among the given n
	points. And returns distance between them.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
	int x;
	int y;
};

void printPoint(Point a) {
	cout << '{' << a.x << ',' << a.y << "} ";
}

double calculateDist(Point a, Point b) {
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double bruteForce(const vector<Point>& a) {
	double d = calculateDist(a[0], a[1]);

	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			d = min(d, calculateDist(a[i], a[j]));
		}
	}
	return d;
}

double cmpX(Point a, Point b) {
	return a.x < b.x;
}

double cmpY(Point a, Point b) {
	return a.y < b.y;
}

vector<Point> filterByD(const vector<Point>& points, double d) {
	vector<Point> result;
	int mid = points[points.size() / 2].x;
	for (auto e : points) {
		if (abs(e.x - mid) < d) {
			result.push_back(e);
		}
	}
	return result;
}

double minDist(vector<Point>& points) {
	// First we split points into two parts by a line
	// so we sort them by x, take each half and
	// make recursive calls with each part.
	// But it gives us min only for those parts and
	// there can be min distance for points from diff parts
	if (points.size() < 4) {
		// easy brute force for sizes from 2 to 3
		return bruteForce(points);
	}

	sort(points.begin(), points.end(), cmpX);
	int mid = points.size() / 2;

	vector<Point> b(points.begin(), points.begin() + mid);
	vector<Point> c(points.begin() + mid, points.end());

	double dist1 = minDist(b);
	double dist2 = minDist(c);

	// Now we compare points from different parts
	// but take only those which distance to middle is
	// less than d
	double d = min(dist1, dist2);
	vector<Point> closestToMiddle = filterByD(points, d);
	// Then we sort those points by y coordinate
	sort(closestToMiddle.begin(), closestToMiddle.end(), cmpY);
	// It turnes out that if |i - j| > 7, their distance
	// will be greater than d so we compare points from
	// closestToMiddle only to 7 other. Phew
	for (int i = 0; i < closestToMiddle.size(); i++) {
		for (int j = i + 1; j < closestToMiddle.size() && j < i + 8; j++) {
			d = min(d, calculateDist(closestToMiddle[i], closestToMiddle[j]));
		}
	}

	return d;
}

int main() {
	int n;
	cin >> n;
	vector<Point> points(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points[i] = {x, y};
	}

	cout << fixed;
	cout << setprecision(9) << minDist(points);
	cout << endl;
	return 0;
}
