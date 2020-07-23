#include <iostream>
#include <algorithm>
using namespace std;

int main(){
/*

    1 : 1 // 1
    2 : 2 // 2
    3 : 1+2, 2+1, 3 // 3
    4 : 1+2+1, 1+3, 3+1 // 3
    5 : 1+3+1, 2+1+2, 2+3, 3+2 // 4
    6 : 1+2+3, 1+3+2, 2+3+1, 2+1+3, 3+2+1, 3+1+2, 1+2+1+2, 2+1+2+1 // 8

    Solve:
    Think of D[i][j], i is represented in 1,2,3 and last number is j(1,2,3).

    Let's think of D[i][1].
    D[i][1]=f(D[i-1][],D[i-2][],D[i-3][])
    D[4][1]=D[3][2]+D[3][3]
    D[4][2]=D[3][1]+D[3][3]
    D[4][3]=D[3][1]+D[3][2]

    D[5][1]=D[4][3]+D[4][2]
    D[5][2]=D[3][1]+D[3][3]
    D[5][3]=D[2][1]+D[2][2]

    D[6][1]=D[5][3]+D[5][2]
    D[6][2]=D[4][1]
    ... Gotcha!

    */
   int tc;
   cin >> tc;
   int n;
   
   long long dp[100001][4]={0,};
   int res=-1;

    dp[1][1]=1;
    dp[1][2]=0;
    dp[1][3]=0;

    dp[2][1]=0;
    dp[2][2]=1;
    dp[2][3]=0;

    dp[3][1]=1;
    dp[3][2]=1;
    dp[3][3]=1;

    for(int i=4;i<=100001;i++){
        dp[i][1]=(dp[i-1][2]+dp[i-1][3])%1000000009;
        dp[i][2]=(dp[i-2][1]+dp[i-2][3])%1000000009;
        dp[i][3]=(dp[i-3][1]+dp[i-3][2])%1000000009;
    }

   for(int i=0;i<tc;i++){
       cin >> n;
       cout << (dp[n][1]+dp[n][2]+dp[n][3])%1000000009 << endl;
   }

   return 0;
}
