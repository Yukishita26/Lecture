#if 0
時間は10分ほど．
#endif
#include <iostream>
#define int long long
using namespace std;
int E;
int solve(int e){
    int min = e;
    for(int z=0; z*z*z<=e; z++){
        for(int y=0; y*y<=e-z*z*z; y++){
            int x = e - z*z*z - y*y;
            min = (min < x+y+z)? min: x+y+z;
        }
    }
    return min;
}
signed main(){
    while(cin >> E && E > 0){
        cout << solve(E) << endl;
    }
}