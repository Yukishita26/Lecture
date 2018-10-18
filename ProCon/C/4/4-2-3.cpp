// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
#include <iostream>
#include <string>
#include <queue>
#define int long long
using namespace std;
priority_queue<int> pque;
signed main(){
    string command;
    int n;
    while(cin >> command){
        if(command == "insert"){
            cin >> n;
            pque.push(n);
        }else if(command == "extract"){
            cout << pque.top() << endl; pque.pop();
        }else{
            break;
        }
    }
}