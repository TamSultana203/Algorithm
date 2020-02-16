#include<iostream>
#include<stdio.h>
int n,a[10005],l;
 long long dp[1000005];

void make_array()
{
    int i;
    a[0]=1;
    for( i=1; i<=20; i++)
    {
       a[i]=a[i-1]*2;
       
    }

}

void way_count()
{
    dp[0]=1;
    for(int c=0; c<=20; c++)
    {
        for(int j=a[c]; j<=n; j++)
        {
            dp[j]+=dp[j-a[c]];
		//cout<<"Work u dipshit"<<endl;
            if(dp[j]>1000000000) 
		//cout<<"hi hi"<<endl;
            dp[j]-=1000000000;
        }

    }
}

int main()
{
     make_array();
    scanf("%d",&n);
    way_count();
    long long way=dp[n];
    printf("%lld\n",way);
    return 0;
}

