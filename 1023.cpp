#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int fact(int n)
{
    int i,sum=1;
    for(i=1; i<=n; i++)
    {
        sum=sum*i;
    }
    return sum;
}
int main()
{
    char str[27];
    int i,t,c=1,n,k,count,sum;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0; i<n; i++)
        {
            str[i]=i+65;
        }
        printf("Case %d:\n",c++);
        if(n<=4)
        {
            sum=fact(n);
            if(sum<k)
                k=sum;
        }
        count=0;
        while(count<k)
        {
            printf("%s\n",str);
            count++;
            next_permutation(str,str+n);
        }
        for(i=0;i<27;i++)
            str[i]='\0';
    }
    return 0;
}
