#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str, explode_str;
	cin >> str >> explode_str;

	stack<char> origin;
	for (int i = 0; i < (int)str.size(); ++i)
		origin.push(str[i]);

	string r_explode_str;
	for (int i = (int)explode_str.size()-1; i >= 0; --i)
		r_explode_str += explode_str[i];

	stack<char> result;
	int explode_idx = 0;
	while (!origin.empty()) {
		result.push(origin.top());
		origin.pop();

		if (result.top() == r_explode_str[explode_idx])
			++explode_idx;
		else if (result.top() == r_explode_str[0])
			explode_idx = 1;
		else
			explode_idx = 0;

		if (explode_idx == (int)explode_str.size()) {
			for (int i = 0; i < explode_idx; ++i)
				result.pop();
			for (int i = 0; i < explode_idx-1; ++i) {
				if (result.empty()) break;
				origin.push(result.top());
				result.pop();
			}
			explode_idx = 0;
		}
	}

	if (result.empty()) {
		cout << "FRULA";
		return 0;
	}
	
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}


	return 0;
}