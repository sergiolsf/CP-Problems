#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vi v;

int f(int x) {
    int sum = 0;
    int ini = x;
    for (auto e: v) {
        sum += abs(ini-e);
        ini++;
    }
    return sum;
}

signed main() {
    fastio();
    int n;
    cin >> n;
    v.resize(n);
    for (auto &i : v) cin >> i;

    int l = -400000, r = 400000;
    for (int i = 0; i < 100; i++) {
        int delta = (r-l)/3;
        int m1 = l+delta;
        int m2 = r-delta;
        (f(m1) > f(m2)) ? l = m1: r = m2;
    }

    int ans = f(l);
    for (int i = l; i <= r; i++) {
        ans = min(ans, f(i));
    }

    cout << ans << endl;

    return 0;
}