#include<stdio.h>
int main()
{
    long int n,t,i,j,k,count,x[100];
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld",&n);
        count=0;
        for(j=0;;j++)
        {
            x[j]=n%2;
            if(x[j]==1)
                count++;
            if(n==0)
                break;
            n=n/2;
        }
        if(count%2==0)
            printf("Case %ld: even\n",i);
        else
            printf("Case %ld: odd\n",i);
    }
    return 0;
}
