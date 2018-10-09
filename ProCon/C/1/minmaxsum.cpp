//minmaxsum.cc
#if 0
所要時間は10分ほど
オーバーフローの対策にintをすべてlonglongにしている

g++をインストールしている間に慣れているPythonで提出してみた

input()
a=list(map(int,input().split()))
print(max(a),min(a),sum(a))
//実行00:02 s,6540 KB

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
//mainの戻り値はintである必要があるがintと書くとlong longになってしまう
signed main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cout << min() << ' ' << max() << ' ' << sum() << endl;
}
