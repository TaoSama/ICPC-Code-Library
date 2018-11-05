#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// last:= 指向添加一个字符后形成的最长回文串的节点
// s[i]:= 第 i 次添加的字符 n:= s 数组时针
// fail[i]:= i 失配后跳转到的 i 表示的最长回文串的最长真后缀回文串的节点
// cnt[i]:= 以 i 表示的最长回文串的右端点为右端点的回文串个数
// dif[i]:= i 表示的本质不同的回文串个数 （需要重新统计）
struct PalindromicTree {
    static const int M = 8e5 + 10, S = 26;
    int n, sz, last;
    int nxt[M][S], fail[M], len[M], s[M];
    int cnt[M], dif[M];
    int newNode(int l) {
        len[sz] = l;
        cnt[sz] = dif[sz] = 0;
        memset(nxt[sz], 0, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = last = 0;
        newNode(0); newNode(-1);
        s[n = 0] = -1; // 无关字符减少特判
        fail[0] = 1;
    }
    int getFail(int u) {
        while(s[n - len[u] - 1] != s[n]) u = fail[u];
        return u;
    }
    void add(int c) {
        s[++n] = c;
        int u = getFail(last); // 找到这个回文串的匹配位置
        int& v = nxt[u][c];
        if(!v) {
            int cur = newNode(len[u] + 2);
            fail[cur] = nxt[getFail(fail[u])][c];
            v = cur;
            cnt[v] = cnt[fail[v]] + 1;
        }
        ++dif[v];
        last = v;
    }
    void count() {
        //父亲累加儿子，如果 fail[v]=u ，则 u 一定是 v 的子回文串
        for(int i = sz - 1; ~i; --i) dif[fail[i]] += dif[i];
    }
} pt;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    string s; cin >> s;
    pt.init();
    for(char c : s) pt.add(c - 'a');
    cout << pt.sz - 2 << endl;
    return 0;
}
