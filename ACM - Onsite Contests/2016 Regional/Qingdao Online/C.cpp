//
//  Created by TaoSama on 2016-09-17
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


//struct Link {
//    struct Edge {
//        char c; int v, nxt;
//    } edges[N];
//    int head[N], cnt;
//    void init() {
//        cnt = 1; memset(head, -1, sizeof head);
//    }
//    inline void addEdge(int u, int v, int c) {
////      printf("%d %d %c\n", u, v, c);
//        edges[cnt] = {c, v, head[u]};
//        head[u] = cnt++;
//    }
//    inline int getEdge(int u, char c) {
//        for(int i = head[u]; ~i; i = edges[i].nxt)
//            if(edges[i].c == c) return i;
//        return 0;
//    }
//    inline int getHead(int u) {
//        return head[u];
//    }
//    inline int getNxt(int i) {
//        return edges[i].nxt;
//    }
//    inline int getV(int i) {
//        return edges[i].v;
//    }
//    inline int getC(int i) {
//        return edges[i].c;
//    }
//};
//
//struct ACAutomata {
//    int sz, root;
//    int len[N], fail[N];
//    int sum[N], q[N];
//    Link nxt;
//
//    inline int idx(char c) {return c - 'a';}
//    inline int newNode() {
//        len[sz] = 0;
//        return sz++;
//    }
//    void init() {
//        sz = 0;
//        nxt.init();
//        root = newNode();
//    }
//    void insert(char* s) {
//        int u = root, i;
//        for(i = 0; s[i]; ++i) {
//            int c = s[i];
//            if(!nxt.getEdge(u, c)) nxt.addEdge(u, newNode(), c);
////            printf("%d -> ", u);
//            u = nxt.getEdge(u, c);
////            printf("%d\n", u);
//        }
//        len[u] = i;
//    }
//    void build() {
//        int st, ed; st = ed = 0;
//        fail[root] = root;
//        for(int i = nxt.getHead(root); ~i; i = nxt.getNxt(i)) {
//            int u = nxt.getV(i);
//            fail[u] = 0;
////            prln(u);
//            q[ed++] = u;
//        }
//        for(; st < ed; ++st) {
//            int u = q[st];
////            prln(u);
//            for(int i = nxt.getHead(u); ~i; i = nxt.getNxt(i)) {
//                int v = nxt.getV(i), c = nxt.getC(i);
//                q[ed++] = v;
//                int t = fail[u];
//                while(t && !nxt.getEdge(t, c)) t = fail[t];
//                int f = nxt.getEdge(t, c);
//                if(!f || f == v) fail[v] = 0;
//                fail[v] = f;
////                printf("%d %d\n", v, fail[v]);
//
//                len[v] = max(len[v], len[fail[v]]);
//            }
//        }
//    }
//    void query(char* s) {
//        int n = strlen(s);
//        for(int i = 0; i <= n; ++i) sum[i] = 0;
//        int u = 0;
//        for(int i = 0; i < n; i++) {
//            int c = s[i];
//            if(isupper(c)) c = tolower(c);
//            while(u && !nxt.getEdge(u, c))
//                u = fail[u];
//            int t = nxt.getEdge(u, c);
//            if(t) u = t;
//            int l = len[u];
////            pr(i); prln(l);
//            --sum[i - l + 1]; ++sum[i + 1];
//        }
//        for(int i = 1; i < n; ++i) sum[i] += sum[i - 1];
//        for(int i = 0; i < n; ++i) io.wchar(sum[i] ? '*' : s[i]);
//        io.wchar('\n');
//    }
//} ac;

