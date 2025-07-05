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

const int MAX_N = 200'005;

int n, c, atual; 
int a[MAX_N];
int b[MAX_N];

int best(int dia) {
    if (c <= atual) return 0;
    int d1 = (c-atual)/a[dia] + ((c-atual)%a[dia] == 0 ? 0 : 1);

    if (dia == n) return d1;

    int at;
    if (b[dia] <= atual) at = 0;
    else at = (b[dia]-atual)/a[dia] + ((b[dia]-atual)%a[dia] == 0 ? 0 : 1);

    atual = atual + a[dia]*at - b[dia];

    int d2 = at + best(dia+1) + 1;
    return min(d1, d2);
}

void solve() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    atual = 0;
    cout << best(1) << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}