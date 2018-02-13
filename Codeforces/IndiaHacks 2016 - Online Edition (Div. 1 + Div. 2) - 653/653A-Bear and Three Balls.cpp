// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
int ar[100];
inline int nxt(){
  int aaa;
  scanf("%d",&aaa);
  return aaa;
}
int main()
{
    int n=nxt();
    f(i,0,n) scanf("%d",&ar[i]);
    f(i,0,n){

        f(j,i+1,n){

           f(k,j+1,n){
              if(ar[i]!=ar[j]&&ar[j]!=ar[k]&&ar[i]!=ar[k]){
                 if(abs(ar[i]-ar[j])<=2&&abs(ar[j]-ar[k])<=2&&abs(ar[i]-ar[k])<=2){
                    puts("YES");
                    return 0;
                 }

              }


           }

        }

    }
    puts("NO");



      return 0;
}