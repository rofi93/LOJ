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

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

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
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
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
const long long int mx=1e2;
const long long int mod=1e9+7;
/* global declaration */

int dp[mx+5][mx+5];
string a,b;
vi idx_a[30+5],idx_b[30+5];

int lcs(int i, int j)
{
    if(i==a.size() || j==b.size()) return 0;

    int &ret=dp[i][j];
    if(ret!=-1) return ret;

    ret=0;
    if(a[i]==b[j]) ret=lcs(i+1,j+1)+1;
    else ret=max(lcs(i+1,j),lcs(i,j+1));

    return ret;
}

void print_all_lcs(int i, int j, int k)
{
    if(k==0) return;
    char ch;
    int ai,bi;
    for(ch='a'; ch<='z'; ch++)
    {
        ai=lower_bound(idx_a[ch-'a'].begin(),idx_a[ch-'a'].end(),i)-idx_a[ch-'a'].begin();
        bi=lower_bound(idx_b[ch-'a'].begin(),idx_b[ch-'a'].end(),j)-idx_b[ch-'a'].begin();
        if(ai!=idx_a[ch-'a'].size() && bi!=idx_b[ch-'a'].size())
        {
            ai=idx_a[ch-'a'][ai];
            bi=idx_b[ch-'a'][bi];
            if(dp[ai][bi]==k)
            {
                printf("%c",ch);
                print_all_lcs(ai+1,bi+1,k-1);
                break;
            }
        }
    }
    return;
}

int main()
{
    int t,k,i;
    cin>>t;
    while(t--)
    {
        getchar();
        cin>>a>>b;
        for(i=0; i<=30; i++) idx_a[i].clear(),idx_b[i].clear();
        for(i=0; i<a.size(); i++) idx_a[a[i]-'a'].pb(i);
        for(i=0; i<b.size(); i++) idx_b[b[i]-'a'].pb(i);
        setneg(dp);
        tc1(tc++);
        k=lcs(0,0);
        if(k==0)
        {
            printf(":(");
            nl;
            continue;
        }
        print_all_lcs(0,0,k);
        nl;
    }
    return 0;
}
