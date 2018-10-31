// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2186
#if 0
コーナーでないケースでmHとmVを逆に書いていてハマってしまっていた．そもそもelseでよかった．
pair<pair<int,int>,pair<int,int>>はアクセスも長くなるのでstructを使って大変楽になった．
#endif
#include <iostream>
//#define int long long
//#define _DEBUG
#define m_v 1000
using namespace std;
int gx, gy, p, T[m_v][m_v];
//pair<pair<int,int>,pair<int,int>> m[m_v];
struct _line{
    int x1;
    int y1;
    int x2;
    int y2;
};
struct _line m[m_v];
bool mH[m_v][m_v], mV[m_v][m_v];
int solve(){
    for(int y=0; y<=gy; y++){
        for(int x=0; x<=gx; x++){
            if(x==0 && y==0){
                T[0][0] = 1;
            }else if((x==0 || mH[x-1][y]) && (y==0 || mV[x][y-1])){
                T[x][y] = 0;
            }else if(x==0 || mH[x-1][y]){
                T[x][y] = T[x][y-1];
            }else if(y==0 || mV[x][y-1]){
                T[x][y] = T[x-1][y];
            }else{// if(x>0 && y>0 && !mV[x-1][y] && !mH[x][y-1]){ //ここの条件分岐でバグった
                T[x][y] = T[x-1][y] + T[x][y-1];
            }
        }
    }
#ifdef _DEBUG
    for(int y=0; y<=gy; y++){
        for(int x=0; x<=gx; x++){
            cout << T[x][y] << " ";
        }
        cout << endl;
    }
    for(int y=0; y<=gy; y++){
        for(int x=0; x<=gx; x++){
            cout << ((mV[x][y])?"x":"0") << " ";
        }
        cout << endl;
    }
    for(int y=0; y<=gy; y++){
        for(int x=0; x<=gx; x++){
            cout << ((mH[x][y])?"x":"0" )<< " ";
        }
        cout << endl;
    }
    
    for(int y=0; y<=gy; y++){
        for(int x=0; x<=gx; x++){
            cout << T[x][y] << " " << ((mH[x][y])?"x":" " ) << " ";
        }cout << endl;
        for(int x=0; x<=gx; x++){
            cout << ((mV[x][y])?"x":" " ) << "   ";
        }
        cout << endl;
    }

#endif
    return T[gx][gy];
}
void get(){
    cin >> gx >> gy >>p;
    for(int i=0; i<p; i++){
        cin >> m[i].x1 >> m[i].y1 >> m[i].x2 >> m[i].y2;
        if(m[i].x1 == m[i].x2){
            mV[m[i].x1][min(m[i].y1,m[i].y2)] = true;
        }else{
            mH[min(m[i].x1,m[i].x2)][m[i].y1] = true;
        }
    }
}
void clear(){
    for(int i=0; i<p; i++){
        mV[m[i].x1][min(m[i].y1,m[i].y2)] = false;
        mH[min(m[i].x1,m[i].x2)][m[i].y1] = false;
    }
}

signed main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        get();
        int s = solve();
        if(s==0){
            cout << "Miserable Hokusai!" << endl;
        }else{
            cout << s << endl;
        }
        clear();
    }
}