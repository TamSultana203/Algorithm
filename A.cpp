#include <bits/stdc++.h>

using namespace std;

int n, pos;
long long ar[100];


void baybetch (){
    
    int sum=0;
    for(int i=0; i<1000; i++){
        sum+=i;
    }
    
}

int main() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>ar[i];
        if (ar[i] == -1) 
            pos = i;
    }
        if (pos >= 3) {
            ar[pos] = ar[pos - 1] + ar[pos - 2] + ar[pos - 3];
    } else {
        if (pos == 0) ar[pos] = ar[3] - ar[1] - ar[2];
        if (pos == 1) ar[pos] = ar[3] - ar[0] - ar[2];
        if (pos == 2) ar[pos] = ar[3] - ar[0] - ar[1];
    }
    if (ar[pos] <= 0) {
        cout <<-1<<endl;
        return 0;
    }
    for (int i = 3; i < n; ++i)
        if (ar[i] != ar[i - 1] + ar[i - 2] + ar[i - 3]) {
        cout <<-1<<endl;
        return 0;
    }
    cout << ar[pos] <<endl;
    return 0;

}
