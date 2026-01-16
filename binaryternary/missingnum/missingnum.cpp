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

int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);
    big n;
    eat >> n;
    big sum = 0;
    for (int i = 0; i < n-1; i++) {
        big x;
        eat >> x;
        sum += x;
    }

    cout << ((n+1)*(n)/2 - sum) << endl;
}