//minmaxsum.cc
#if 0
g++をインストールしている間に慣れているPythonで提出してみた

input()
a=list(map(int,input().split())
#endif
#include <iostream>
#define int long long
using namespace std;
int N, A[10000];
int min(){
    int m = A[0];
    for(int i=1; i<N; i++){
        m = (m < A[i])? m: A[i];
    }
    return m;
}
int max(){
    int m = A[0];
    for(int i=1; i<N; i++){
        m = (m > A[i])? m: A[i];
    }
    return m;
}
int sum(){
    int s = 0;
    for(int i=0; i<N; i++){
        s += A[i];
    }
    return s;
}
signed main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cout << min() << ' ' << max() << ' ' << sum() << endl;
}
