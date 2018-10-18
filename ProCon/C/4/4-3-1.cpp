// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C&lang=jp
#include <iostream>
#include <string>
#include <unordered_set>
#define int long long
using namespace std;
int n;
unordered_set<int> h_s;
signed main(){
    string opr, word;
    while(cin >> n){
        for(int i=0; i<n; i++){
            cin >> opr >> word;
            if(opr == "insert"){
                h_s.insert(word);
            }else if(opr == "find"){
                cout << ((h_s.count(word)>0)? "yes": "no" <<endl;
            }
        }
    }
}