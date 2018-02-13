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
#define        N                     5000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
ll prime[5000000 + 100];ll countfactor[N],q;
void p()
{
    for(int i=2;i<=N;i++){
            if(!prime[i]){
            for (int j = i; j <= N; j=j+i ){
                      q=j;int ans=0;
                     while(q%i==0){ q/=i;
                        ans++;
                     }
                     prime[j]+=ans;
              }
            }
    }

    for (int i = 2; i <= N; i++){
        countfactor[i]=countfactor[i-1]+prime[i];
    }

}

int main()
{
 p();
take1(test);
while(test--){
    take2(a,b);
    printf("%lld\n",countfactor[a]-countfactor[b]);


}


return 0;
}