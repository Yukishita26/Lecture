// http://poj.org/problem?id=2397
#if 0
解法は解説どおり．経路の追跡は前者（TとHsの関係からゴールから遡る）
経路のトレースでindexをところどころで間違えてなかなか合わせられなかった．
#endif
#include <iostream>
#include <string>
//#define int long long
#define MAX_HEIGHT 1009
#define INFTY 10000007
//#define _DEBUG
using namespace std;
int M, Hs[1009], T[1009][MAX_HEIGHT];
string trace(){
    string str = string(M, '0');
    int now_height = 0;
    for(int i=M-1; i>=0; i--){
        if(now_height >= Hs[i]){
            if(T[i][now_height+Hs[i]] < T[i][now_height-Hs[i]]){
                str[i] = 'D';
                now_height += Hs[i];
            }else{
                str[i] = 'U';
                now_height -= Hs[i];
            }
        }else{
            str[i] = 'D';
            now_height += Hs[i];
        }
#ifdef _DEBUG
        cout << now_height <<endl;
#endif
    }
    return str;
}
int cost_up(int i,int h){
    if(h<Hs[i]){
        return INFTY;
    }else{
        return max( T[i][h-Hs[i]], h );
    }
}
string solve(){
    for(int i=0; i<=M; i++){
        for(int h=0; h<MAX_HEIGHT; h++){
            T[i][h] = INFTY;
        }
    }
    T[0][0] = 0;
    
    for(int i=0; i<M; i++){
        for(int h=0; h<MAX_HEIGHT; h++){
            T[i+1][h] = min(cost_up(i,h), T[i][h+Hs[i]]);
        }
    }
#ifdef _DEBUG
    cout << "h\\i";
    for(int h=0; h<21; h++){
        cout << "\t" << h; 
    }cout << endl;
    for(int i=0; i<=M; i++){
        cout << i;
        if(i!=0) cout << ", " << Hs[i-1];
        for(int h=0; h<21; h++){
            cout << "\t" << T[i][h]; 
        }
        cout << endl;
    }
#endif
    if(T[M][0]==INFTY) return "IMPOSSIBLE";
    return trace();
}
signed main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> M;
        for(int j=0; j<M; j++){
            cin >> Hs[j];
        }
        cout << solve() << endl;
    }
}