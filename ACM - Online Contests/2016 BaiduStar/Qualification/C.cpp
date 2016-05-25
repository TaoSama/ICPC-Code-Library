//
//  Created by TaoSama on 2016-05-14
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Trie {
    static const int M = 20 * 1e5 + 10, S = 26;
    int root, sz;
    int nxt[M][S], have[M];
    int newNode() {
        have[sz] = 0;
        memset(nxt, 0, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0; newNode();
        root = newNode();
    }
    void update(char* s) {
        int u = root;
        for(int i = 0; s[i]; ++i) {
            int& v = nxt[u][s[i] - 'a'];
            if(!v) v = newNode();
            ++have[v];
            u = v;
        }
    }
    void delPrefix(char* s) {
        int u = root;
        for(int i = 0; s[i]; ++i) u = nxt[u][s[i] - 'a'];
        int delta = have[u];
        memset(nxt[u], 0, sizeof nxt[u]);
        if(!delta) return;  //prefix doesn't exist

        u = root;
        for(int i = 0; s[i]; ++i) {
            u = nxt[u][s[i] - 'a'];
            have[u] -= delta;
        }
    }
    bool query(char* s) {
        int u = root;
        for(int i = 0; s[i]; ++i) u = nxt[u][s[i] - 'a'];
        return have[u];
    }
} trie;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int n; scanf("%d", &n);
    trie.init();
    for(int i = 1; i <= n; ++i) {
        char op[10], word[50]; scanf("%s%s", op, word);
        if(*op == 'i') trie.update(word);
        else if(*op == 'd') trie.delPrefix(word);
        else puts(trie.query(word) ? "Yes" : "No");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
