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
pair<int,pii> ar[N];
vector<int> v;
double area(double x1, double y1, double x2, double y2, double x3, double y3){
 double ans = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
 ans /= 2;
 ans = fabs(ans); return ans;

}
bool check(double x, double y){
 double A = area(ar[v[0]].ff, ar[v[0]].ss.ff, ar[v[1]].ff, ar[v[1]].ss.ff, ar[v[2]].ff, ar[v[2]].ss.ff);
 double B = area(x, y, ar[v[1]].ff, ar[v[1]].ss.ff, ar[v[2]].ff, ar[v[2]].ss.ff);
 double C = area(ar[v[0]].ff, ar[v[0]].ss.ff, x, y, ar[v[2]].ff, ar[v[2]].ss.ff);
 double D = area(ar[v[0]].ff, ar[v[0]].ss.ff, ar[v[1]].ff, ar[v[1]].ss.ff, x, y);
 if (A == B + C + D)
  return true;
 return false;
}
int main()
{
 int n;
 cin >> n;
 f(i, 0, n){
  cin >> ar[i].ff >> ar[i].ss.ff;
  ar[i].ss.ss=i;
 }
 sort(ar, ar + n);
 f(i, 2, n){
  if (area(ar[i].ff,ar[i].ss.ff,ar[i-1].ff,ar[i-1].ss.ff,ar[i-2].ff,ar[i-2].ss.ff)){
   cout<<ar[i].ss.ss+1<<" "<<ar[i-1].ss.ss+1<<" "<<ar[i-2].ss.ss+1<<endl;
         break;
  }

 }

 return 0;
}