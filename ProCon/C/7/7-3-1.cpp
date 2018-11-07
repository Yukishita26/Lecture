#if 0
オブジェクトのほうが扱いやすいのでクラスを作った．
#endif
#include <iostream>
#include <string>
using namespace std;
//#define int long long
//#define _DEBUG
class UnionFindTree{
    private:
    int P[10010];
    public:
    UnionFindTree(int N){
        for(int i=0; i<=N; i++) P[i] = i;
    }
    int root(int a){
        if (P[a] == a) return a;
        return (P[a] = root(P[a]));
    }
    bool is_same_set(int a, int b){
        return root(a) == root (b);
    }
    void unite(int a, int b){
        P[root(a)] = root(b);
    }
};
signed main(){
    int n, q;
    while(cin >> n >> q){
        auto uft = UnionFindTree(n);
        for(int i=0; i<q; i++){
            int c, x, y;
            cin >> c >> x >> y;
            if(c==0){
                uft.unite(x,y);
            }else{
                cout << uft.is_same_set(x,y) << endl;
            }
        }
    }
}