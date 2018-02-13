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
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
int nxt(){
  int a;
  scanf("%d",&a);
  return a;
}
char a[5][5],b[5][5];
vector<char> v1,v2;
int main()
{
    for(int i=0;i<2;i++)
           scanf("%s",a[i]);
    for(int i=0;i<2;i++)
        scanf("%s",b[i]);
        for(int i=0;i<2;i++)
               if(a[0][i]!='X') v1.pb(a[0][i]);
         for(int i=1;i>=0;i--)
               if(a[1][i]!='X') v1.pb(a[1][i]);
                for(int i=0;i<2;i++)
               if(b[0][i]!='X') v2.pb(b[0][i]);
           for(int i=1;i>=0;i--)
               if(b[1][i]!='X') v2.pb(b[1][i]);
               int c=0;
            while(1){
                if(v1==v2){
                    puts("YES");
                    return 0;
                }
                swap(v1[1],v1[2]);
                swap(v1[0],v1[1]);
                   c++;
                   if(c>15) break;


            }
      puts("NO");
      return 0;
}