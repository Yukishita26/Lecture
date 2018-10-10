#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
int t, n, k, x[100000], d[99999];
int solve(){
    if(k>n)k=n;
    for(int i=0; i<n-1; i++){
        d[i] = x[i+1] - x[i];
    }
    sort(d,d+n-1);
    int w = 0;
    for(int i=0; i<k-1; i++){
        w += d[n-2-i];
    }
    return x[n-1] - x[0] - w;
}
void get(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
}
signed main(){
    cin >> t;
    for(int i=0; i<t; i++){
        get();
        cout << solve() << endl;
    }
}