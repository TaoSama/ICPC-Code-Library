//
//  Created by TaoSama on 2015-07-21
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

string a, b, zero = "0";

void read(string& a, set<pair<string, string> >& s) {
    bool iskey = true;
    string key, val;
//    cout << a << endl;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] == '{') continue;
        if(a[i] == ':') {
            iskey = false;
            continue;
        }
        if(a[i] == ',' || a[i] == '}') {
            iskey = true;
            if(key.size() && val.size()) s.insert({key, val});
//            cout << key << ' ' << val << endl;
            key.clear(); val.clear();
            continue;
        }
        if(iskey) key += a[i];
        else val += a[i];
    }
}

void get(vector<string>& add, set<pair<string, string> >& s,
         set<pair<string, string> >& t) {
//  if(s.empty()){
//      for(auto &i : t) add.push_back(i.first);
//      return;
//  }
    for(auto &i : t) {
        auto now = s.lower_bound({i.first, "0"});
//        if(now != s.end()) cout << now->first << ' ' << now->second << ' ' << i.first << endl;
        if(now == s.end() || now->first != i.first) {
            add.push_back(i.first);
        }
    }
}

void print(vector<string>& add) {
    for(int i = 0; i < add.size(); ++i) {
        if(i > 0) cout << ',';
        cout << add[i];
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t; cin.get();
    while(t--) {
        set<pair<string, string> > s, t;
        getline(cin, a); getline(cin, b);
        read(a, s);
        read(b, t);
//      cout << s.size() << ' ' << t.size() << endl;
        vector<string> add, sub, ast;
        //add
        get(add, s, t);
//        cout << endl;
        //sub
        get(sub, t, s);
//        cout << endl;
        //change
        for(auto &i : s) {
            auto now = t.lower_bound({i.first, zero});
            if(now != t.end() && now->first == i.first &&
                    now->second != i.second)
                ast.push_back(i.first);
        }

        if(add.size()) {cout << '+'; print(add); cout << '\n';}

        if(sub.size()) {cout << '-'; print(sub); cout << '\n';}

        if(ast.size()) {cout << '*'; print(ast); cout << '\n';}
        if(add.size() + sub.size() + ast.size() == 0) cout << "No changes\n";
        cout << '\n';
    }
    return 0;
}
