#include <algorithm>
#include <iostream>
#include <utility>
#define int long long
using namespace std;
int n, d;
pair<int, int> xy[1000];
//bool com(pair<int,int> a, pair<int,int> b){ //Pの値で降順ソート
//    return a.second > b.second;
//}
int solve(){
    
    return r;
}
bool get(){
    cin >> n;
    if(n==0)return false;
    cin >> d;
    for(int i=0; i<n; i++){
        cin >> xy[i].first >> xy[i].second;
    }
}
signed main(){
    while(get()){
        cout << solve() << endl;
    }
}