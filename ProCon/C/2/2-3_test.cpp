#if 0
時間は10分ほど．
#endif
#include <iostream>
#define int long long
using namespace std;
int E;
int solve_xyz(int e){
    int min = e;
    for(int x=0; x<=e; x++){
        for(int y=0; y*y<=e-x; y++){
            int z = (int)round(pow(e-x-y*y,1.0/3));
            if(x+y*y+z*z*z!=e) continue;
            min = (min < x+y+z)? min: x+y+z;
        }
    }
    return min;
}
int solve_xzy(int e){
    int min = e;
    for(int x=0; x<=e; x++){
        for(int z=0; z*z*z<=e-x; z++){
            int y = (int)round(sqrt(e - x - z*z*z));
            if(x+y*y+z*z*z!=e) continue;
            min = (min < x+y+z)? min: x+y+z;
        }
    }
    return min;
}
int solve_yxz(int e){
    int min = e;
    for(int y=0; y*y<=e; y++){
        for(int x=0; x<=e-y*y; x++){
            int z = (int)round(pow(e - y*y - x,1.0/3));
            if(x+y*y+z*z*z!=e) continue;
            min = (min < x+y+z)? min: x+y+z;
        }
    }
    return min;
}
int solve_yzx(int e){
    int min = e;
    for(int y=0; y*y<=e; y++){
        for(int z=0; z*z*z<=e-y*y; y++){
            int x = e - z*z*z - y*y;
            min = (min < x+y+z)? min: x+y+z;
        }
    }
    return min;
}
int solve_zxy(int e){
    int min = e;
    for(int z=0; z*z*z<=e; z++){
        for(int y=0; y*y<=e-z*z*z; y++){
            int x = e - z*z*z - y*y;
            min = (min < x+y+z)? min: x+y+z;
        }
    }
    return min;
}
int solve_zyx(int e){
    int min = e;
    for(int z=0; z*z*z<=e; z++){
        for(int y=0; y*y<=e-z*z*z; y++){
            int x = e - z*z*z - y*y;
            //必ず整数である．
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