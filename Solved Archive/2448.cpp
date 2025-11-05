#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> get_stars(int k) {
	if (k == 0) {
		return {
			"  *  ",
			" * * ",
			"*****"
		};
	}
	
	vector<string> former = get_stars(k-1);
	int former_str_size = (int)former[0].size();
	int space_cnt = former_str_size / 2 + 1;
	int former_size = (int)former.size();
	for (int i = 0; i < former_size; ++i)
		former.push_back(former[i] + string(1, ' ') + former[i]);
	for (int i = 0; i < former_size; ++i)
		former[i] = string(space_cnt, ' ')  + former[i] + string(space_cnt, ' ');

	return former;
}

int main() {
	int N;
	cin >> N;

	int k = 0;
	int power_2 = N / 3;
	while (power_2 != 1) {
		power_2 >>= 1;
		++k;
	}

	vector<string> stars = get_stars(k);
	for (const string& s : stars)
		cout << s << '\n';

	return 0;
}