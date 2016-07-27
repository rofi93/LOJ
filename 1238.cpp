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
#define nl printf("\n")
#define pii pair<int,int>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
/* defining macros */

using namespace std;

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
/* direction array */

int visited[20][20],level[20][20],m,n;
char maps[20][21];

bool OK(int x, int y)
{
    if(x>=0 && x<m && y>=0 && y<n && maps[x][y]!='#' && maps[x][y]!='m' && visited[x][y]==0)
        return true;
    return false;
}
int bfs(int x, int y)
{
    queue<pii>Q;
    int i,j,k,nx,ny;
    pii top;

    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            visited[i][j]=level[i][j]=0;
        }
    }
    level[x][y]=0;
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
            if(OK(nx,ny))
            {
                level[nx][ny]=level[x][y]+1;
                visited[nx][ny]=1;
                Q.push(pii(nx,ny));
                if(maps[nx][ny]=='h')
                {
                    return level[nx][ny];
                }
            }
        }
        Q.pop();
    }
    return 0;
}
int main()
{
    int t,i,j,k,a,b,c,max,tc=1;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(i=0; i<20; i++)
        {
            for(j=0; j<21; j++)
            {
                maps[i][j]='\0';
            }
        }
        for(i=0; i<m; i++)
        {
            scanf("%s",maps[i]);
        }
        max=0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(maps[i][j]=='a')
                {
                    a=bfs(i,j);
                }
                else if(maps[i][j]=='b')
                {
                    b=bfs(i,j);
                }
                else if(maps[i][j]=='c')
                {
                    c=bfs(i,j);
                }
            }
        }
        if(a>max)
            max=a;
        if(b>max)
            max=b;
        if(c>max)
            max=c;
        printf("Case %d: %d\n",tc++,max);
    }
    return 0;
}
