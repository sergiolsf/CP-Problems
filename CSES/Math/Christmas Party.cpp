#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int MOD = 1e9+7;

int good (int n) {
    if (n == 1) return 0;
    int c = 1;
    if (n&1) c = -1;
    return (n*good(n-1)+c)%MOD;
}

signed main() {
    fastio();
    int n;
    cin >> n;
    cout << good(n) << endl;  
    return 0;
}