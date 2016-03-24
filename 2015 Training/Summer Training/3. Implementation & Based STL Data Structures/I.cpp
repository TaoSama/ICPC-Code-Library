//
//  Created by TaoSama on 2015-07-20
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

int n, cut;
double money[75];
struct P {
    char name[25], place[5];
    int n, rd[4], sc2, sc4;
    bool is, dq;
    bool operator< (const P& rhs) const {
        if(dq && rhs.dq) {
            if(n == rhs.n) {
                if(sc4 == rhs.sc4) return strcmp(name, rhs.name) < 0;
                else return sc4 < rhs.sc4;
            } else return n > rhs.n;
        }
        if(dq) return false;
        if(rhs.dq) return true;
        if(n == rhs.n) {
            if(sc4 == rhs.sc4) return strcmp(name, rhs.name) < 0;
            else return sc4 < rhs.sc4;
        } else return n > rhs.n;
    }
} a[205];

bool isCut(const P& x, const P& y) {
//  if(x.sc2 < 0 && y.sc2 < 0) return false;
    if(x.sc2 < 0) return false;
    if(y.sc2 < 0) return true;
    return x.sc2 < y.sc2;
}

void read() {
    char buf[105], tmp[5];
    for(int i = 0; i <= 70; ++i) {
        gets(buf);
        sscanf(buf, "%lf", money + i);
    }
    gets(buf);
    sscanf(buf, "%d", &n);

    for(int i = 1; i <= n; ++i) {
        gets(buf);
        a[i].is = a[i].dq = false;
        for(int j = 0; j < 20; ++j) {
            a[i].name[j] = buf[j];
            if(buf[j] == '*') a[i].is = true;
        }
        a[i].name[20] = 0;
        a[i].sc2 = a[i].sc4 = 0;
        for(int j = 0; j < 4; ++j) {
            sscanf(buf + 20 + j * 3, "%s", tmp);
            if(tmp[0] == 'D') {
                a[i].n = j;
                a[i].dq = true;
                if(j < 2) a[i].sc2 = -1;
                break;
            } else a[i].rd[j] = atoi(tmp);
            if(j < 2) a[i].sc2 += a[i].rd[j];
            if(j < 4) a[i].sc4 += a[i].rd[j];
        }
        if(!a[i].dq) a[i].n = 4;
    }

//    for(int i = 1; i <= n; ++i) {
//        printf("%s ", a[i].name);
//        for(int j = 0; j < a[i].n; ++j)
//            printf("%d ", a[i].rd[j]);
//        puts("");
//    }
}

void makeCut() {
    for(int i = 1; i <= n; ++i) {
//      printf("%s ", a[i].name);
//        for(int j = 0; j < a[i].n; ++j)
//            printf("%d ", a[i].rd[j]);
//      if(a[i].dq) printf("DQ");
//        puts("");
        if(a[i].sc2 < 0) {
            cut = i - 1;
            return;
        }
        if(i == 70) {
            while(i + 1 <= n && a[i + 1].sc2 == a[i].sc2) ++i;
            cut = i;
            return;
        }
    }
}

void print() {
    printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
    printf("-----------------------------------------------------------------------\n");

    int i = 1, p = 1;
    while(i <= cut) {
        if(a[i].dq) {
            printf("%s           ", a[i].name);
            for(int j = 0; j < a[i].n; ++j)
                printf("%-5d", a[i].rd[j]);
            for(int j = 0; j < 4 - a[i].n; ++j) printf("     ");
            printf("DQ\n");
            i++;
            continue;
        }
        int j = i, num = 0;
        double tot = 0;
        bool have = false;
        while(j <= cut && a[j].sc4 == a[i].sc4) {
            if(!a[j].is) {
                ++num;
                if(p <= 70) {
                    have = true;
                    tot += money[p++];
                }
            }
            ++j;
        }

        int place = i;
        double each = money[0] * tot / num / 100; // m=0 no care
        while(i < j) {
            printf("%s ", a[i].name);
            sprintf(a[i].place, "%d%c", place, num > 1 && have && !a[i].is ? 'T' : ' ');
            printf("%-10s", a[i].place);
            for(int k = 0; k < a[i].n; ++k) printf("%-5d", a[i].rd[k]);

            if(have && !a[i].is) {
                printf("%-10d", a[i].sc4);
                printf("$%9.2f\n", each + 1e-8);
            } else printf("%-3d\n", a[i].sc4);
            ++i;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; char buf[105]; gets(buf);
    sscanf(buf, "%d", &t);
    while(t--) {
        gets(buf); //empty line
        read();
        sort(a + 1, a + 1 + n, isCut);
        makeCut();
        sort(a + 1, a + 1 + cut);
        print();
        if(t) puts("");
    }
    return 0;
}
