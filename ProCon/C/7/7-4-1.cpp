#if 0

#endif
#include <iostream>
#include <algorithm>
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
struct weight_edge{// (weight, (vert_a,vert_b))
    int w;
    int a;
    int b;
};
int n, k;
weight_edge we[10007];
bool com_we(weight_edge a, weight_edge b){
    return ((a.w == b.w)? a.a < b.a: a.w < b.w);
}
int solve(){
    if(n==0)return 0;
    sort(we, we+k, com_we);
    //for(int i=0; i<k; i++)printf("%d,%d,%d\n",we[i].w,we[i].a,we[i].b);
    auto uft = UnionFindTree(n);
    int i=0, r=0, l=0;
    while(l<n-1){
        if(!uft.is_same_set(we[i].a, we[i].b)){
            uft.unite(we[i].a, we[i].b);
            r += we[i].w;
            l++;
            //printf("%d;\tw:%d,\t(%d,%d)\n",l,we[i].w,we[i].a,we[i].b);
        }
        i++;
    }
    return r;
}
void get(){
    k = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int t;
            cin >> t;
            if(i<j && t>=0){
                we[k].w = t;
                we[k].a = i; we[k].b = j;
                k++;
            }
            //cout << t<<":"<<i<<","<<j<<"\t";
        }
        //cout << endl;
    }
    //cout << "k"<<k<<endl;
}
signed main(){    
    while(cin >> n){
        get();
        cout << solve() <<  endl;
    }
}