#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;

static double calculate_triangle_area(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
	double vector_ab_x = b.first - a.first;
	double vector_ab_y = b.second - a.second;
	double vector_ac_x = c.first - a.first;
	double vector_ac_y = c.second - a.second;

	return (vector_ab_x * vector_ac_y - vector_ac_x * vector_ab_y) * 0.5;
}

int main() {
	int N;
	cin >> N;

	double total_area = 0.0;
	vector<pair<int, int>> coordinates(N);

	cin >> coordinates[0].first >> coordinates[0].second;
	cin >> coordinates[1].first >> coordinates[1].second;

	for (int i = 2; i < N; ++i) {
		cin >> coordinates[i].first >> coordinates[i].second;
		total_area += calculate_triangle_area(coordinates[0], coordinates[i - 1], coordinates[i]);
	}

	cout << fixed << setprecision(1) << abs(total_area);

	return 0;
}