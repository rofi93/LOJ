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
const long long int mx=3e4;
const long long int mod=1e9+7;
/* global declarations */

int tree[4*mx+5];
int arr[mx+5];
int R_Idx,L_Idx;

void build(int node, int begin, int end)
{
    if(begin==end)
    {
        tree[node]=arr[begin];
        return;
    }
    int l,r,mid;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;
    build(l,begin,mid);
    build(r,mid+1,end);
    tree[node]=min(tree[l],tree[r]);
    return;
}

int query_right(int node, int begin, int end, int a, int b, int val)
{
    if(b<begin || a>end || begin>end || a>b) return INT_MAX;
    if(begin==end) return tree[node];
    if(begin>=a && end<=b && tree[node]>=val) return tree[node];
    int l,r,mid,L=INT_MAX,R=INT_MAX;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;
    L=query_right(l,begin,mid,a,b,val);
    if(L>=val && L!=INT_MAX) R=query_right(r,mid+1,end,a,b,val);
    if(L>=val && L!=INT_MAX) R_Idx=max(R_Idx,mid);
    if(R>=val && R!=INT_MAX) R_Idx=max(R_Idx,end);
    //pr2(L,R);
    return min(L,R);
}

int query_left(int node, int begin, int end, int a, int b, int val)
{
    if(b<begin || a>end || begin>end || a>b) return INT_MAX;
    if(begin==end) return tree[node];
    if(begin>=a && end<=b && tree[node]>=val) return tree[node];
    int l,r,mid,L=INT_MAX,R=INT_MAX;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;
    R=query_left(r,mid+1,end,a,b,val);
    //pr1(R);
    if(R>=val && R!=INT_MAX) L=query_left(l,begin,mid,a,b,val);
    if(R>=val && R!=INT_MAX) L_Idx=min(L_Idx,mid+1);
    if(L>=val && L!=INT_MAX) L_Idx=min(L_Idx,begin);
    //pr3(begin,end,L_Idx);
    //pr2(L,R);
    return min(L,R);
}

void reset(void)
{
    int i;
    for(i=0; i<=4*mx; i++) tree[i]=INT_MAX;
    return;
}

int main()
{
    int t,n,i,area,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1; i<=n; i++) iin(arr[i]);
        reset();
        build(1,1,n);
        area=0;
        for(i=1; i<=n; i++)
        {
            L_Idx=i;
            R_Idx=i;
            query_left(1,1,n,1,i,arr[i]);
            query_right(1,1,n,i,n,arr[i]);
            pr3(i,L_Idx,R_Idx);
            area=max(area,arr[i]*(R_Idx-L_Idx+1));
        }
        tc1(tc++);
        pr1(area);
    }
    return 0;
}
