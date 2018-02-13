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
#define        N                     100010
#define        M                     1000000007
#define        pi                    acos(-1.0)
#define        ff                    first
#define        ss                    second
#define        pb                    push_back
using namespace std;

struct st{
    double x,y;
}ar[N];
struct point{
  double x,y;
  point(){}
  point(double xx,double yy) {x=xx,y=yy;}
}P[N];
point centre;
struct vec{
  double x,y;
  vec(){}
  vec(point xx,point yy) {x=yy.x-xx.x,y=yy.y-xx.y;}

};
double dotproduct(vec a,vec b){
   return (a.x*b.x+a.y*b.y);
}
double crossproduct(vec a,vec b){
   return (a.x*b.y-a.y*b.x);
}
double norm_sq(vec a){
  return (a.x*a.x+a.y*a.y);
}
double angle(point A,point B,point C){ ///will return angle between ABC in Radian
    vec BA(B,A),BC(B,C);
   return acos(dotproduct(BA,BC)/sqrt(norm_sq(BA)*norm_sq(BC)));
}
double triangleArea(point a,point b,point c) {  /// Area without division by 2
    double area=a.x*b.y+b.x*c.y+c.x*a.y;
    area-=(b.x*a.y+c.x*b.y+a.x*c.y);
    return area;
}
double area(int n){  /// Area of n-gon without division by 2
    double A=0;
     P[n].x=P[0].x;
     P[n].y=P[0].y;
    for(int i=0;i<n;i++){
        A+=(P[i].x*P[i+1].y-P[i+1].x*P[i].y);
    }
    return A<0?-A:A;
}
double Distance(point a,point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double pointSegmentDistance(point C,point A,point B) { ///AB is line segment and c is point
   vec BA(B,A);
   vec AB(A,B);
   vec AC(A,C);
   vec BC(B,C);
   double dot = dotproduct(BA,AC);
   if(dot>=0) return Distance(A,C);
   dot = dotproduct(AB,BC);
   if(dot>=0) return Distance(B,C);
   return fabs(crossproduct(AB,AC)/sqrt(norm_sq(AB)));  /// magnitude of vector AB = sqrt(norm_sq(AB));
}
int main()
{
    int n;
    cin>>n>>centre.x>>centre.y; double mini=1e8,mx=0;pii value;
     double low=1e8;
    f(i,0,n){
        cin>>P[i].x>>P[i].y;
          mx=max(mx,Distance(centre,P[i]));
        if(i){

         mini=min(mini,pointSegmentDistance(centre,P[i],P[i-1]));
        }
    }
    mini=min(mini,pointSegmentDistance(centre,P[n-1],P[0]));
    double ans=pi*(mx*mx-mini*mini);
    printf("%.20lf\n",ans);
   return 0;
}