/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9

#define fs          first
#define sc          second
#define pb(a)       push_back(a)
#define mp(a,b)     make_pair(a,b)
#define sp          printf(" ")
#define nl          printf("\n")

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define tc1(x)      printf("Case %d: ",x)
#define tc2(x)      printf("Case #%d: ",x)
#define tc3(x)      printf("Case %d:\n",x)
#define tc4(x)      printf("Case #%d:\n",x)

#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"
/* defining macros */

using namespace std;

template <class T> inline T bigmod(T b, T p, T m)
{
    T ret;
    if(p==0) return 1;
    if(p&1)
    {
        ret=(bigmod(b,p/2,m)%m);
        return ((b%m)*ret*ret)%m;
    }
    else
    {
        ret=(bigmod(b,p/2,m)%m);
        return (ret*ret)%m;
    }
}
template <class T> inline T _sqrt(T a)
{
    return (T)sqrt((double)a);
}
template <class T, class X> inline T _pow(T a, X b)
{
    T res=1;
    for(int i=1; i<=b; i++)
        res*=a;
    return res;
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef pair<double, double>pdd;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<double>vd;
/* type definition */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int tc=1;
const long long int mx=100000;
/* global declaration */

int arr[mx+5];
int tree[3*mx+5];

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void add_money(int node, int b, int e, int i, int money)
{
    if(i>e || i<b)
        return;
    if(b==e)
    {
        tree[node]+=money;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    add_money(left,b,mid,i,money);
    add_money(right,mid+1,e,i,money);
    tree[node]=tree[left]+tree[right];
}

void give_money(int node, int b, int e, int i)
{
    if(i>e || i<b)
        return;
    if(b==e)
    {
        printf("%d\n",tree[node]);
        tree[node]=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    give_money(left,b,mid,i);
    give_money(right,mid+1,e,i);
    tree[node]=tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int sum1=query(left,b,mid,i,j);
    int sum2=query(right,mid+1,e,i,j);
    return sum1+sum2;
}

int main()
{
    int t,i,j,n,q,cmd;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build(1,1,n);
        tc3(tc++);
        while(q--)
        {
            scanf("%d",&cmd);
            if(cmd==1)
            {
                scanf("%d",&i);
                i++;
                give_money(1,1,n,i);
                arr[i]=0;
            }
            else if(cmd==2)
            {
                scanf("%d %d",&i,&j);
                i++;
                add_money(1,1,n,i,j);
                arr[i]+=j;
            }
            else if(cmd==3)
            {
                scanf("%d %d",&i,&j);
                i++;j++;
                printf("%d\n",query(1,1,n,i,j));
            }
        }
    }
    return 0;
}
