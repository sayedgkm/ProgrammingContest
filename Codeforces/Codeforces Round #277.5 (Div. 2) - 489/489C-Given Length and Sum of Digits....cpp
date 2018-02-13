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
#define        ff                    first
#define        ss                    second
#define        pb                    push_back
using namespace std;
bool possible(int a,int b){
        if(b*9>=a) return true;
        else return false;
}
int main()
{
    take2(k,n);
    if(k==1&&n==0){
        puts("0 0");
        return 0;
    }
    if(k*9<n||n==0){
        puts("-1 -1"); return 0;
    }
    int temp=n; string small,big;
    for(int i=1;i<=k;i++){
          for(int j=0;j<10;j++){
            if(possible(n-j,k-i)){
                if(i==1&&j==0) continue;
                    small.push_back(j+'0');
                  n-=j;
                break;
            }

        }
    }
         n=temp;
    for(int i=1;i<=k;i++){
           for(int j=9;j>=0;j--){
            if(possible(n-j,k-i)&&(n-j)>=0){
                    big+=(j+'0');
                    n-=j;
              // cout<<i<<" "<<j<<" "<<n<<endl;
               // puts("b");
                break;
            }

        }
    }

cout<<small<<" "<<big<<endl;
   return 0;
}