#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> Queue;
	int n, m, res, tmp;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		Queue.push(i); // Queue init

	// circular에 대한 발상을 어떻게?
	// 앞의 data를 pop하고 뒤에 넣음의 반복.

	cout << '<';
	for (int j = 0; j < n - 1;j++) { // while(!Stack.empty()) 가 아니라 for문. 출력형식의 문제.
		for (int i = 0; i < m-1; i++) {
			tmp = Queue.front();
			Queue.pop();
			Queue.push(tmp);
		}
		res = Queue.front();
		cout << res << ", "; // 이걸 char로 ', ' 하니까 개판나더라. 당연하지.
		Queue.pop();
	}
	res = Queue.front();
	cout << res;
	cout << '>';

	return 0;
}