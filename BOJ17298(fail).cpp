#include <iostream>
#include <queue>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	int temp;
	bool flag = false;
	int i, j;

	int* arr;
	arr = new int[n];
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	queue<int> Queue;
	for (int i = 0; i < n; i++)
		Queue.push(arr[i]);

	for (i = 0; i < n; i++) {
		flag = false;
		if (Queue.size() == 1)
			cout << -1 << ' '; // end
		else {
			temp = Queue.front();
			Queue.pop();

			for (j = 0; j < Queue.size(); j++) {
				if (Queue.front() > temp && flag == false) {
					cout << Queue.front() << ' ';
					flag = true;
				}
				Queue.push(Queue.front());
				Queue.pop();
			}
			if (j == Queue.size() && flag==false)
				cout << -1 << ' ';
		}
	}
}