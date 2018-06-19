// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
string a, b; int lena, lenb, ans; int dp[200][200];
int fun(int i, int j){
    if (i == lena || j == lenb)
        return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j])
        ans = fun(i + 1, j + 1) + 1;
    else {
        int p = fun(i + 1, j);
        int q = fun(i, j + 1);
        ans = max(p, q);
    }
    return dp[i][j] = ans;
}
int main()
{
    take1(test);
    f(j, 1, test + 1){
        mem(dp, -1);
        cin >> a;
        b = a;
        reverse(b.begin(), b.end());
        lena = a.length();
        lenb = b.length();
        printf("Case %d: %d\n", j, lena - fun(0, 0));

    }

    return 0;
}


