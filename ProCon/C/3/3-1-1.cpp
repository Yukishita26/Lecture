#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
int N, A[1000000];
signed main(){
    while(cin >> N && N > 0){
        for(int i=0; i<N; i++){
            cin >> A[i];
        }
        sort(A, A+N);
        for(int i=0; i<N; i++){
            cout << A[i];
            if(i != N-1) cout << " ";
        }
        cout << endl;
    }
}