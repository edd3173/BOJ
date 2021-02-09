#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);

	int curY = 0;
	int curE = 0, curS = 0, curM = 0;

	while (1) {
		curY++;
		
		curE++;
		if (curE > 15)
			curE = 1;
		
		curS++;
		if (curS > 28)
			curS = 1;

		curM++;
		if (curM > 19)
			curM = 1;

		//printf("curY : %d, (E,S,M) : (%d, %d, %d)\n", curY, curE, curS, curM);
		if (curE == e && curS == s && curM == m) {
			//printf("Answer : %d\n", curY);
			printf("%d\n", curY);
			break;
		}
	}
	return 0;
}