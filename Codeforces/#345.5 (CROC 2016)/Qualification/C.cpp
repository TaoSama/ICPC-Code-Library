//
//  Created by TaoSama on 2016-03-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int n;
string word[N << 1];
set<int> G[N << 1]; //save each address by host

typedef unsigned long long ULL;
map<ULL, int> toHost; //hash
vector<int> host[N << 1];

map<string, int> mp;
int ID(string& s) {
    static int cnt = 0;
    if(!mp.count(s)) {
        mp[s] = ++cnt;
        word[cnt] = s;
        return cnt;
    }
    return mp[s];
}

void process(string s) {
    auto p = s.find('/', 7);
    string hostS = s.substr(0, p), pathS = p == string::npos ? "" : s.substr(p);
    G[ID(hostS)].insert(ID(pathS));
}

void insert(int i) {
    ULL code = 0;
    for(int x : G[i]) code = code * 1333333331 + x;
    static int cnt = 0;
    if(!toHost.count(code)) {
        toHost[code] = ++cnt;
        host[cnt].push_back(i);
    } else host[toHost[code]].push_back(i);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        char buf[50]; scanf("%s", buf);
        process(buf);
    }
    for(int i = 1; i <= n << 1; ++i)
        if(G[i].size()) insert(i);

    vector<int> ans;
    for(auto p : toHost) if(host[p.second].size() > 1) ans.push_back(p.second);
    printf("%d\n", ans.size());
    for(int x : ans) {
        for(int y : host[x]) printf("%s ", word[y].c_str());
        puts("");
    }
    return 0;
}
