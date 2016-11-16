#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char a[2][15];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL

    string str;
    while(cin >> str) {
        map<char, int> mp;
        int s = -1, t = -1;
        memset(a, 0, sizeof a);
        for(int i = 0; i < 27; ++i) {
            if(mp.count(str[i])) {
                s = mp[str[i]];
                t = i;
            }
            mp[str[i]] = i;
        }

        if(s + 1 == t) {
            cout << "Impossible\n";
            continue;
        }

        int len = t - s, hf = (len + 1) / 2;
        if(hf == 14) --hf;

        int p1, p2;

//        printf("s = %d t = %d hf = %d\n", s, t, hf);
        auto pr = [&]() {
            for(int i = 0; i < 2; ++i) {
                for(int j = 0; j < 13; ++j)
                    printf("%c", a[i][j]);
                puts("");
            }
        };

        p1 = 0, p2 = 12 - hf;
        if(p2 < 0) p1 = 1, p2 = 0;
        for(int i = s - 1; i >= 0; --i) {
            a[p1][p2] = str[i];
            if(p1 == 0) {
                if(--p2 == -1) p1 = 1, p2 = 0;
            } else {
                ++p2;
            }
        }
//        pr();

        p1 = 0, p2 = 12 - hf + 1;
        for(int i = s; i < t; ++i) {
            a[p1][p2] = str[i];
            if(p1 == 0) {
                if(++p2 == 13) p1 = 1, p2 = 12;
            } else {
                --p2;
            }
        }
//        pr();

        for(int i = t + 1; i < str.size(); ++i) {
            a[p1][p2] = str[i];
            if(p1 == 1) {
                if(--p2 == -1) p1 = 0, p2 = 0;
            } else ++p2;
        }
        pr();
    }
    return 0;
}
