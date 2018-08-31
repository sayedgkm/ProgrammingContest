#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               305
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              (1e9)+1000
#define        eps                             1e-9
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
char s1[105],s2[105],s3[305];
int dp[105][105][305];
int len1,len2,len3;
int Next[N][26];
int go(int i,int j,int k) {
    if(i==len1&&j==len2) {
        if(k<=len3) return 0;
        return inf;
    }
    if(k>=len3) return inf;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int res = inf;
    if(s1[i]==s2[j]) {
        res=min(res,go(i+1,j+1,Next[k][s1[i]-'a'])+1);

    } else {
        if(i<len1)
        res=min(res,go(i+1,j,Next[k][s1[i]-'a'])+1);
        if(j<len2)
        res=min(res,go(i,j+1,Next[k][s2[j]-'a'])+1);
    }

    return dp[i][j][k]=res;
}
int dp1[105][105][305];

int cnt[26];

int go1(int i,int j,int k) {
    //debug(i,j,k,s1[i],s2[j]);
    if(i==len1&&j==len2) return k<=len3;
    if(k>=len3) return 0;
    if(dp1[i][j][k]!=-1) return dp1[i][j][k];
    int lc = go(i,j,k);
    ll res = 0;
    if(s1[i]==s2[j]&&i<len1&&j<len2&&lc-1==go(i+1,j+1,Next[k][s1[i]-'a'])) {
        res+=go1(i+1,j+1,Next[k][s1[i]-'a']);
        res%=M;
    } else {
        if(i<len1)
            if(go(i+1,j,Next[k][s1[i]-'a'])==lc-1) res+=go1(i+1,j,Next[k][s1[i]-'a']),res%=M;
        if(j<len2){
            if(go(i,j+1,Next[k][s2[j]-'a'])==lc-1) res+=go1(i,j+1,Next[k][s2[j]-'a']);
        }
        res%=M;

    }
    return dp1[i][j][k]=(int)res;
}
string ans;
void print(int i,int j,int k) {
   // debug(i,j,k);
    if(i==len1&&j==len2) {
        return;
    }
    int lc = go(i,j,k);
    if(s1[i]==s2[j]&&i<len1&&j<len2&&go(i+1,j+1,Next[k][s1[i]-'a'])==lc-1) {
        ans+=s1[i];
        print(i+1,j+1,Next[k][s1[i]-'a']);
    } else {
        if(i<len1&&j<len2){
            if(lc-1==go(i+1,j,Next[k][s1[i]-'a'])&&lc-1==go(i,j+1,Next[k][s2[j]-'a'])) {
                if(s1[i]<s2[j]) {
                    ans+=s1[i];
                    print(i+1,j,Next[k][s1[i]-'a']);
                } else {
                    ans+=s2[j];
                    print(i,j+1,Next[k][s2[j]-'a']);
                }
            } else if(lc-1==go(i+1,j,Next[k][s1[i]-'a'])){
                ans+=s1[i];
                print(i+1,j,Next[k][s1[i]-'a']);
            } else {
                ans+=s2[j];
                print(i,j+1,Next[k][s2[j]-'a']);

            }
        } else if(i<len1) {
            ans+=s1[i];
            print(i+1,j,Next[k][s1[i]-'a']);
        } else {
            ans+=s2[j];
            print(i,j+1,Next[k][s2[j]-'a']);
        }



    }

}

int main(){
    #ifdef sayed
    freopen("out.txt","w",stdout);
     freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    int cs = 1;
    while(test--) {
        scanf("%s%s%s",s1,s2,s3);
        len1 = strlen(s1);
        len2 = strlen(s2);
        len3 = strlen(s3);
        for(int i = 0;i<26;i++) cnt[i] = len3+5;
        for(int i = len3-1;i>=0;i--) {
            cnt[s3[i]-'a']= i;
            for(int j = 0;j<26;j++) Next[i][j] = cnt[j]+1;
        }

        SET(dp);
        SET(dp1);
        int tmp = go(0,0,0);
       // debug(tmp);
        int res;

        if(tmp<inf) {
            res = go1(0,0,0);
            print(0,0,0);
            printf("Case %d: %d\n",cs++,res);
            printf("%s\n",ans.c_str());
        } else printf("Case %d: 0\nNOT FOUND\n",cs++);
        ans.clear();
        CLR(cnt);
        CLR(Next);
    }


    return 0;
}
