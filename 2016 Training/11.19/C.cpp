//
//  Created by TaoSama on 2016-11-19
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
#include <stack>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

inline bool go(stack<int>& from, stack<int>& to) {
    if(!from.size()) return false;
    if(!to.size() || from.top() < to.top()) {
        to.push(from.top());
        from.pop();
        return true;
    }
    return false;
}

inline void bk(stack<int>& from, stack<int>& to) {
    from.push(to.top());
    to.pop();
}


map<vector<stack<int> >, int> mp;
int dfs(vector<stack<int> > sta, int cnt) {
    if(mp.count(sta)) return mp[sta];
    int& ret = mp[sta];
    stack<int>& A = sta[0];
    stack<int>& B = sta[1];
    stack<int>& C = sta[2];
    if(C.size() == n) return ret = 0;
    ret = INF;

    if(go(A, B)) {
        ret = min(ret, dfs(sta, cnt + 1) + 1);
        bk(A, B);
    }
    if(go(B, A)) {
        ret = min(ret, dfs(sta, cnt + 1) + 1);
        bk(B, A);
    }
    if(go(B, C)) {
        ret = min(ret, dfs(sta, cnt + 1) + 1);
        bk(B, C);
    }
    if(go(C, B)) {
        ret = min(ret, dfs(sta, cnt + 1) + 1);
        bk(C, B);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
//      stack<int> A;
//      for(int i = n; i; --i) A.push(i);
//      vector<stack<int> > v(3, stack<int>());
//      v[0] = A;
//      int ans = dfs(v, 0);
        int f[20] = {};
        for(int i = 1; i <= n; ++i) f[i] = 3 * f[i - 1] + 2;
        printf("%d\n", f[n]);
    }

    return 0;
}
