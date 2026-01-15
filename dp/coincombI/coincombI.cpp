#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define eat cin
#define big long long
#define endl "\n"

const int MOD = 1000000007;
int n;
int x;

int dp[1000005];
int c[105];
int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);

    eat >> n >> x;

    for (int i =0; i <n; i++) {
        int coin;
        eat >> coin;
        c[i]  = coin;
    }

    dp[0] = 1;


    for (int t = 0; t <= x; t++) {
        for (int i = 0; i < n; i++) {
            if (t < c[i]) continue;
            dp[t] += dp[t-c[i]];
            dp[t] %= MOD;
        }
    }

    cout << dp[x]<< endl;
}