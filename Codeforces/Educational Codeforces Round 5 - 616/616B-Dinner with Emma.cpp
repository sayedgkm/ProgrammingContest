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
ll ar[105][105];ll br[105];
int main()
{
    take2(r, c);
    ll maxi = 0, index, sum = 0;
    f(i, 0, r){

        f(j, 0, c) {
            scanf("%I64d", &ar[i][j]);
        }
          sort(ar[i], ar[i] + c);
        if (maxi<ar[i][0]){
            index = i;
            maxi = ar[i][0];
        }
    }
    printf("%I64d\n", ar[index][0]);
    return 0;
}