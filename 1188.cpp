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

struct query_class
{
    int idx,l,r;
    query_class(int a, int b, int c)
    {
        l=a;
        r=b;
        idx=c;
    }
    query_class()
    {

    }
};

bool operator<(query_class A, query_class B)
{
    return A.r<B.r;
}

int tree[3*mx+5];
int prev[mx+5];
int arr[mx+5];
int res[mx+5];

void update(int node, int begin, int end, int idx, int val)
{
    if(idx<begin || idx>end) return;
    if(begin==idx && idx==end)
    {
        tree[node]=val;
        return;
    }
    int l,r,mid;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;

    update(l,begin,mid,idx,val);
    update(r,mid+1,end,idx,val);
    tree[node]=tree[l]+tree[r];
    return;
}

int query(int node, int begin, int end, int a, int b)
{
    if(b<begin || a>end) return 0;
    if(begin>=a && end<=b) return tree[node];
    int l,r,mid,L,R;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;
    L=query(l,begin,mid,a,b);
    R=query(r,mid+1,end,a,b);
    return L+R;
}

int main()
{
    int t,n,q,a,b,i,k;
    cin>>t;
    while(t--)
    {
        vector<query_class>vp;
        setzero(tree);
        setzero(prev);
        iin(n);
        iin(q);
        for(i=1; i<=n; i++) iin(arr[i]);
        for(i=1; i<=q; i++)
        {
            iin(a);
            iin(b);
            vp.pb(query_class(a,b,i));
        }
        sort(vp.begin(),vp.end());
        k=0;
        for(i=1; i<=n; i++)
        {
            a=arr[i];
            update(1,1,n,i,1);
            update(1,1,n,prev[a],0);
            prev[a]=i;
            while(k<q && vp[k].r==i)
            {
                a=query(1,1,n,vp[k].l,vp[k].r);
                b=vp[k].idx;
                res[b]=a;
                k++;
            }
        }
        tc3(tc++);
        for(i=1; i<=q; i++) printf("%d\n",res[i]);
    }
    return 0;
}
