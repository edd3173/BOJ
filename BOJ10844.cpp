#include <iostream>
using namespace std;
#define MOD 1000000000

int main(){
        /*
        dp[i][0]=(dp[i-1][1])%1000000000;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%1000000000;
        dp[i][2]=(dp[i-1][1]+dp[i-1][3])%1000000000;
        dp[i][3]=(dp[i-1][2]+dp[i-1][4])%1000000000;
        dp[i][4]=(dp[i-1][3]+dp[i-1][5])%1000000000;
        dp[i][5]=(dp[i-1][4]+dp[i-1][6])%1000000000;
        dp[i][6]=(dp[i-1][5]+dp[i-1][7])%1000000000;
        dp[i][7]=(dp[i-1][6]+dp[i-1][8])%1000000000;
        dp[i][8]=(dp[i-1][7]+dp[i-1][9])%1000000000;
        dp[i][9]=(dp[i-1][8])%1000000000;
        */
    int n;
    cin >> n;

    long long dp[101][10]={0,}; // init
    
    for(int i=1;i<=9;i++){
        dp[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j==0)
                dp[i][j]=dp[i-1][1]%MOD;
            else if(j==9)
                dp[i][j]=dp[i-1][8]%MOD;
            else
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
        }
    }

    long long res=0;
    for(int i=0;i<10;i++){
        res+=dp[n][i];
    }

    res%=MOD;

    cout << res << endl;

    return 0;
}