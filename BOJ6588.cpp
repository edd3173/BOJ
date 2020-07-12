#include <iostream>
#include <math.h>
#define NUM 1000000
using namespace std;

int main() {

	bool check[NUM + 1];
	for (int i = 0; i <= NUM; i++)
		check[i] = true;
	for (int i = 2; i <= sqrt(NUM); i++) {
		if (check[i]) {
			for (int j = i + i; j <= NUM; j += i) {
				check[j] = false;
				// false : pn
			}
		}
	}

	int target;
	while (1) {
		scanf("%d", &target);
		if (target == 0)
			break;
		bool flag = false;

		for (int i = 3; i <= sqrt(NUM); i++) { // odd
			if (check[i] && check[target - i]) { // i, target-i are pn
				printf("%d = %d + %d\n", target, i, target - i);
				flag = true;
				break;
			}
		}
		if (flag == false)
			printf("Goldbach's conjecture is wrong\n");
	}

	return 0;
}