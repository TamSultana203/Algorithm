#include<bits/stdc++.h>
using namespace std;
int len;
string a;
int dp[1005][1005];
int palindrome(int i,int j)
{
    if(i==j)
        return 0;
    if(i>j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i]==a[j])
    {
        dp[i][j]=palindrome(i+1,j-1);
        return dp[i][j];
    }
///replace kori jokhon : palindrom(i+1,j-1)+1
///a[j] delete kori jokhon : palindrome(i,j-1)+1;
///a[i[ delete kori jokhon : palindrome (i+1,j)+1;

    dp[i][j]=min(palindrome(i+1,j-1)+1 , palindrome(i,j-1)+1 );
    dp[i][j]=min(palindrome(i+1,j)+1 , dp[i][j]);
    return dp[i][j];
}
int main()
{
    int t;
    cin>>t;
    for(int z=1; z<=t; z++)
    {
        cin>>a;
        len=a.length();
        memset(dp,-1,sizeof dp);
        int cnt=palindrome(0,len-1);
        printf("Case %d: %d\n",z,cnt);

    }
    return 0;
}

