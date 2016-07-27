#include<stdio.h>
int main()
{
    unsigned long long int t,i,a,b,c,x,y,z;
    scanf("%llu",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%llu %llu %llu",&a,&b,&c);
        if(a>=b && a>=c)
        {
            x=a;
            y=b;
            z=c;
        }
        else if(b>=a && b>=c)
        {
            x=b;
            y=a;
            z=c;
        }
        else if(c>=a && c>=b)
        {
            x=c;
            y=a;
            z=b;
        }
        printf("Case %llu: ",i);
        if(x*x==(y*y)+(z*z))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
