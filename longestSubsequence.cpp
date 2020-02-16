#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[1005][1005];
int lcs(int i,int j)
{

    int ans=0;
    if(i<0 || j<0)
        return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];

	if(s1[i]==s2[j])
	return dp[i][j]=1+lcs(i-1,j-1);
	ans=max(lcs(i-1,j),lcs(i,j-1));
	ans=max(lcs(i-1,j-1),ans);
	return dp[i][j]=ans;

}
int main()
{

    while(getline(cin,s1))
    {
        getline(cin,s2);
        memset(dp,-1,sizeof dp);
        int l=lcs(s1.length()-1,s2.length()-1);
        cout<<l<<endl;
    }
    return 0;
}
//longest string
