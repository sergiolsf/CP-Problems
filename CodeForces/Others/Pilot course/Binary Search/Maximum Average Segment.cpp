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
int ini, fim;

bool good (double t) {
    vector<double> minimum (n+1);
    vector<double> sum (n+1);
    vi menor (n+1, 0);
    
    minimum[0] = 0;
    sum[0] = 0;

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + (double) a[i] - t;

        if (minimum[i-1] >= sum[i]) {
            minimum[i] = sum[i];
            menor[i] = i+1;
        } else { 
            menor[i] = menor[i-1];
            minimum[i] = minimum[i-1];
        }

        if (sum[i] >= 0 && i >= d) {
            ini = 1;
            fim = i;
            return true;
        }
        if (i-d >= 1) {
            if (sum[i] - minimum[i-d] >= 0) {
                ini = menor[i-d];
                fim = i;
                return true;
            }
        }
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
        if (a[i] > 0) ok = true;
    }

    if (!ok) {
        cout << 1 << " " << d << endl;
        return 0;
    }

    double l = 0;
    double r = 1000;

    for (int i = 1; i <= 100; i++) {
        double m = (r+l)/2.0;
        if (good(m)) l = m;
        else r = m;
    }

    cout << ini << " " << fim << endl;
  
    return 0;
}