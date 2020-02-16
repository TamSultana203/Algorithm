#include <bits/stdc++.h>

using namespace std;

#define mx 1005
#define nx 10010
#define MOD 1e9 + 7

int n, q, x, ar[nx], frag[nx][mx];

void func(int q){
    for (int i = 1; i <= q; ++i) {
            cin>>x;
            if (i > 1) cout<<' ';
                cout<<frag[n][x];
        }
        puts("");
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i = 1; i <= n; ++i) {
           cin>>ar[i];
        }
        frag[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <mx; ++j) {
                frag[i][j] = frag[i - 1][j];
                    if (j >= ar[i]) {
                        frag[i][j] += frag[i - 1][j - ar[i]];
                    if (frag[i][j] >= MOD) frag[i][j] -= MOD;
                }
            }
        }
        
        
        cin>>q;
        func(q);
        
    }
    return 0;
}

