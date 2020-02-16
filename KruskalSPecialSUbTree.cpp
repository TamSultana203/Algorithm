

#include<bits/stdc++.h>
#define     pb                      push_back
#define     mkp                     make_pair
#define     inf                     1000000007
#define     rep(i,n)                for(int i=0;i<n;i++)
#define     fr                      first
#define     sc                      second
#define     clr(a)                  memset(a,0LL,sizeof a);
#define     WHITE                   0
#define     BLACK                   1
#define     pi                      3.141592653589793

using       namespace               std;

typedef     unsigned long long      ull;
typedef     long long               ll;
typedef     vector<ll>              vi;
typedef     pair<ll,ll>             ii;
typedef     vector<ii>              vii;
typedef     set<ll>::iterator       sit;
typedef     map<ll,ll>::iterator    mit;
typedef     vector<int>::iterator   vit;

//_____________________________

vector<pair<ll, ii> > v; // Edge List
ll parent[3001];
int mst_count;

ll findSet(ll x){
    return (parent[x] == x) ? x : (parent[x] = findSet(parent[x]));
}

bool isSameSet(ll a, ll b){
    return ( findSet(a) == findSet(b));
}

void _union_(ll a, ll b){
    parent[findSet(a)] = findSet(b);
}


void solve(){
    ll n, m;
    cin >> n >> m;


    while(m -- ){
        ll x, y, r;
        cin >> x >> y >> r;
        x --, y --;
        v.pb(mkp(r , ii(x, y)));
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < n ; i ++){
        parent[i] = i;
    }
    mst_count = 0;
    int index = 0;
    while(index < v.size()){
        pair<int, ii > front = v[index++];
        if(!isSameSet(front.sc.sc, front.sc.fr)){
            mst_count += (front.fr);
            _union_(front.sc.fr, front.sc.sc);
        }
    }

    cout << mst_count << endl;



}
int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    solve();
}

