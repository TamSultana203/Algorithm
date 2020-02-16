#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back

int n;
vvi g;
ll f, b, c;
vi sub;

ll maxF, maxB, maxC;

void dfs(int v) {
    sub[v] = 1;
    for (int u : g[v]) {
        dfs(u);
        sub[v] += sub[u];
        maxF += sub[u] - 1;
        maxB += sub[u];
    }
    ll sum = 0;
    for (int u : g[v]) {
        maxC += sum * sub[u];
        sum += sub[u];
    }
}

vvi gOut;

typedef set<int> Set;

Set* merge(Set* a, Set* b) {
    if (a->size() < b->size()) {
        return merge(b, a);
    }
    a->insert(b->begin(), b->end());
    return a;
}

Set* genGraph(int v) {
    Set* sub = new Set();
    for (int u : g[v]) {
        Set* s = genGraph(u);
        ll bNow = min(b, (ll)s->size());
        Set::iterator it = s->begin();
        forn(i, bNow) {
            gOut[*it].pb(v);
            it++;
        }
        b -= bNow;
        ll fNow = min(f, (ll)s->size() - 1);
        it = s->begin();
        forn(i, fNow) {
            if (*it == u) {
                it++;
                i--;
                continue;
            }
            gOut[v].pb(*it);
            it++;
        }
        f -= fNow;
        ll cNow = min(c, (ll)s->size() * (ll)sub->size());
        it = s->begin();
        c -= cNow;
        while (cNow && it != s->end()) {
            Set::iterator it2 = sub->begin();
            while (cNow && it2 != sub->end()) {
                gOut[*it].pb(*it2);
                it2++;
                cNow--;
            }

            it++;
        }

        sub = merge(sub, s);
    }
    sub->insert(v);
    return sub;
}

vi col;
vi tin, tout;

bool isAnc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int curTime;

void dfs2(int v) {
    tin[v] = curTime++;
    for (int u : g[v]) {
        dfs2(u);
    }
    tout[v] = curTime++;
}

void dfsCheck(int v) {
    col[v] = 1;
    for (int u : gOut[v]) {
        if (col[u] == 0) {
            dfsCheck(u);
        } else if (col[u] == 1) {
            b++;
        } else if (isAnc(v, u)) {
            f++;
        } else {
            c++;
        }
    }
    col[v] = 2;
}

void check() {
    sub = vi(n);
    maxF = maxC = maxB = 0;
    dfs(0);
    if (f <= maxF && b <= maxB && c <= maxC) {
        gOut = g;
        ll _f = f, _b = b, _c = c;
        genGraph(0);
        b = f = c = 0;
        tin = tout = vi(n);
        dfs2(0);
        col = vi(n);
        dfsCheck(0);
        if (f != _f || b != _b || c != _c) {
            throw;
        }
        cout << n << endl;
        forn(i, n) {
            printf("%d", (int)gOut[i].size());
            for (int j : gOut[i]) {
                printf(" %d", j + 1);
            }
            printf("\n");
        }
        exit(0);
    }
}

int random(int n) {
    int r = (rand() << 15) ^ rand();
    return abs(r) % n;
}

void genLine() {
    g = vvi(n);
    forn(i, n - 1) {
        g[i].pb(i + 1);
    }
}

void genStar() {
    g = vvi(n);
    forn(i, n - 1) {
        g[0].pb(i + 1);
    }
}

void genTree(int maxD) {
    g = vvi(n);
    vvi byDepth(n);
    int curD = 0;
    byDepth[0].pb(0);
    for (int i = 1; i < n; i++) {
        int d = random(curD + 1);
        if (d + 1 > maxD) d--;
        int j = byDepth[d][random((int)byDepth[d].size())];
        g[j].pb(i);
        byDepth[d + 1].pb(i);
        curD = max(curD, d + 1);
    }
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t >> b >> f >> c;
    n = t + 1;
    genStar();
    check();
    genLine();
    check();
    forn(it, 20) {
        genTree(max(1, int(n / 20.0 * it)));
        check();
    }
    cout << -1 << endl;
    return 0;
}

