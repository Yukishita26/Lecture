// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327
#if 0

#endif
#include <iostream>
#include <valarray>
#define int long long
#define SIZE 10000
//#define _DEBUG
using namespace std;
int N, M, A, B, C, T, S[SIZE], U[SIZE];
struct Matrix {
    valarray<int> a;
    Matrix() : a(N*N) {a=0;}
};
Matrix mult(const Matrix& P, const Matrix& Q){
    Matrix R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            R.a[i*N + j] = (P.a[slice(i*N,N,1)]*Q.a[slice(j,N,N)]).sum() % M;
        }
    }
    return R;
}
Matrix pow(const Matrix& P, int p){
    if(p==0){
        Matrix I;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                I.a[i*N + j] = ((i==j)? 1: 0);
            }
        }
        return I;
    }else if(p%2 == 0){
        Matrix Q = pow(P, p/2);
        return mult(Q, Q);
    }else{
        return mult(pow(P, p-1), P);
    }
}
void mat4vec(const Matrix& P){ //U <= M x S
    for(int i=0; i<N; i++){
        int t=0;
        for(int j=0; j<N; j++){
            t += P.a[i*N+j]*S[j] % M;
        }
        U[i] = t % M;
    }
}
void showMat(Matrix P){
    cout << "[";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << P.a[N*i + j] << "\t";
        }
        cout << endl << " ";
    }
    cout << "]" << endl;
}
void solve(){
    Matrix P;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j-i == -1){
                P.a[i*N+j] = A;
            }else if(j-i == 0){
                P.a[i*N+j] = B;
            }else if(j-i == 1){
                P.a[i*N+j] = C;
            }else{
                //P.a[i*N+j] = 0;
            }
        }
    }
    P = pow(P, T);
    //showMat(P);
    mat4vec(P);
    for(int i=0; i<N; i++){
        S[i] = U[i];
        //cout << S[i] << endl;
    }
}
signed main(){
    while(cin>> N>>M>>A>>B>>C>>T && N>0){
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