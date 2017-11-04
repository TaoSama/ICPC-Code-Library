//
//  Created by TaoSama on 2017-05-16
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

void dfs(int dep, const vector<int>& v,
         const vector<int>& seq, set<vector<int>>& ret) {
    if(dep == seq.size()) {
        if(v.size()) ret.insert(v);
        return;
    }
    dfs(dep + 1, v, seq, ret);
    if(!v.size() || v.size() && seq[dep] >= v.back()) {
        vector<int> nv = v;
        nv.push_back(seq[dep]);
        dfs(dep + 1, nv, seq, ret);
    }
}

vector<vector<int>> getSubSeq(const vector<int>& seq) {
    set<vector<int>> ret;
    dfs(0, vector<int>(), seq, ret);
    return vector<vector<int>>(ret.begin(), ret.end());
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    vector<int> test = {4, 6, 7, 7};
    vector<vector<int>> ans = getSubSeq(test);
    for(const auto& v : ans) {
        for(int x : v) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
