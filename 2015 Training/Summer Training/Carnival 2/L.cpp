//
//  Created by TaoSama on 2015-08-02
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

vector<string> line;
vector<bool> is;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string x;
    while(getline(cin, x)) line.push_back(x);

    for(int i = 0; i < line.size(); ++i) {
        bool o = false;
//        cout << line[i] << endl;
        for(int j = 0; j < line[i].size(); ++j) {
            if(isspace(line[i][j])) continue;
            else if(line[i][j] == '#') {
                o = true;
                break;
            } else break;
        }
        is.push_back(o);
    }

    bool last = false, first = true;
    for(int i = 0; i < line.size(); ++i) {
        if(is[i]) {
            cout << line[i] << '\n', last = true;
            first = false;
            continue;
        } else {
            for(int j = 0; j < line[i].size(); ++j)
                if(!isspace(line[i][j])) cout << line[i][j];
        }
        bool newline = false;
        if(i > 0 && last && i + 1 < line.size() && is[i + 1])
            newline = true;
        if(first && i + 1 < line.size() && is[i + 1]) newline = true;
        if(newline || !is[i] && i == line.size() - 1) {
            first = false;
            cout << '\n';
        }
    }
    return 0;
}
