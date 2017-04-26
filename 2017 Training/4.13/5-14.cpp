//
//  Created by TaoSama on 2017-04-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
map<pair<int, pair<string, string>>, set<pair<int, pair<string, string>>>> G;

int cnt = 0;
void dfs(pair<int, pair<string, string>> u, int d) {
//  if(++cnt > 20) return;
    auto& vec = G[u];
    for(auto& v : vec) {
        for(int i = 0; i < 2 * d; ++i) cout << ' ';
        cout << v.second.second << '\n';
        if(G[v].size()) dfs(v, d + 1);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        string line; cin >> line;
        for(char& c : line) if(c == '\\') c = ' ';
        bool isFile = line.back() != ' ';
        stringstream ss(line);
        string s; vector<string> vec;
        while(ss >> s)  vec.push_back(s);

        pair<int, pair<string, string>> fa = {0, {"root", "root"}};
        string name;
        for(int j = 0; j < vec.size(); ++j) {
            name += vec[j];
            pair<int, pair<string, string>> cur = {0, {name, vec[j]}};
            if(j + 1 == vec.size()) cur.first = isFile;
            G[fa].insert(cur);
            fa = cur;
        }
    }
    cout << "root\n";
    dfs({0, {"root", "root"}}, 1);

    return 0;
}
