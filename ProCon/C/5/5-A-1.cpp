// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp
#if 0

#endif
#include <iostream>
#define int long long
#define MOD 1000000007
//#define _DEBUG
using namespace std;
int N, M;
int mod_times(int a, int b){
    return (a*b)%MOD;
}
int pow(int n, int p){
    //cout << n << "," << p << endl;
    if(p==1){
        return n;
    }else if(p%2 == 0){
        int n2 = pow(n, p/2);
        return mod_times(n2, n2);
    }else{
        return mod_times(pow(n, p-1), n);
    }
}
signed main(){
    while(cin >> N >> M){
        cout << pow(N, M) << endl;
    }
}