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
int r, g, b;
int n;
string s;
int dp[205][205][205];
void go(int red, int blue, int green)
{
    if(dp[red][blue][green]) return ;
    dp[red][blue][green]=1;
    if (red <= 0 && blue <= 0 && green <= 0)
    {
        return;
    }
    if (red == 1 && blue == 0 && green == 0)
    {
        r = 1;
        return;
    }
    if (red == 0 && blue == 0 && green == 1)
    {
        g = 1;
        return;
    }
    if (red == 0 && blue == 1 && green == 0)
    {
        b = 1;
        return;
    }
    if (red >= 1 && blue >= 1)
        go(red - 1, blue - 1, green + 1);
    if (red >= 1 && green >= 1)
        go(red - 1, blue + 1, green-1 );
    if (blue >= 1 && green >= 1)
        go(red + 1, blue - 1, green-1);
    if (red >= 2)
        go(red - 1, blue, green);
    if (blue >= 2)
        go(red, blue - 1, green);
    if (green >= 2)
        go(red, blue, green - 1);

}
int main()
{

    cin >> n;
    cin >> s;
    int red = 0, blue = 0, green = 0;
    f(i, 0, n)
    {
        if (s[i] == 'R') red++;
        if (s[i] == 'G') green++;
        if (s[i] == 'B') blue++;
    }
    go(red, blue, green);

    if (b) printf("B");;
    if (g) printf("G");
    if (r)printf("R");
    return 0;
}
