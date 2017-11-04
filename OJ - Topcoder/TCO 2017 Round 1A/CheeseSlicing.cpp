#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class CheeseSlicing {
    public:
        int f[N][N][N];
        int check(int a, int b, int c, int s) {
            if(a > b) swap(a, b);
            if(a > c) swap(a, c);
            if(b > c) swap(b, c);
            if(a < s) return 0;
            return b * c;
        }
        int dfs(int a, int b, int c, int s) {
            int& ret = f[a][b][c];
            if(~ret) return ret;
            ret = check(a, b, c, s);
            if(ret == 0) return ret;
            for(int i = 1; i < a; ++i)
                ret = max(ret, dfs(a - i, b, c, s) + check(i, b, c, s));
            for(int i = 1; i < b; ++i)
                ret = max(ret, dfs(a, b - i, c, s) + check(a, i, c, s));
            for(int i = 1; i < c; ++i)
                ret = max(ret, dfs(a, b, c - i, s) + check(a, b, i, s));
            return ret;
        }
        int totalArea(int A, int B, int C, int S) {
            memset(f, -1, sizeof f);
            return dfs(A, B, C, S);
        }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) { return x < 0;}
template<class I, class O> vector<pair<I, O>> getTestCases() {
    return {
        { { 1, 3, 3, 2 }, {0} },
        { { 5, 3, 5, 3 }, {25} },
        { { 5, 5, 5, 2 }, {58} },
        { { 49, 92, 20, 3 }, {30045} },
        // Your custom test goes here:
        //{ { , , , }, {} },
    };
}

//------------------------------------------------------------------------------
// Tester code:
#define DISABLE_COLORS

#include "tester.cpp"
struct input {
    int p0; int p1; int p2; int p3;

    int run(CheeseSlicing* x) {
        return x->totalArea(p0, p1, p2, p3);
    }
    void print() {
        //Tester::printArgs(p0,p1,p2,p3);
    }
};

int main() {
    return Tester::runTests<CheeseSlicing>(
               getTestCases<input, Tester::output<int>>(), disabledTest,
               500, 1491064011, CASE_TIME_OUT, Tester::COMPACT_REPORT
           );
}
// CUT end
