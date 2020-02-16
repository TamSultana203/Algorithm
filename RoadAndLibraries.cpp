#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
bool vis[mx];
vector<ll> vec[mx];
ll ct =0;
void dfs(ll src){
    vis[src]=true;
    //cout << u << "-> ";
    ct++;
    for(ll i=0;i<vec[src].size();i++){
        ll v= vec[src][i];
       // cout << v << "#";
        if(!vis[v]){
            //cout << v << "#";
            dfs(v);
        }
    }
}

int main ()
{
    ll test,n,m,u,v;
    cin >> test;
    while(test--){
        ll clib, crod;
        cin>>n>>m>>clib>>crod;
        while(m--){
            ll a, b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        ll cost =0;
    //    memset(vis, 0, sizeof vis);
        for(ll i=1;i<=n; i++){
            if(!vis[i]){
                 ct=0;
                 dfs(i);
                 cost=cost+clib;
                if(clib<crod){
                    cost+= clib*(ct-1);
                }
                else {

                    cost+= crod*(ct-1);
                }

            }

        }
        cout<<cost<<endl;
        for(ll i=0; i<=n; i++){
            vec[i].clear();
            vis[i] = false;

        }
    }


}

