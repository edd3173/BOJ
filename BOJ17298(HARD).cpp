#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

	int N, i, temp;
	vector <int> v;
	stack <int> s;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &temp);
		v.push_back(temp); // get value and put it in vec
	}

	vector <int> ans(v.size(), -1); // init

	for (i = 0; i < v.size(); i++) { // for each iter.
		while (!s.empty() && v[s.top()] < v[i]) {
			ans[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");

	return 0;
}