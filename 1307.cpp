/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)
#define mp(a,b)       make_pair(a,b)

#define set0(a)       memset(a,0,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"First":"Second")
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
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=2000;
const long long int mod=1000000007;
/* global declaration */

LL x[mx+5];

LL BS(LL val, LL l, LL r)
{
    LL mid,ans=l-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(x[mid]<val) l=mid+1,ans=mid;
        else r=mid-1;
    }
    return ans;
}

void combine(int p, int q, int r)
{
    int i,j,k,n1,n2,L[mx+5],R[mx+5];

    n1=q-p+1;
    n2=r-q;
    for(i=1;i<=n1;i++) L[i]=x[p+i-1];
    for(j=1;j<=n2;j++) R[j]=x[q+j];
    L[i]=R[j]=INT_MAX;

    i=j=1;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j]) x[k]=L[i++];
        else x[k]=R[j++];
    }
}

void merge_sort(int p, int r)
{
    if(p>=r) return;

    int q=(p+r)/2;
    merge_sort(p,q);
    merge_sort(q+1,r);
    combine(p,q,r);
}

int main()
{
    LL t,n,i,j,ans,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++) scanf("%lld",&x[i]);
        //sort(x,x+n);
        merge_sort(1,n);
        ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                a=BS(x[i]+x[j],j+1,n);
                ans+=a-j;
            }
        }
        tc1(tc++);
        pr1(ans);
    }
    return 0;
}
