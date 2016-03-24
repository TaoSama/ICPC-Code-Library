//
//  Created by TaoSama on 2015-07-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s;

void dfs(vector<stack<string> >& v, int x, int y) {
    string &a = v[x].top();
    if(y < v.size()) {
        string &b = v[y].top();
        if(a[0] == b[0] || a[1] == b[1]) {
//          cout << v[x].top() << ' ' << v[y].top() << endl;
            v[x].push(v[y].top());
            if(v[y].size() == 1) v.erase(v.begin() + y);
            else v[y].pop();
            dfs(v, x, y);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s && s != "#") {
        vector<stack<string> > v(52);
        v[0].push(s);
        for(int i = 1; i < 52; ++i) {
            cin >> s;
            v[i].push(s);
        }

        while(true) {
            bool isMove = false;
            for(int i = 0; i < v.size(); ++i) {
                string &a = v[i].top();
                if(i - 3 >= 0) {
                    string &b = v[i - 3].top();
                    if(a[0] == b[0] || a[1] == b[1]) {
                        v[i - 3].push(v[i].top());
                        if(v[i].size() == 1) v.erase(v.begin() + i);
                        else v[i].pop();
                        isMove = true;
                        break;
                    }
                }
                if(i - 1 >= 0) {
                    string &b = v[i - 1].top();
                    if(a[0] == b[0] || a[1] == b[1]) {
                        v[i - 1].push(v[i].top());
                        if(v[i].size() == 1) v.erase(v.begin() + i);
                        else v[i].pop();
                        isMove = true;
                        break;
                    }
                }
            }
            if(!isMove) break;
        }

        cout << v.size() << " pile" << (v.size() > 1 ? "s" : "") << " remaining: ";
        for(int i = 0; i < v.size(); ++i) {
            if(i) cout << ' ';
            cout << v[i].size();
        }
        cout << '\n';
    }
    return 0;
}
