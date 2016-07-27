/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>

#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<utility>
#include<iostream>
#include<algorithm>

#include<bits/stdc++.h>
/* all header files included */

#define LL long long

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

#define pii pair<int,int>

#define nl printf("\n")
/* defining macros */

using namespace std;
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int main()
{
    int visited[22][22],matrix[22][22],i,j,k,w,h,t,x,y,tc=1,nx,ny,count;
    queue<pii>Q;
    pii top;

    cin>>t;
    while(t--)
    {
        cin>>w>>h;
        for(i=0; i<22; i++)
        {
            for(j=0; j<22; j++)
            {
                matrix[i][j]=visited[i][j]=0;
            }
        }
        for(i=1; i<=h; i++)
        {
            char ch[1001];
            scanf("%s",ch);
            for(j=0; j<strlen(ch); j++)
            {
                if(ch[j]=='#')
                    matrix[i][j+1]=-1;
                else if(ch[j]=='@')
                {
                    x=i;
                    y=j+1;
                }
            }

        }
        visited[x][y]=1;
        Q.push(pii(x,y));
        while(!Q.empty())
        {
            top=Q.front();
            x=top.first;
            y=top.second;
            for(i=0; i<4; i++)
            {
                nx=x+fx[i];
                ny=y+fy[i];
                if(nx>0 && nx<=h && ny>0 && ny<=w && visited[nx][ny]==0 && matrix[nx][ny]!=-1)
                {
                    visited[nx][ny]=1;
                    Q.push(pii(nx,ny));
                }
            }
            Q.pop();
        }
        count=0;
        for(i=1; i<=h; i++)
        {
            for(j=1; j<=w; j++)
            {
                if(visited[i][j])
                {
                    count++;
                }
            }
        }
        printf("Case %d: %d\n",tc++,count);
    }
    return 0;
}
