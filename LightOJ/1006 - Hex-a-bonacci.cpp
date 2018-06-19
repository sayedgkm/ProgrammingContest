#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define bignum 10000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,y) for(int i=0;i<y;i++)
using namespace std;
long long dp[10100];
long long a, b, c, d, e, f;
long long fn(long long  n) {
    dp[0]=a%bignum;
    dp[1]=b%bignum;
    dp[2]=c%bignum;
    dp[3]=d%bignum;
    dp[4]=e%bignum;
    dp[5]=f%bignum;

    for(long long i=6;i<=n;i++)
        dp[i] = ( dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6])%bignum;

    return dp[n];
}
int main() {
  long long n, caseno = 0, cases;

    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        mem(dp,-1);
           printf("Case %lld: %lld\n", ++caseno,fn(n));

    }
    return 0;
}
