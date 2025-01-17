#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int INF = 1e8;

vi memo;

int steps(int n) {
    if (n == 0) {
        return 0;
    }

    if (memo[n] < INF) return memo[n];

    vi digits;
    int k = n;

    while (k != 0) {
        digits.push_back(k%10);
        k /= 10;
    }

    int minimum = INF;

    for (auto d: digits) {
        if (d != 0) minimum = min(minimum, steps(n-d)+1);
    }

    memo[n] = minimum;

    return minimum;
}

signed main() {
    fastio();

    int n;
    cin >> n;

    memo.resize(n+1, INF);

    cout << steps(n) << endl;
    
    return 0;
}