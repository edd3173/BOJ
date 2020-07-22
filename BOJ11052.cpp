#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    
   int n;
   int arr[10000]={0,};
   int dp[10000]={0,};
   cin >> n;

   for(int i=1;i<=n;i++){
       cin >> arr[i];
   } // 1부터 받는다.

    // 방향성을 잘못 잡았어! 난 팩의 종류를 줄였는데, 팩을 고르는 횟수를 bottom-up으로!

    // dp[] : total sum
    // arr[] : cost per pack

   /*
   dp[1]=arr[1]
   dp[2]=max(dp[0]+arr[2], dp[1]+arr[1])
   dp[3]=max(dp[0]+arr[3], dp[1]+arr[2], dp[2]+arr[1])
   */

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            dp[i]=max(arr[j]+dp[i-j],dp[i]);
        /* 아! 내가 완전히 잘못알고 잇었다! dp[i]는 max를 찾기 위해 반복적으로 들어가는 것! 논리식과는 연관이 없다!!!
         결국 핵심은 arr[j]+dp[i-j]
         어쩐지, 재귀적이다 싶었어.
         그래서 dp[0]는 뭔데? dp[0]는 0. 
         왜 arr[i]는 1부터 받는거야? dp와 iteration을 맞춰주기 위해서
        */
    }

    cout << dp[n] << endl;

    return 0;
}