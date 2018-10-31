// http://poj.org/problem?id=3070
#if 0

#endif
#include <iostream>
#include <valarray>
#define int long long
#define MOD 10000
#define SIZE 10000
//#define _DEBUG
using namespace std;
struct Matrix {
    valarray<int> a;
    Matrix() : a(N*N) {a=0;}
};
Matrix malt(const Matrix& A, const Matrix& B){
    Matrix C;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C.a[i*N + j] = (A.a[slice(i*N,N,1)]*B.a[slice(j,N,N)]).sum()%MOD;
        }
    }
    return C;
}
Matrix pow(const Matrix& A, int p){
    if(p==0){
        Matrix I;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                I.a[i*N + j] = ((i==j)? 1: 0);
            }
        }
        return I;
    }else if(p%2 == 0){
        Matrix B = pow(A, p/2);
        return malt(B, B);
    }else{
        return malt(pow(A, p-1), A);
    }
}
void showMat(const Matrix& A){
    cout << "[ ";
    for(int j=0; i<N; j++){
        for(int i=0; i<N; i++){
            cout << A.a[N*i * j] <<" "
        }
        cout << endl << " ";
    }
    cout << " ]" << endl;
}
int N, M, A, B, C, T, S[SIZE];
void solve(){
    
    
}
signed main(){
    while(cin>>N>>M>>A>>B>>C>>T){
        for(int i=0; i<N; i++){
            cin >> S[i];
        }
        solve();
        cout << S[0];
        for(int i=1; i<N; i++){
            cout << " " << S[i];
        }
        cout << endl;
    }
}