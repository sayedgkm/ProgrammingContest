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
int one[105]; int zero[105], ar[105];
int main()
{
    int c1=0, c2=0, n;
    cin >> n;
        f(i,0,n){
           cin>>ar[i];if(ar[i]==1)c1++;
           }
           if(c1==n){
            cout<<n-1<<endl;return 0;
           }
           int max_ending=0,max_so_far=0;
    f(i,0,n){
       if(ar[i]==0) max_ending++;else max_ending--;
       max_so_far=max(max_so_far,max_ending);
       if(max_ending<0) max_ending=0;
    }

    cout << c1+max_so_far<< endl;
    return 0;
}