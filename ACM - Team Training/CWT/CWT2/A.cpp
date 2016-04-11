//
//  Created by TaoSama on 2016-01-20
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

string s;

bool isSeperator(char c) {
    return c == ',' || c == ';';
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        string a, b, word;
        bool isNumber = true, first = true;
        bool haveA = false, haveB = false;
        s += ',';
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(isSeperator(c)) {
                if(!word.size()) isNumber = false;
                if(isNumber) {
                    if(haveA) a += "," + word;
                    else a += word, haveA = true;
                } else {
                    if(haveB) b += "," + word;
                    else b += word, haveB = true;
                }
                isNumber = first = true;
                word.clear();
            } else {
                word += c;
                if(!isdigit(c) || c == '.') isNumber = false;
                if(first) {
                    first = false;
                    if(c == '0' && !isSeperator(s[i + 1])) isNumber = false;
                }
            }
        }
        if(haveA) cout << "\"" << a << "\"\n";
        else cout << "-\n";
        if(haveB) cout << "\"" << b << "\"\n";
        else cout << "-\n";
    }
    return 0;
}
