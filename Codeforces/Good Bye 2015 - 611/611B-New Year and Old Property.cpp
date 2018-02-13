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
vector<int>bin;
ll pow1(ll a, ll b){
    ll mul = 1;
    f(i, 0, b) mul *= a; return mul;

}
void fun(ll a){

    while (a){
        bin.push_back(a % 2);
        a /= 2;
    }

    reverse(bin.begin(), bin.end());
}
ll fun1(){
    ll sum = 0; ll p = 0;
    for (ll i = bin.size() - 1; i >= 0; i--){
        sum += pow1(2, p++)*bin[i];

    }
    return sum;

}
int main()
{
    ll a, b;
    cin >> a >> b;
    fun(a);
    bin[0] = 0;
    bin[1] = 1;
    for (ll i = 2; i<bin.size(); i++)
        bin[i] = 1;
    ll p = 0;
    ll ans = 0;
    while (1){
        ll result = fun1();
        //cout<<result<<endl;
        if (result>b) break;
        if (result >= a&&result <= b) ans++;
        if (bin[bin.size() - 1] == 0){
            bin[bin.size() - 1] == 1;
            bin.push_back(1);
            bin[0] = 0;
            bin[1] = 1; p = 0;
            for (ll i = 2; i<bin.size(); i++)
                bin[i] = 1;
        }
        bin[p] = 1;
        bin[p + 1] = 0;
        p++;


    }
    cout << ans << endl;

    return 0;
}