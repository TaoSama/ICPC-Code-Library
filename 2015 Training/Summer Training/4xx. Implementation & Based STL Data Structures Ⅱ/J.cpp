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
#include <sstream>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, cnt, row[105];
bool found;
string line, x, s[105][1500];
map<string, int> mp;
map<int, set<int> > text, wh[105];

void outAll(vector<string>& op) {
    int query = mp[op[0]];  //the word
    bool more = false;
    for(auto &j : text[query]) {
        if(more) cout << "----------\n";
        if(!more) more = true;
        //the rows of the word in the essay
        for(auto &k : wh[j][query]) {
            found = true;
            cout << s[j][k] << '\n';
        }
    }
}

void outNot(vector<string>& op) {
    bool have[105];  memset(have, false, sizeof have);
    int query = mp[op[1]];
    //mark the have essay
    for(auto &j : text[query]) have[j] = true;

    //output the whole essay
    bool more = false;
    for(int j = 1; j <= n; ++j) {
        if(!have[j]) {
            if(more) cout << "----------\n";
            if(!more) more = true;
            for(int k = 1; k < row[j]; ++k) {
                found = true;
                cout << s[j][k] << '\n';
            }
        }
    }
}

void outAnd(vector<string>& op) {
    int l = mp[op[0]], r = mp[op[2]];
    set<int> AND;  //get the AND essay
    set_intersection(text[l].begin(), text[l].end(), text[r].begin(),
                     text[r].end(), inserter(AND, AND.begin()));

    bool more = false;
    for(auto &i : AND) {
        if(more) cout << "----------\n";
        if(!more) more = true;
        set<int> mix;  //to get the appearing rows
        set_union(wh[i][l].begin(), wh[i][l].end(), wh[i][r].begin(), wh[i][r].end(),
                  inserter(mix, mix.begin()));

        for(auto &j : mix) {
            found = true;
            cout << s[i][j] << '\n';
        }
    }
}

void outOr(vector<string>& op) {
    int l = mp[op[0]], r = mp[op[2]];
    set<int> OR;  //get the OR essay
    set_union(text[l].begin(), text[l].end(), text[r].begin(), text[r].end(),
              inserter(OR, OR.begin()));

    bool more = false;
    for(auto &i : OR) {
        if(more) cout << "----------\n";
        if(!more) more = true;
        set<int> mix;  //to get the appearing rows
        set_union(wh[i][l].begin(), wh[i][l].end(), wh[i][r].begin(), wh[i][r].end(),
                  inserter(mix, mix.begin()));

        for(auto &j : mix) {
            found = true;
            cout << s[i][j] << '\n';
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n; cin.get();
    for(int i = 1; i <= n; ++i) {
        while(getline(cin, s[i][++row[i]]) && s[i][row[i]] != "**********") {
            stringstream ss(s[i][row[i]]);
            while(ss >> x) {
                //for convenience add a garbage
                x += ' ';
                //to erase the garbage to get the word & to lowercase
                string each;
                for(char &c : x) {
                    if(isalpha(c)) each += tolower(c);
                    else {
                        if(each.empty()) continue;
//                        cout << each << endl;
                        if(!mp.count(each)) mp[each] = ++cnt;
                        int now = mp[each];
                        text[now].insert(i);
                        wh[i][now].insert(row[i]);
                        each.clear();
                    }
                }
            }
        }
    }

    cin >> m; cin.get();
    for(int i = 1; i <= m; ++i) {
        getline(cin, line);
        vector<string> op;
        stringstream ss(line);
        while(ss >> x) op.push_back(x);

        found = false;
        if(op.size() == 1) outAll(op);     //all
        else if(op.size() == 2) outNot(op); //not
        else {
            if(op[1][0] == 'A') outAnd(op); //and
            else outOr(op);                 //or
        }
        if(!found) cout << "Sorry, I found nothing.\n";
        cout << "==========\n";
    }
    return 0;
}
