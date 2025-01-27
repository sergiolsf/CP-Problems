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

signed main() {
    fastio();
    int n;
    cin >> n;

    vi a(n+2);
    int s = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }

    if (s%3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int x = s/3;

    int ini = -1, fim = -1;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum == x) {
            ini = i;
            break;
        }
    }

    sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += a[i];
        if (sum == x) {
            fim = i;
            break;
        }
    }

    if (fim <= ini || fim == -1 || ini == -1) {
        cout << 0 << endl;
        return 0;
    }

    sum = 0;
    int count = 0;
    int ans = 0;
    for (int i = ini+1; i < fim; i++) {
        sum += a[i];
        if (sum == x) {
            count++;
        }
    }

    ans += count;
    sum = 0;

    for (int i = ini+1; i < fim; i++) {
        sum += a[i];
        if (sum == x) {
            count--;
        }
        if (sum == 0) {
            ans += count;
        }
    }

    cout << ans << endl;    
    return 0;
}