#include <iostream>
#include <algorithm>
using namespace std;

int main(){

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