//struct AC {
//    vector<map<char, int>> trie;
//    vector<int> endp;
//    vector<int> fail;
//    void init() {
//        trie.clear();
//        endp.clear();
//        fail.clear();
//        trie.resize(1);
//        endp.resize(1);
//    }
//    void add_string(char* s) {
//        int cur = 0;
//        int n = strlen(s);
//        for(int i = 0; i < n; i++) {
//            if(trie[cur].count(s[i]))
//                cur = trie[cur][s[i]];
//            else {
//                cur = trie[cur][s[i]] = trie.size();
//                trie.push_back(map<char, int>());
//                endp.push_back(0);
//            }
//        }
//        endp[cur] = n;
//    }
//    void build() {
//        fail.resize(trie.size());
//        vector<pair<int, pair<int, char>>> Q;
//        Q.push_back({0, {0, '\0'}});
//        fail[0] = 0;
//        for(int i = 0; i < (int)Q.size(); i++) {
//            int u = Q[i].first;
//            int p = Q[i].second.first;
//            char c = Q[i].second.second;
//            for(auto& it : trie[u])
//                Q.push_back({it.second, {u, it.first}});
//            if(u == 0)
//                continue;
//            int f = fail[p];
//            while(f != 0 && !trie[f].count(c))
//                f = fail[f];
//            if(!trie[f].count(c) || trie[f][c] == u)
//                fail[u] = 0;
//            else
//                fail[u] = trie[f][c];
//            endp[u] = max(endp[u], endp[fail[u]]);
//        }
//    }
//    void count(char* s) {
//        int n = strlen(s);
//        vector<int> sum(n + 1, 0);
//        int cur = 0;
//        for(int i = 0; i < n; i++) {
//            char c = s[i];
//            if(isupper(c)) c = tolower(c);
//            while(cur != 0 && !trie[cur].count(c))
//                cur = fail[cur];
//            if(trie[cur].count(c))
//                cur = trie[cur][c];
//            int l = endp[cur];
//            --sum[i - l + 1]; ++sum[i + 1];
//        }
//        for(int i = 1; i <= n; ++i) sum[i] += sum[i - 1];
//        for(int i = 0; i < n; ++i) if(sum[i]) s[i] = '*';
//        io.wstring(s);
//        io.wchar('\n');
//    }
//} ac;

struct ACAutomata {
    static const int S = 27;
    int sz, root;
    static const int M = 5e5 + 10;
    int nxt[M][S], fail[N], len[N], q[N];
    int sum[N];

    inline int idx(char c) {return c - 'a';}
    inline int newNode() {
        len[sz] = 0;
        memset(nxt[sz], 0, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    void insert(const char* s) {
        int u = root, i;
        for(i = 0; s[i]; ++i) {
            int c = idx(s[i]);
//            prln(c);
            int& v = nxt[u][c];
            if(!v) v = newNode();
//            printf("%d->%d\n", u, v);
            u = v;
        }
        len[u] = i;
    }
    void build() {
        int st, ed; st = ed = 0;
        fail[root] = root;
        for(int i = 0; i < S; ++i) {
            int& v = nxt[root][i];
//            prln(v);
            if(v) {
//              prln(v);
                fail[v] = root;
                q[ed++] = v;
            } else v = root;
        }
        for(; st < ed; ++st) {
            int u = q[st];
//            prln(u);
            for(int i = 0; i < S; ++i) {
                int& v = nxt[u][i];
                if(v) {
                    fail[v] = nxt[fail[u]][i];
//                    printf("fail[%d] = %d\n", v, fail[v]);
                    len[v] = max(len[v], len[nxt[fail[u]][i]]);
                    q[ed++] = v;
                } else v = nxt[fail[u]][i];
            }
        }
    }
    void query(char* s) {
        int u = root, n = strlen(s);
        for(int i = 1; i <= n; ++i) sum[i] = 0;
        for(int i = 0; i < n; ++i) {
            int c = isalpha(s[i]) ? tolower(s[i]) - 'a' : 26;
//          pr(i); pr(c);
            u = nxt[u][c];
            int l = len[u];
//           prln(l);
            ++sum[i - l + 1]; --sum[i + 1];
        }
        for(int i = 1; i <= n; ++i) sum[i] += sum[i - 1];
        for(int i = 0; i < n; ++i) if(sum[i]) s[i] = '*';
        puts(s);
    }
} ac;

char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  prln(int('\n'));

    int t; scanf("%d",  &t);
    while(t--) {
        int n; scanf("%d", &n);
        ac.init();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            ac.insert(s);
        }
//        prln(1);
        ac.build();
        getchar();
        gets(s);
//      puts(s);
        ac.query(s);
    }


    return 0;
}
