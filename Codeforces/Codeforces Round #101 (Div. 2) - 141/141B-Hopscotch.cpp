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
int main()
{
 int n, x, y; int a;
 cin >> n;
 cin >> x >> y;
 if (y%n == 0){
  puts("-1"); return 0;
 }
 a = y / n; a++; int ans = 0;
 if (a == 1){
  ans=1;

 }
 else {
  a--;
  if (a % 2 == 0)
   ans += a + a / 2;
  else
   ans += (a- 1) + (a / 2) + 1;
  ans++; a++;
 }
  double p=(double)(n);
 if (a % 2 == 0||a==1){
  if (x > -(p / 2) && x < p / 2){
   cout << ans << endl;
   return 0;
  }
 }
 else if (a % 2){

  if (x>-p && x<p && x != 0){
   if (x<0)
    ans--;
    //if(!ans)
   cout << ans << endl; return 0;

  }


 }
 puts("-1");
 return 0;
}