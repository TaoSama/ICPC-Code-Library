//
//  Created by TaoSama on 2017-01-18
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
#include <sstream>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<string> level[N];

void dfs(int d, int& maxd, stringstream& ss) {
    maxd = max(maxd, d);
    string s; ss >> s;
    level[d].push_back(s);
    int sons; ss >> sons;
    for(int i = 0; i < sons; ++i)
        dfs(d + 1, maxd, ss);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string line; getline(cin, line);
    for(char& c : line) if(c == ',') c = ' ';
    stringstream ss(line);

    string s;
    int maxd = 1;
    while(ss >> s) {
        level[1].push_back(s);
        int sons; ss >> sons;
        for(int i = 0; i < sons; ++i)
            dfs(2, maxd, ss);
    }

    cout << maxd << '\n';
    for(int i = 1; i <= maxd; ++i) {
        for(int j = 0; j < level[i].size(); ++j) {
            cout << level[i][j] << " \n"[j + 1 == level[i].size()];
        }
    }

    return 0;
}
