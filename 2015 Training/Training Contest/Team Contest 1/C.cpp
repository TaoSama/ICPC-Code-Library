//
//
//
//  Created by TaoSama on 2015-03-26
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

string ss = "START", gg = "END";

void read(string &s) {
    string tt;
    while(getline(cin, tt)) {
        //cout<<"tt: "<<tt<<endl;
        if(tt == ss) continue;
        if(tt == gg) break;
        if(tt == "") tt = "\n";
        s += tt;
    }
}

bool isWhite(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}
string ans[3] = {"Presentation Error", "Wrong Answer", "Accepted"};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t; cin.get();
    while(t--) {
        string in, out;
        read(in);
        read(out);
        //<<in<<endl;
        //cout<<out<<endl;
        int x;
        int i = 0, j = 0;
        bool pe = false, wa = false;
        while(i < in.size() && j < out.size()) {
            if(isWhite(in[i]) || isWhite(out[j])) {
                if(in[i] != out[j]) pe = true;
                while(isWhite(in[i])) ++i;
                while(isWhite(out[j])) ++j;
            } else {
                if(in[i] != out[j]) {
                    wa = true;
                    break;
                } else ++i, ++j;
            }
        }
        if(i == in.size() && j < out.size()) {
            for(int k = j; k < out.size(); ++k) {
                if(!isWhite(out[k])) {
                    wa = true;
                    break;
                }
            }
            if(!wa) pe = true;
        } else if(i < in.size() && j == out.size()) {
            for(int k = i; k < in.size(); ++k) {
                if(!isWhite(in[k])) {
                    wa = true;
                    break;
                }
            }
            if(!wa) pe = true;
        }
        if(wa) x = 1;
        else if(pe) x = 0;
        else x = 2;
        cout << ans[x] << endl;
    }
    return 0;
}
