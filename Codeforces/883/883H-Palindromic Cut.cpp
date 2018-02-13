#pragma comment(linker, "/stack:640000000")

#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define ll long long int
#define scanl(a) scanf("%lld",&a)
#define scanii(a,b) scanf("%d%d",&a,&b)
#define scaniii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scanll(a,b) scanf("%lld%lld",&a,&b)
#define scanlll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scani(a) scanf("%d",&a)
#define clr(a) memset(a,0,sizeof(a))
#define clr_(a) memset(a,-1,sizeof(a))
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) a*a
#define eps 1e-9
#define inf INT_MAX
#define pi acos(-1.0)
#define ff first
#define ss second
#define INF (ll)1e18
#define endl '\n'
#define m_p make_pair
#define vsort(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define UNIQUE(X) X.erase( unique( X.begin(), X.end() ), X.end() )
int fx[]={0,0,-1,1,-1,1,1,-1};
int fy[]={1,-1,0,0,1,1,-1,-1};
ll lcm(ll a,ll b){return (a/__gcd(a,b))*b;}
ll bigmod(ll a,ll p,ll mod){ll ans=1;while(p){if(p&1)ans=ans*a%mod;a=a*a%mod;p>>=1;}return ans;}
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0){ll y=power(x,n/2);return y*y;}else return x*power(x,n-1);}
struct point{double x,y;point(){}point(double xx,double yy){x=xx;y=yy;}};
inline double Distance(point  a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
#ifdef shaft
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
const int N=(int)1e5;



struct pall
{
    char c;
    int fr;
};

int pairr ;
int indiv ;

vector<pall> vec;

bool f(int n, int k)
{
    debug(n,k);
    if(n%2)
    {
        int even = ((n-1)*k)/2;
        int odd = k;

        int kk = pairr-even;

        if(kk<0) return false;

        int temp = indiv + (kk*2);

        if(temp!=odd)
        {
            return false;
        }
    }
    else
    {
        if(indiv) return false;
    }

    debug("ACCEPTED");
    return true;
}


void print(int n, int k)
{
    vector<string>ans;
    if(n%2)
    {
        debug("ASG")
        vector<char>mid;

        for(int i=0;i<vec.size();i++)
        {
            if(vec[i].fr%2)
            {
                vec[i].fr--;
                mid.pb(vec[i].c);
            }
        }

        int rem = k-mid.size();


        while(rem)
        {
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i].fr)
                {
                    mid.pb(vec[i].c);
                    mid.pb(vec[i].c);
                    vec[i].fr-=2;
                    rem-=2;
                }

                if(rem==0) break;
            }
        }

        debug(rem,mid.size(),"A")


        for(int i=0;i<k;i++)
        {

            string temp1="";
            //string temp2="";

            int lens=0;

            for(int j=0;j<vec.size();)
            {
                debug(j,vec[j].fr);
                if(vec[j].fr)
                {
                    temp1+=vec[j].c;
                    vec[j].fr-=2;
                }
                else
                {
                    j++;
                }

                debug(temp1)

                if(temp1.size()==n/2)
                {
                    string ulta = temp1;
                    reverse(ulta.begin(),ulta.end());

                    string res = temp1 + mid[i] + ulta;

                    ans.pb(res);
                    debug("RES: " , res);
                    break;
                }
            }

        }
    }
    else
    {
        //debug("ASGCHE")
        for(int i=0;i<k;i++)
        {
            string temp1="";
            //string temp2="";

            int lens=0;

            for(int j=0;j<vec.size();)
            {
                if(vec[j].fr)
                {
                    temp1+=vec[j].c;
                    vec[j].fr-=2;
                }
                else
                {
                    j++;
                }

                if(temp1.size()==n/2)
                {
                    string ulta = temp1;
                    reverse(ulta.begin(),ulta.end());

                    string res = temp1 + ulta;

                    ans.pb(res);
                    debug(res);
                    break;
                }
            }

        }
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        if(i) cout<<" "<<ans[i];
        else cout<<ans[i];
    }
    cout<<endl;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    #ifdef shaft
     //   freopen("in.txt","r",stdin);
        ///freopen("out.txt","w",stdout);
    #endif ///shaft

    int n,k;
    cin>>n;
    {

        vec.clear();
        string x;
        cin>>x;

        int freq[300];
        clr(freq);

        int len = x.length();

        for(int i=0;i<len;i++)
        {
            char c = x[i];
            freq[c]++;
        }

        for(int i=0;i<300;i++)
        {
            if(freq[i])
            {
                pall p;
                p.c = i;
                p.fr = freq[i];
                vec.pb(p);

                pairr+=(p.fr/2);
                indiv+=(p.fr%2);
            }
        }




        vector<int>div;
        int sq = sqrt(n);
        for(int i=1;i<=sq;i++)
        {
            if(n%i==0)
            {
                div.pb(i);
                if(i!=n/i) div.pb(n/i);
            }
        }

        sort(div.begin(),div.end());


        for(int i=div.size()-1;i>=0;i--)
        {
            if(f(div[i],n/div[i]))
            {
                print(div[i],n/div[i]);
                break;
            }
        }


    }

    return 0;
}