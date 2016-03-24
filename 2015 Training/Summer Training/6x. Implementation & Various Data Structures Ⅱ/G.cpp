//
//  Created by TaoSama on 2015-07-24
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
#include <sstream>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

map<string, int> mp;
string s, name[N];
vector<int> depend[N], need[N], installed;
int cnt, state[N]; //0->haven't installed 1->explicit 2->implicit

void install(int id, bool top) {
    if(!state[id]) {
        for(auto &i : depend[id])
            install(i, false);
        cout << "   Installing " << name[id] << '\n';
        state[id] = top ? 1 : 2;
        installed.push_back(id);
    }
}

bool isNeeded(int id) {
    for(auto &i : need[id])
        if(state[i]) return true;
    return false;
}

void remove(int id, bool top) {
    if((top || state[id] == 2) && !isNeeded(id)) {
        state[id] = 0;
        installed.resize(remove(installed.begin(), installed.end(),
                                id) - installed.begin());
        cout << "   Removing " << name[id] << '\n';
        for(auto &i : depend[id]) {
            remove(i, false);
        }
    }
}

int getId(string& x) {
    if(!mp.count(x)) {
        mp[x] = ++cnt;
        name[cnt] = x;
    }
    return mp[x];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cnt = 0;
    while(getline(cin, s)) {
        cout << s << '\n';
        if(s == "END") break;
        stringstream ss(s);
        string op, x; ss >> op;
        if(op == "DEPEND") {
            ss >> x;
            int l = getId(x), r;
            while(ss >> x) {
                r = getId(x);
                depend[l].push_back(r);
                need[r].push_back(l);
            }
        } else if(op == "INSTALL") {
            ss >> x;
            int id = getId(x);
            if(state[id]) {
                cout << "   " << x << " is already installed.\n";
                continue;
            }
            install(id, true);
        } else if(op == "REMOVE") {
            ss >> x;
            int id = getId(x);
            if(isNeeded(id)) {
                cout << "   " << x << " is still needed.\n";
                continue;
            } else if(!state[id]) {
                cout << "   " << x << " is not installed.\n";
                continue;
            }
            remove(id, true);
        } else if(op == "LIST") {
            for(auto &i : installed)
                cout << "   " << name[i] << '\n';
        }
    }
    return 0;
}
