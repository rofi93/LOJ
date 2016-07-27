#include<stdio.h>
#include<string.h>
int main()
{
    long int i,t,j,n,k,sum;
    char x[20];
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld",&n);
        sum=0;
        printf("Case %ld:\n",i);
        for(j=0;j<n;j++)
        {
            scanf("%s",x);
            if(x[0]=='d' || x[0]=='D')
            {
                scanf("%ld",&k);
                sum+=k;
            }
            else
                printf("%ld\n",sum);
        }
    }
    return 0;
}
