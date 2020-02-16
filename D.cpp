#include <bits/stdc++.h>

using namespace std;

#define mx 100010

int n, ar[mx], l, r;
long long ans = 0;

long long int work (){
    for (int i = 1; i <=n; ++i) {
            int low = l - ar[i];
            int high = r - ar[i];
            int tot = upper_bound(ar + 1, ar + n + 1, high) - lower_bound(ar + 1, ar + n + 1, low);
            
            
            ans += tot; 
            if (low <= ar[i] && ar[i] <= high) --ans;
        }
    return ans;
}

int main() {
    int t;
    cin>>t;
    for(int q=1; q<=t; q++){
        cin>>n>>l>>r;
        for (int i = 1; i<=n; ++i)
            cin>>ar[i]; 
            
        sort(ar + 1, ar + n + 1);
        ans = 0;
        long long int anss= work();
        
        
        anss >>= 1;
        printf("Case %d: %lld\n", q, anss);
        }
    return 0;
}
