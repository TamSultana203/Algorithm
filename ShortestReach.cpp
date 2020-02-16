#include<bits/stdc++.h>
using namespace std;
#define mx 1000
#define pb push_back

vector<int>vec[mx];
int vis[mx];
int col[mx];
int dis[mx];
int par [mx];
int nodes, edges;
int flag=0;

void bfs(int src)
{

    dis[src]=0;
    vis[src]=1;
    queue<int>q;

    q.push(src);

    while(!q.empty())
    {
        int a = q.front();
       // cout<<a<<endl;
        q.pop();

        for(int i=0; i<vec[a].size(); i++)
        {
            int v = vec[a][i];
            if(!vis[v])
                {
                    vis[v]=1;
                    dis[v] = 1+dis[a];
                    //cout<<dis[v]<<endl;
                    q.push(v);
                }
            }
        }
    }




int main()
{
    int q;
    cin>>q;
    while(q--){
        cin>>nodes>>edges;
        for(int i=0; i<edges; i++)
        {
            int u, v;
            cin>>u>>v;
            vec[u].pb(v);
            vec[v].pb(u);
        }
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        int str;
        cin>>str;
        bfs(str);

        for(int i=1; i<=nodes; i++){
            if(i!=str){
                if(dis[i]>0){
                cout<<6*dis[i];
            }
            else {
                cout<<-1;
            }
            if(i<nodes) cout<<' ';
            }


        }
        cout<<endl;
        for(int i=0; i<=nodes; i++) vec[i].clear();

    }

}


