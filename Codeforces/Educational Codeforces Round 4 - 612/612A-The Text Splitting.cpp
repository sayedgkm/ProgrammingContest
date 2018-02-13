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
int ar[N];
int main()
{
    take3(a, b, c); int x = 0, y = 0;
    string s;
    cin >> s;
    int temp = a; int check = 0;
    while (a>=0){
        if (a%c == 0){
            y = a / c;
            check = 1; break;
        }
        x++;
        a -= b;


    }
    if (check){
        cout << x + y << endl; int i = 0, d = 0;
        for (i = 0; i<x*b; i++){
            cout << s[i];
            d++;
            if (d%b == 0) cout << "\n";

        }
        d = 0;
        for (; i<temp; i++){
            cout << s[i];
            d++;
            if (d%c == 0) cout << "\n";

        }
        return 0;
    }

    puts("-1");


    return 0;
}