#if 0
>商品の税抜価格として 1 円から s-1 円のすべてを考慮に入れよ．
の文を見落としていたためi=0からカウントしていたためはじめWAになってしまった．
#endif
#include <iostream>
#define int long long
using namespace std;
int X, Y, S;
int tax(int x, int p){
    return p*(100+x)/100;
}
int solve(int x, int y, int s){
    int max = 0;
    for(int i=1; i<s; i++){
        for(int j=1; j<s; j++){
            if(tax(x, i) + tax(x, j) == s){
                int t = tax(y, i) + tax(y,j);
                max = (max > t)? max: t;
            }
        }
    }
    return max;
}

signed main(){
    while(cin >> X >> Y >> S && X > 0){
        cout << solve(X, Y, S) << endl;
    }
}