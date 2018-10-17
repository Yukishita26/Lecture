//http://poj.org/problem?id=1328
#if 0
考え方は
 xの小さい島から見ていき，そこにレーダーが届く設置場所の範囲と共通部分を持つものを貪欲法で集めていく．
 このとき範囲の最右点だけ見ていれば，共通部分の最右点はそのまま変わらないか，xと最右点の間になるため追跡できる．
 範囲と共通点を持たないものがあれば新たにレーダーを設置すれば良い．
と考えられます．
計算量は(x,y)をxの順に並び替えるのにO(NlogN)，貪欲法の処理ではO(N)のため全体でO(NlogN)となります．

最初は貪欲法の途中でyがdの値を超えるものがあれば処理を打ち切って-1を返すようにしていたのですが，
これではWrong Answerとなり，一番最初にケース全体をチェックするようにしたらAcceptedとなりました．
前者が駄目で後者なら良いようなケースが考えつかないのですがどのようなものなのでしょうか？
#endif
#include <algorithm>
#include <iostream>
#include <utility>
#include <math.h>
#define int long long
using namespace std;
int n, d;
pair<int, int> xy[1000];
double ld(int d, int y){
    return sqrt((double)d*d-y*y);
}
int solve(){
    for(int i=0; i<n; i++){
        if(xy[i].second > d) return -1;
    }
    sort(xy,xy+n);
    int r=1, x=xy[0].first, y=xy[0].second;
    double rightEdge = x + ld(d, y);
    for(int i=1; i<n; i++){
        int xi = xy[i].first, yi = xy[i].second;
        //if(yi > d)return -1;

        if(xi-ld(d,yi) > rightEdge){
            r++;
            x = xi;
            y = yi;
            rightEdge = x + ld(d,y);
        }else{
            rightEdge = (rightEdge < xi+ld(d,yi))? rightEdge: xi+ld(d,yi);
        }
    }

    return r;
}
bool get(){
    cin >> n;
    if(n==0)return false;
    cin >> d;
    for(int i=0; i<n; i++){
        cin >> xy[i].first >> xy[i].second;
    }
    return true;
}
signed main(){
    int cs = 1;
    while(get()){
        cout << "Case " << cs << ": " << solve() << endl;
        cs++;
    }
}