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

int n, d;
vi a;

bool good (double x) {
    vector<double> sum (n+1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + (double) a[i] - x;
    }
    int indMenor = 1;
    double menor = 0;
    for (int i = 1; i <= n; i++) {
        if (i-d >= 1) { 
            if (menor >= sum[i-d]) {
                indMenor = i-d+1;
                menor = sum[i-d];
            }
        }
        if (sum[i] - menor >= 0 && i-indMenor >= d-1) return true;
    }
    return false;
}

signed main() {
    fastio();
    cin >> n >> d;
    a.resize(n+1);
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) ok = true;
    }

    if (!ok) {
        cout << 1 << " " << d << endl;
        return 0;
    }

    double l = 0;
    double r = 1000;

    for (int i = 1; i <= 100; i++) {
        double m = (r+l)/2;
        if (good(m)) l = m;
        else r = m;
    }

    /// a maior média é l

    vector<double> sum (n+1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + (double) a[i] - l;
    }
    double menor = 0;
    int indMenor = 1;
    for (int i = 1; i <= n; i++) {
        if (i-d >= 1) {
            if (menor >= sum[i-d]) { 
                indMenor = i-d+1; 
                menor = sum[i-d];
            }
        }
        if (sum[i] - menor >= 0 && i-indMenor >= d-1) {
            cout << indMenor << " " << i << endl;
            break;
        }
    }
    return 0;
}