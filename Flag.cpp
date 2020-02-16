#include<bits/stdc++.h>
using namespace std;
long long dp[50][5][5];
int n;

long long flag(int pos,int prev,int prev2)
{
    long long ans=0;
    if(pos==n+1)
        return 1;
    if(dp[pos][prev][prev2]!=-1)
        return dp[pos][prev][prev2];

    if(prev==1)
    {


        ans+=flag(pos+1,3,prev);
        if(pos!=n)
            ans+=flag(pos+1,2,prev);
        dp[pos][prev][prev2]=ans;

        return dp[pos][prev][prev2];


    }
    if(prev==3)
    {

        ans=flag(pos+1,1,prev);
        if(pos!=n)
            ans+=flag(pos+1,2,prev);
        dp[pos][prev][prev2] =ans;

        return dp[pos][prev][prev2];
    }
    if(prev==2)
    {

        if(prev2==1)
            ans+= flag(pos+1,3,prev);
		//cout<<"hello"<<endl;
        else
            ans+=flag(pos+1,1,prev);
		//cout<<"hello 1"<<endl;
        dp[pos][prev][prev2]=ans;


        return dp[pos][prev][prev2];
    }
}

int main()
{

    cin>>n;
    memset(dp,-1,sizeof dp);
    long long sum= flag(2,3,-1)+flag(2,1,-1);
    cout<<sum<<endl;
}
