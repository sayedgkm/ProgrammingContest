#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2, edges, last[MAXN1], prv[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    prv[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prv[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prv[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
map<pair<int,int> ,int> mp;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int test;
    scanf("%d",&test);
    while(test--) {
        int p;
        scanf("%d",&p);
        init(p+1,p+1);
        int e;
        scanf("%d",&e);
        for(int i = 0;i<e;i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            mp[make_pair(a,b)]=1;
        }
        for(int i = 1;i<=p;i++) {
            for(int j = 1;j<=p;j++) {
                if(mp.count(make_pair(i,j))) continue;
                addEdge(i,j);
            }
        }
        printf("%d\n",p+p-maxMatching());
        mp.clear();
    }

    return 0;
}

