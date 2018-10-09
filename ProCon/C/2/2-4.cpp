#if 0
所要時間：2時間ほど
イテレータやhashmapの挙動がよくわからず時間がかかった

解法は縦，横のあり得る間隔をすべて列挙し，等しいものの数を数えるというものである
縦幅=Xのものがn個，横幅=Xのものがm個ならば X*Xの正方形はnm個であるから，
片方で出てきた間隔X全てに対して足し合わせれば正方形の個数がわかる

計算量はありうる間隔の列挙でN^2/2+M^2/2，
hashmapの生成でN^2/2+M^2/2，
正方形の個数のカウントでN^2/2
より全体でO(max(N,M)^2)である．
N,M<=1500より2x10^6程度なので実行可能である．
#endif
#include <iostream>
#include <vector>
#include <unordered_map> 
#define int long long
using namespace std;
int N, M, sumH[1501], sumW[1501];
int solve(){
    vector<int> dH;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            dH.push_back(sumH[j+1]-sumH[i]);
        }
    }
    vector<int> dW;
    for(int i=0; i<M; i++){
        for(int j=i; j<M; j++){
            dW.push_back(sumW[j+1]-sumW[i]);
        }
    }
    unordered_map<int,int> mH;
    unordered_map<int,int> mW;
    for(auto itr=dH.begin(); itr!=dH.end(); ++itr){
        mH[*itr]+=1;
        //mW[*itr]=0;
    }
    for(auto itr=dW.begin(); itr!=dW.end(); ++itr){
        auto t = mH.find(*itr);
        if(t != mH.end()){
            mW[*itr]+=1;
        }
    }
    int count = 0;
    for(auto itr=mH.begin(); itr!=mH.end(); ++itr){
        count += itr->second * mW[itr->first];
    }
    return count;
}
signed main(){
    while(cin >> N >> M && N > 0){
        int temp;
        sumH[0] = 0;
        for(int i=0; i<N; i++){
            cin >> temp;
            sumH[i+1] = sumH[i] + temp;
        }
        sumW[0] = 0;
        for(int i=0; i<M; i++){
            cin >> temp;
            sumW[i+1] = sumW[i] + temp;
        }
        cout << solve() << endl;
    }
}