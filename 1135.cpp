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

struct st
{
    int mul[3];
    int lazy;
};

st tree[3*mx+5];

void build(int node, int begin, int end)
{
    if(begin==end)
    {
        tree[node].lazy=0;
        tree[node].mul[0]=1;
        tree[node].mul[1]=0;
        tree[node].mul[2]=0;
        return;
    }
    int i,l,r,mid;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;

    build(l,begin,mid);
    build(r,mid+1,end);

    tree[node].mul[0]=tree[l].mul[0]+tree[r].mul[0];
    tree[node].mul[1]=0;
    tree[node].mul[2]=0;
    tree[node].lazy=0;
    return;
}

void swap(int node)
{
    int tmp;
    tmp=tree[node].mul[2];
    tree[node].mul[2]=tree[node].mul[1];
    tree[node].mul[1]=tree[node].mul[0];
    tree[node].mul[0]=tmp;
    return;
}

void propagate(int node, int begin, int end)
{
    int l,r;

    l=2*node;
    r=2*node+1;

    tree[l].lazy=(tree[l].lazy+tree[node].lazy)%3;
    tree[r].lazy=(tree[r].lazy+tree[node].lazy)%3;
    tree[node].lazy=tree[node].lazy%3;

    while(tree[node].lazy)
    {
        swap(l);
        swap(r);
        tree[node].lazy--;
    }
    return;
}

void update(int node, int begin, int end, int a, int b)
{
    if(b<begin || a>end) return;
    if(begin>=a && end<=b)
    {
        int tmp;
        tree[node].lazy=(tree[node].lazy+1)%3;
        swap(node);
        return;
    }
    int i,l,r,mid;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;

    if(tree[node].lazy) propagate(node,begin,end);

    update(l,begin,mid,a,b);
    update(r,mid+1,end,a,b);
    for(i=0; i<3; i++)
    {
        tree[node].mul[i]=tree[l].mul[i]+tree[r].mul[i];
    }
    return;
}

int query(int node, int begin, int end, int a, int b)
{
    if(b<begin || a>end) return 0;
    if(begin>=a && end<=b) return tree[node].mul[0];
    int i,l,r,mid,L,R;
    l=2*node;
    r=2*node+1;
    mid=(begin+end)/2;

    if(tree[node].lazy) propagate(node,begin,end);

    L=query(l,begin,mid,a,b);
    R=query(r,mid+1,end,a,b);
    return L+R;
}

int main()
{
    int t,type,n,q,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        build(1,1,n);
        tc3(tc++);
        while(q--)
        {
            iin(type);
            if(type)
            {
                iin(a);
                iin(b);
                printf("%d\n",query(1,1,n,a+1,b+1));
            }
            else
            {
                iin(a);
                iin(b);
                update(1,1,n,a+1,b+1);
            }
        }
    }
    return 0;
}
