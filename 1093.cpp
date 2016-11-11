/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define iin(x)        scanf("%d",&x)
#define din(x)        scanf("%lf",&x)
#define lin(x)        scanf("%lld",&x)
#define clin(x)       scanf("%I64d",&x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define fast          ios::sync_with_stdio(0)
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"yes":"no")
/* macro definitions */

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definitions */

LL MOD_EXPO(LL b, LL p, LL m)
{
    if(p==0) return 1;
    LL ret=MOD_EXPO(b,p/2,m)%m;
    ret=(ret*ret)%m;
    return ((p&1) ? (ret*b)%m : ret%m);
}
LL POWER(LL N, LL K)
{
    LL i,ans=1;
    for(i=1; i<=K; i++) ans*=N;
    return ans;
}
int SET(int N, int pos)
{
    return (N | (1<<pos));
}
int RESET(int N, int pos)
{
    return (N & !(1<<pos));
}
bool CHECK(int N, int pos)
{
    return (N & (1<<pos));
}
/* necessary functions */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction arrays */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declarations */

struct ST
{
    int mini,maxi;
};

ST tree[4*mx+5];
int arr[mx+5];

void build(int node, int begin, int end)
{
    if(begin==end)
    {
        tree[node].mini=arr[begin];
        tree[node].maxi=arr[begin];
        return;
    }
    int l,r,mid;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;
    build(l,begin,mid);
    build(r,mid+1,end);
    tree[node].mini=min(tree[l].mini,tree[r].mini);
    tree[node].maxi=max(tree[l].maxi,tree[r].maxi);
    return;
}

ST query(LL node, LL begin, LL end, LL a, LL b)
{
    if(b<begin || a>end) return tree[0];
    if(begin>=a && end<=b) return tree[node];
    int l,r,mid;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;

    ST L=query(l,begin,mid,a,b);
    ST R=query(r,mid+1,end,a,b);
    ST ret;
    ret.mini=min(L.mini,R.mini);
    ret.maxi=max(L.maxi,R.maxi);
    return ret;
}

int main()
{
    int i,n,d,ans,t;
    ST get;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        for(i=1; i<=n; i++) iin(arr[i]);
        tree[0].maxi=INT_MIN;
        tree[0].mini=INT_MAX;
        build(1,1,n);
        ans=0;
        for(i=1; i<=n-d+1; i++)
        {
            get=query(1,1,n,i,i+d-1);
            ans=max(ans,get.maxi-get.mini);
        }
        tc1(tc++);
        pr1(ans);
    }
    return 0;
}
