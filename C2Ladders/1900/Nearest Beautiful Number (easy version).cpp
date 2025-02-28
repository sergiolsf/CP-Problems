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

void solve() {
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    char a0 = s[0], a1 = s[0];
    for (int i = 0; i < n; i++) {
        if (s[i] != a0) {
            a1 = s[i];
            break;
        }
    }

    int b0 = a0-'0';
    int b1 = a1-'0';

    if (k == 1) {
        if (b0 < b1) b0++;
        for (int i = 0; i < n; i++) cout << b0;
    } else {
        int num = 0;
        int di = 1;
        for (int i = n-1; i >= 0; i--) {
            int d = s[i]-'0';
            num += d*di;
            di *= 10;
        }

        int mini, maxi;
        int minj, maxj;
        int ans = 1e10;

        if (b0 == 9) mini = maxi = 9;
        else {
            mini = b0;
            maxi = b0+1;
        }
        if (b1 < 9) {
            minj = b1;
            maxj = b1+1;
        }
        di/=10;
        for (int i = mini; i <= maxi; i++) {
            for (int j = minj; j <= maxj; j++) {
                for (int m = 0; m < (1<<n); m++) {
                    int dez = di;
                    int sum = 0;
                    for (int h = 0; h < n; h++) {
                        if ((1<<h) & m) sum += i*dez;
                        else sum += j*dez;
                        if (sum < num/dez) break;
                        dez /= 10;
                    }
                    if (sum >= num && sum < ans) ans = sum;
                }
            }
        }
        for (int i = mini; i <= maxi; i++) {
            for (int j = 0; j <= 0; j++) {
                for (int m = 0; m < (1<<n); m++) {
                    int dez = di;
                    int sum = 0;
                    for (int h = 0; h < n; h++) {
                        if ((1<<h) & m) sum += i*dez;
                        else sum += j*dez;
                        if (sum < num/dez) break;
                        dez /= 10;
                    }
                    if (sum >= num && sum < ans) ans = sum;
                }
            }
        }
        

        cout << ans;
    }
    cout << endl;
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