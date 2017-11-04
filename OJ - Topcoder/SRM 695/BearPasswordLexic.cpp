#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class BearPasswordLexic {
    public:
    string findPassword(vector<int> x) {
        int n = x.size();
        vector<int> c;
        for(int i = n - 1; ~i; --i){
            while(x[i]--){
                c.push_back(i + 1);
                for(int j = i - 1; ~j; --j) {
                    x[j] -= i - j + 1;
                    if(x[j] < 0) return "";
                }
            }
        }

        int all = accumulate(c.begin(), c.end(), 0);
        if(all != n) return "";

        sort(c.begin(), c.end());
        string ans;
        for(int i = c.size() - 1, j = 0; i >= j; --i, ++j){
            ans += string(c[i], 'a');
            if(i != j) ans += string(c[j], 'b');
        }

        return ans;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x ){ return x < 0;}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {5,0,0,0,0} }, {"ababa"} },
    { { {4,2,1,0} }, {"aaab"} },
    { { {3,1,1} }, {""} },
    { { {4,3,2,1} }, {"aaaa"} },
    { { {0} }, {""} },
    { { {4,0,3,2} }, {""} },
    // Your custom test goes here:
    { { {6, 3, 1, 0, 0, 0}}, {"aaabaa"} },
};}

//------------------------------------------------------------------------------
// Tester code:
    #define DISABLE_COLORS

    #include "tester.cpp"
    struct input {
        vector<int> p0;

        string run(BearPasswordLexic* x) {
            return x->findPassword(p0);
        }
        void print() {
            //Tester::printArgs(p0);
        }
    };

    int main() {
        return Tester::runTests<BearPasswordLexic>(
            getTestCases<input, Tester::output<string>>(), disabledTest,
            300, 1468925974, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
