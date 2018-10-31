// http://poj.org/problem?id=3070
#if 0

#endif
#include <iostream>
#define int long long
#define MOD 10000
//#define _DEBUG
using namespace std;
struct Mat2x2{
    int _11, _12, _21, _22;
};
Mat2x2 malt(Mat2x2 A, Mat2x2 B){
    Mat2x2 C = {0};
    C._11 = ((A._11 * B._11)%MOD + (A._12 * B._21)%MOD)%MOD;
    C._12 = ((A._11 * B._12)%MOD + (A._12 * B._22)%MOD)%MOD;
    C._21 = ((A._21 * B._11)%MOD + (A._22 * B._21)%MOD)%MOD;
    C._22 = ((A._21 * B._12)%MOD + (A._22 * B._22)%MOD)%MOD;
    return C;
}
Mat2x2 pow(Mat2x2 A, int p){
    if(p==0){
        Mat2x2 I = {1, 0, 0, 1};
        return I;
    }else if(p%2 == 0){
        Mat2x2 B = pow(A, p/2);
        return malt(B, B);
    }else{
        return malt(pow(A, p-1), A);
    }
}
void showMat(Mat2x2 A){
    cout << "[ " << A._11 << " ,  " << A._12 << endl
        << "  " << A._21 << " ,  " << A._22 << " ]" << endl;
}
int N;
int solve(){
    Mat2x2 A = {1, 1, 1, 0};
    A = pow(A, N);
    return A._21;
}
signed main(){
    while(cin >> N && N>=0){
        cout << solve() << endl;
    }
}