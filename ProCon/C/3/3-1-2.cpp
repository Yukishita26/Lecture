#include <algorithm>
#include <string>
#include <iostream>
#define int long long
using namespace std;
int N;
string A[1000000];
signed main(){
    //while(cin >> N && N > 0){
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> A[i];
        }
        sort(A, A+N);
        cout << A[0] << endl;
    //}
}