//
//  Created by TaoSama on 2015-10-05
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
#include <sstream>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Word {
    char c[35];
    int l;
    bool operator< (const Word& rhs) const {
        return strcmp(c, rhs.c) < 0;
    }
    bool operator!= (const Word& rhs) const {
        if(l == rhs.l) return strcmp(c, rhs.c);
        return true;
    }
} word;

char line[85];
map<Word, Word> mp;
bool isWord;

Word abbr(Word s) {
    Word x; x.l = -1;
    if(isWord) {
        if(s.l < 4) return x;
        for(int i = 0; i < s.l; ++i) s.c[i] = tolower(s.c[i]);
        sprintf(x.c, "%c%d%c", s.c[0], s.l - 2, s.c[s.l - 1]);
        if(mp.count(x)) {
            Word &tmp = mp[x];
            if(tmp.l != -1 && tmp != s) tmp.l = -1;
        } else mp[x] = s;
        return x;
    } else {
        s.c[0] = tolower(s.c[0]);
        s.c[s.l - 1] = tolower(s.c[s.l - 1]);
//        puts(s.c);
        return mp.count(s) ? mp[s] : x;
    }
}

void format(Word& s, Word& t) {
    if(isupper(s.c[0])) {
        if(islower(s.c[s.l - 1])) {
            for(int i = 0; i < t.l; ++i) {
                if(i == 0) putchar(toupper(t.c[i]));
                else putchar(t.c[i]);
            }
        } else for(int i = 0; i < t.l; ++i) putchar(toupper(t.c[i]));
    } else {
        for(int i = 0; i < t.l; ++i) putchar(t.c[i]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

    while(gets(line)) {
        for(int i = 0; line[i];) {
            if(!isalnum(line[i])) putchar(line[i++]);

            int p = 0;
            isWord = true;
            while(isalnum(line[i])) {
                if(isdigit(line[i])) isWord = false;
                word.c[p++] = line[i++];
            }
            word.c[p] = 0; word.l = p;
            Word t = abbr(word);
            if(~t.l) format(word, t);
            else printf("%s", word.c);
        }
        puts("");
    }
    return 0;
}
