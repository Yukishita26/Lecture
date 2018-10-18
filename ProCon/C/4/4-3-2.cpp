// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0029&lang=jp
#include <iostream>
#include <string>
#include <unordered_map>
#define int long long
using namespace std;
int n;
unordered_map<int> h_m;
signed main(){
    string word;
    int m_len = 0, m_count = 0;
    string w_len = "", w_count = "";
    while(cin >> word){
        h_m[word] += 1;
        if(m_len < word.size()){
            m_len = word.size();
            w_len = word;
        }
        if(m_count < h_m[word]){
            m_count = h_m[word];
            w_count = word;
        }
    }
    cout << w_count << " " << w_len << endl;
}