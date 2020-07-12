#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> Queue;
	int n, m, res, tmp;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		Queue.push(i); // Queue init

	// circular�� ���� �߻��� ���?
	// ���� data�� pop�ϰ� �ڿ� ������ �ݺ�.

	cout << '<';
	for (int j = 0; j < n - 1;j++) { // while(!Stack.empty()) �� �ƴ϶� for��. ��������� ����.
		for (int i = 0; i < m-1; i++) {
			tmp = Queue.front();
			Queue.pop();
			Queue.push(tmp);
		}
		res = Queue.front();
		cout << res << ", "; // �̰� char�� ', ' �ϴϱ� ���ǳ�����. �翬����.
		Queue.pop();
	}
	res = Queue.front();
	cout << res;
	cout << '>';

	return 0;
}