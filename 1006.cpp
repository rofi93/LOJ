/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>

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
#define setinf(a)   memset(a,126,sizeof(a))

#define tc1(x)      printf("Case %d: ",x)
#define tc2(x)      printf("Case #%d: ",x)
#define tc3(x)      printf("Case %d:\n",x)

#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"
/* defining macros */

using namespace std;

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
/* global declaration */

LL a, b, c, d, e, f;
LL dp[10001];
const LL MOD = 10000007;

void reset(void)
{
    int i;
    for(i=0; i<10001; i++)
        dp[i]=-1;
}

LL fn( LL n )
{
    if( n == 0 )
        return a;
    if( n == 1 )
        return b;
    if( n == 2 )
        return c;
    if( n == 3 )
        return d;
    if( n == 4 )
        return e;
    if( n == 5 )
        return f;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=( (fn(n-1)%MOD) + (fn(n-2)%MOD) + (fn(n-3)%MOD) + (fn(n-4)%MOD) + (fn(n-5)%MOD) + (fn(n-6)%MOD) )%MOD;

    return dp[n];
}

int main()
{
    LL t,n;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&n);
        reset();
        tc1(tc++);
        pr1(fn(n)%MOD);
    }
    return 0;
}
