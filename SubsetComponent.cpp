#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <utility>
typedef unsigned long long ull;
using namespace std;
int n;
vector<ull> d(20);
vector<int> p,rnk,num;
int find(int a){
    return p[a]==a?a:p[a]=find(p[a]);
}
bool same(int a,int b){
    return find(a)==find(b);
}
void merge(int a,int b){
    if(!same(a,b)){
        if(rnk[find(a)]>rnk[find(b)]){
            num[find(a)]+=num[find(b)];
            p[find(b)]=find(a);
        }
        else {
            num[find(b)]+=num[find(a)];
            p[find(a)]=find(b);
        }
        if(rnk[find(a)]==rnk[find(b)])
            rnk[find(b)]++;
    }
}
int build(vector<vector<int> > prev,int k){
    // cout<<i<<' '<<j<<' '<<k<<endl;
    p=prev[0],rnk=prev[1],num=prev[2];
    int z=-1;
    ull dd=d[k];
    for(int i=0;dd>0;i++){
        if(dd&1ull){
            if(z==-1)
                z=i;
            else
                merge(z,i);
        }
        dd>>=1;
    }
    int ans=64;
    bitset<64> vis;
    for(int j=0;j<64;j++){
        if(!vis[find(j)])
            vis[find(j)]=1,ans-=num[find(j)]-1;
    }
    prev={p,rnk,num};
    for(int y=k+1;y<n;y++)
        ans+=build(prev,y);
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>d[i];
    vector<vector<int> > ini(3,vector<int>(64));
    for(int j=0;j<64;j++)
            ini[0][j]=j,ini[1][j]=1,ini[2][j]=1;
    // int j=0;
    int ans=64;
    for(int i=0;i<n;i++)
        ans+=build(ini,i);
    cout<<ans<<endl;
    return 0;
}



