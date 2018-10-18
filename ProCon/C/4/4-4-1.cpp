// http://poj.org/problem?id=3061
#if 0
所要時間2時間ほど
scanfを使ってもTLEだったがlong longをintに戻したらAcceptされた．制限が厳しくて大変だった．
解法は講義資料のヒント通り．"しゃくとり"の先頭と末尾を入力の配列のindexで管理した．
#endif
//#define _DEBUG
#ifdef _DEBUG
#include <iostream>
#else
#include <stdio.h>
#endif
#include <queue>
//#define int long long
using namespace std;
int N, S, a[100000], sum_que;
queue<int> que;
int solve(){
    while(que.size()>0){
        que.pop();
    }
    int head = 1, tail = 0, // sum_que=sum(a[tail::head])
        shortest_len = N+1;
    que.push(a[0]);
    sum_que = a[0];
    while(head<=N && tail<=head){
        if(sum_que < S){
            head++;
            que.push(a[head-1]);
            sum_que += a[head-1];
        }else{
            tail++;
            sum_que -= que.front(); que.pop();
        }
        if(sum_que >= S)shortest_len = min(shortest_len, head-tail);

#ifdef _DEBUG
        for(int i=0; i<N; i++){
            if(i==tail && i==head-1)cout << "<<" << a[i] << ">> ";
            else if(i==tail || i==head-1)cout << "<" << a[i] << "> ";
            else cout << a[i] << " ";
        }cout << ": " << sum_que << ":" << shortest_len <<endl;
        int q = que.size();
        cout << q << ":";
        for(int i=0; i<q; i++){
            int t = que.front(); que.pop();
            cout << t << " ";
            que.push(t);
        }cout << endl;
#endif
    }
    if(shortest_len == N+1)shortest_len = 0;
    return shortest_len;
}
signed main(){
    int n;
    scanf("%d",&n);
    for(int c=0; c<n; c++){
        scanf("%d%d",&N,&S);
        for(int i=0; i<N; i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",solve());
    }
}