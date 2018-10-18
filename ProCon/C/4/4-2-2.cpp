// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=jp
#include <iostream>
#include <string>
#include <utility>
#include <queue>
#define int long long
using namespace std;
queue<pair<string,int>> que;
int n,q;
void round_robin(){
    int t = 0;
    while(!que.empty()){
        auto nt = que.front(); que.pop();
        if(nt.second > q){
            nt.second -= q;
            t += q;
            que.push(nt);
        }else{
            t += nt.second;
            cout << nt.first << " " << t << endl;
        }
    }
}
signed main(){    
    while(cin >> n >> q){
        for(int i=0; i<n; i++){
            pair<string,int> nt;
            cin >> nt.first >> nt.second;
            que.push(nt);
        }
        round_robin();
    }
}