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
int visited[N], level[N];
int bfs(int a, int b){
    queue<int> q;
    q.push(a);
    visited[a] = 1;
    level[a] = 0;
    while (!q.empty()){
        int f = q.front(); q.pop();
        if (f == b) return level[f];
        int m = f - 1;
        int n = f * 2;
        if (!visited[m]&&m<90000){
            level[m] = min(level[f] + 1, level[m]);
            visited[m] = 1;
            q.push(m);

        }
        if (!visited[n] && n<90000)
        {
            level[n] = min(level[n], level[f] + 1);
            visited[n] = 1;
            q.push(n);

        }
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0);
    f(i,0,N) level[i]=1e8;
    take2(x, y);
    cout << bfs(x, y) << endl;

    return 0;
}