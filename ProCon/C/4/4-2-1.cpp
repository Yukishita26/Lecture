// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp
#include <iostream>
#include <string>
#include <stack>
#define int long long
using namespace std;
stack<int> stk;
signed main(){
    string word;
    while(cin >> word){
        if(word == "*"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(a*b);
        }else if(word == "+"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(a+b);
        }else if(word == "-"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b-a);
        }else{
            stk.push(stoi(word));
        }
    }
    cout << stk.top() << endl;
}