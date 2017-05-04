//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> a, b;

bool dfs(vector<int> a, int p) {
    bool allWin = true;
    for(int i = 0; i < a.size(); ++i) {
        if(p == 1) {
            for(int j = 1; j <= a[i]; ++j) {
                vector<int> nxt = a;
                nxt[i] -= j;
                allWin &= dfs(nxt, p ^ 1);
                if(!allWin) return true;
            }
        } else {
            if(b[i] == 0) {
                for(int j = 1; j <= a[i]; ++j) {
                    vector<int> nxt = a;
                    nxt[i] -= j;
                    allWin &= dfs(nxt, p ^ 1);
                    if(!allWin) return true;
                }
            } else {
                for(int j = b[i]; j <= a[i]; j += 2) {
                    vector<int> nxt = a;
                    nxt[i] -= j;
                    allWin &= dfs(nxt, p ^ 1);
                    if(!allWin) return true;
                }
            }
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        a.resize(n); b.resize(n);
        for(int& x : a) scanf("%d", &x);
        for(int& x : b) scanf("%d", &x);

        puts(dfs(a, 0) ? "Alice" : "Bob");
    }

    return 0;
}
