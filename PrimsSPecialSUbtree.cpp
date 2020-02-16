#include<bits/stdc++.h>
#define pb push_back
#define INF 9999999
#define mp make_pair

using namespace std;

vector<pair<int,int> >adj[5000];

int prims(int s,int n)

{

    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    vis[s]=true;
    vector<int>d;
    d.clear();
    d.resize(n+1);
    for(int i=0; i<=n; i++)
        d[i]=INF;
    d[s]=0;
    set<pair<int,int> >q;
    q.clear();
    q.insert(mp(0,s));
    int wt=0;
    int prev=0;
    while(!q.empty())
    {
        pair<int,int> top=*q.begin();
        q.erase(q.begin());
        int u=top.second;
        vis[u]=true;
        wt+=prev;
        //cout<<"u-"<<u<<endl;
        vector<pair<int,int> >::iterator it;
        for(it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            int cost=it->first;
            int v=it->second;
            if(!vis[v])
            {
                if(d[v]>cost)
                {
                    if(d[v]!=INF)
                    {
                        q.erase(q.find(mp(d[v],v)));
                    }
                    d[v]=cost;
                    q.insert(mp(d[v],v));
                }
            }

        }
        prev=top.first;
    }
    return wt+prev;
}

int main()

{

    int T,t,r,x,y,n,m,i,s,d;

    cin>>n>>m;
    for(i=0; i<n+2; i++)
        adj[i].clear();
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>r;
        adj[x].pb(mp(r,y));
        adj[y].pb(mp(r,x));
    }
    cin>>s;
    int ans=prims(s,n);
    cout<<ans<<endl;
    return 0;
}

