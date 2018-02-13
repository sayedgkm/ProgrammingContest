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
ll le[N], ri[N];
int main()
{
 int n, a, b, t;
 take2(n, a);
 take2(b, t);
 string s;
 cin >> s;
 f(i, 0, s.length()){
  int p = 0;
  if (s[i] == 'w')
   p += b;
  p += a + 1;
  i == 0 ? ri[i] = p - a : ri[i] = ri[i - 1] + p ;
 }
 int x = 0;
 le[x++] = ri[0];
 for (int i = s.length() - 1; i >= 1; i--){
  int p = 0;
  if (s[i] == 'w')
   p += b;
  p += a + 1;
  le[x] = le[x - 1] + p; x++;
 }
 int ans = 0;
 for (int i = 0; i<n; i++){
  int p = i + 1;
  if (ri[i] <= t){
   ans = max(ans, p);
   int val = t - a*i - ri[i] + le[0];
   int x = upper_bound(le, le + n, val) - le;
   if(x)x--;
   p += x;
   p = min(p, n);
   ans = max(ans, p);
  }

 }
 for (int i = 0; i<n; i++){
  int p = i + 1;
  if (le[i] <= t){
   ans = max(ans, p);
   int val = t - a*i - le[i] + le[0];
   int x = upper_bound(ri, ri + n, val) - ri;
   if(x)x--;
   p += x;
   p = min(p, n);
   ans = max(ans, p);
  }

 }
 cout << ans << endl;
 return 0;
}