//
//  Created by TaoSama on 2017-01-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

const string rev = "A!!!3!!HIL!JM!O!!!2TUVWXY51SE!Z!!8!";

int getId(char c) {
    if(isupper(c)) return c - 'A';
    else return c - '1' + 26;
}

bool isPalindrome(string& s) {
//    for(int i = 0; i < s.size(); ++i){
//        if(s[i] != s[s.size() - i - 1]) return false;
//    }
//    return true;
    string rev(s.rbegin(), s.rend());
    return s == rev;
}

bool isMirrored(string& s) {
    string mirrored = s;
    for(char& c : mirrored) {
        int id = getId(c);
        if(rev[id] == '!') return false;
        c = rev[id];
    }
    reverse(mirrored.begin(), mirrored.end());
    return s == mirrored;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif//
//  Created by TaoSama on 2017-01-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

const string rev = "A!!!3!!HIL!JM!O!!!2TUVWXY51SE!Z!!8!";

int getId(char c) {
    if(isupper(c)) return c - 'A';
    else return c - '1' + 26;
}

bool isPalindrome(string& s) {
//    for(int i = 0; i < s.size(); ++i){
//        if(s[i] != s[s.size() - i - 1]) return false;
//    }
//    return true;
    string rev(s.rbegin(), s.rend());
    return s == rev;
}

bool isMirrored(string& s) {
    string mirrored = s;
    for(char& c : mirrored) {
        int id = getId(c);
        if(rev[id] == '!') return false;
        c = rev[id];
    }
    reverse(mirrored.begin(), mirrored.end());
    return s == mirrored;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  cout << ch << endl;

    string s;
    while(cin >> s) {
        bool retPalindrome = isPalindrome(s);
        bool retMirrored = isMirrored(s);
        if(!retPalindrome && !retMirrored)
            cout << s << " -- is not a palindrome.\n";
        else if(retPalindrome && !retMirrored)
            cout << s << " -- is a regular palindrome.\n";
        else if(!retPalindrome && retMirrored)
            cout << s << " -- is a mirrored string.\n";
        else cout << s << " -- is a mirrored palindrome.\n";
        cout << '\n';
    }

    return 0;
}

    ios_base::sync_with_stdio(0);

//  cout << ch << endl;

    string s;
    while(cin >> s) {
        bool retPalindrome = isPalindrome(s);
        bool retMirrored = isMirrored(s);
        if(!retPalindrome && !retMirrored)
            cout << s << " -- is not a palindrome.\n";
        else if(retPalindrome && !retMirrored)
            cout << s << " -- is a regular palindrome.\n";
        else if(!retPalindrome && retMirrored)
            cout << s << " -- is a mirrored string.\n";
        else cout << s << " -- is a mirrored palindrome.\n";
        cout << '\n';
    }

    return 0;
}
