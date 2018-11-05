
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int a[N], b[N];
int fa[N];
int find(int x) {
    return fa[x] = fa[x] == x ? x : find(fa[x]);
}

void pre(int u, vector<int>& preOrder) {
    if(!u) return;
    preOrder.emplace_back(u);
    pre(a[u], preOrder);
    pre(b[u], preOrder);
}

void post(int u, vector<int>& postOrder) {
    if(!u) return;
    post(a[u], postOrder);
    post(b[u], postOrder);
    postOrder.emplace_back(u);
}

int main(){
#ifdef LOCAL
//    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
        vector<int> preOrder, postOrder;
        pre(1, preOrder);
        post(1, postOrder);
        for(int i = 1; i <= n; ++i) fa[i] = i;
        for(int i = 0; i < preOrder.size(); ++i) {
            int x = preOrder[i];
            int y = postOrder[i];
            x = find(x); y = find(y);
            if(x < y) swap(x, y);
            fa[x] = y;
        }
        int atMost = n;
        for(int i = 1; i <= n; ++i) {
            int x = find(i);
            if(x != i) --atMost;
        }
        static int kase = 0;
        if(k > atMost) {
            cout << "Case #" << ++kase << ": " << "Impossible\n";
        }
        else {
            cout << "Case #" << ++kase << ":";
            for(int i = 1; i <= n; ++i) {
                int x = find(i);
                x = min(x, k);
                cout << " " << x;
            }
            cout << '\n';
        }
    }
    return 0;
}
