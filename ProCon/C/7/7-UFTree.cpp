#include <iostream>
using namespace std;

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

int main(){
    auto uft = UnionFindTree(10);
    cout<< uft.is_same_set(1, 3) <<endl;
    uft.unite(1,2);
    cout<< uft.is_same_set(1, 3) <<endl;
    uft.unite(2,3);
    cout<< uft.is_same_set(1, 3) <<endl;   
}