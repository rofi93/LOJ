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
    if(p==0)
        return 1;
    LL ret=MOD_EXPO(b,p/2,m)%m;
    ret=(ret*ret)%m;
    return ((p&1) ? (ret*b)%m : ret%m);
}
LL POWER(LL N, LL K)
{
    LL i,ans=1;
    for(i=1; i<=K; i++)
        ans*=N;
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
const long long int mx=2e4;
const long long int mod=1e9+7;
/* global declarations */

int root;
int low[mx+5];
vi edges[mx+5];
int parent[mx+5];
int current_time;
bool visited[mx+5];
int discovery[mx+5];
bool is_articulation_point[mx+5];

void find_articulation_points(int node)
{
    int i,x,children;

    children=0;
    current_time++;
    visited[node]=true;
    low[node]=current_time;
    discovery[node]=current_time;

    for(i=0; i<edges[node].size(); i++)
    {
        x=edges[node][i];

        if(x==parent[node])
            continue;

        if(!visited[x])
        {
            children++;
            parent[x]=node;
            find_articulation_points(x);
            low[node]=min(low[node],low[x]);

            if(node!=root && discovery[node]<=low[x])
                is_articulation_point[node]=true;
        }
        else
        {
            low[node]=min(low[node],discovery[x]);
        }
    }

    if(children>1 && node==root)
        is_articulation_point[node]=true;

    return;
}

void clean(void)
{
    int i;
    for(i=0; i<=mx; i++)
    {
        low[i]=0;
        parent[i]=0;
        discovery[i]=0;
        visited[i]=false;
        edges[i].clear();
        is_articulation_point[i]=0;
    }
}

int main()
{
    int t,i,n,m,a,b,ans;

    cin>>t;
    while(t--)
    {
        clean();

        cin>>n>>m;
        for(i=1; i<=m; i++)
        {
            iin(a);
            iin(b);
            edges[a].pb(b);
            edges[b].pb(a);
        }

        ans=0;
        root=1;
        current_time=0;
        find_articulation_points(root);

        for(i=1; i<=n; i++)
        {
            if(is_articulation_point[i])
                ans++;
        }

        tc1(tc++);
        pr1(ans);
    }

    return 0;
}
