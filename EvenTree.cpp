#include <bits/stdc++.h>

using namespace std;

vector<int> g[1000002];

int cnt;

int dfs(int n, int p)
{
    int ans = 1;
    for(int i = 0; i < g[n].size(); i++)
    {
        int v = g[n][i];
        if(v != p)
        {
            ans += dfs(v, n);
        }
    }
    if(ans % 2 == 0) cnt++;
    return ans;
}
///not mine
int main()
{
    int n, i, m, j;
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    
    cout << cnt-1 << endl;
}

