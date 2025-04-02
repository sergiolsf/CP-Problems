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

const int MAX_B = 32;
const int MAX_N = 100'010;

vvi Pesq(MAX_N, vi (MAX_B));
vvi Pdir(MAX_N, vi (MAX_B));
int dir[MAX_B];
int esq[MAX_B];
int c[MAX_B];

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;

    for (int i = 0; i < MAX_B; i++) {
        dir[i] = esq[i] = c[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_B; j++) {
            if (a[i]&(1LL<<j)) dir[j]++;

            if (i == 0) {
                Pdir[i][j] = 0;
            } else {
                Pdir[i][j] = Pdir[i-1][j];
            }

            if (dir[j]&1) Pdir[i][j]++;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < MAX_B; j++) {
            if (a[i]&(1LL<<j)) esq[j]++;

            if (i == n-1) {
                Pesq[i][j] = 0;
            } else {
                Pesq[i][j] = Pesq[i+1][j];
            }
            
            if (esq[j]&1) Pesq[i][j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int bms;

        for (int j = 0; j < MAX_B; j++) {
            if (a[i] & (1LL<<j)) {
                bms = j;
                c[j] = (c[j]+1)%2;
                esq[j] = (esq[j]+1)%2;
            }
        }

        int Id, Pd, Pe, Ie;

        if (c[bms]) {
            Pd = 1 + Pdir[n-1][bms]-Pdir[i][bms]; 
            Id = (n-1)-i-(Pd-1);
        } else { 
            Id = Pdir[n-1][bms]-Pdir[i][bms]; 
            Pd = (n-1)-i-Id+1;
        }

        if(!esq[bms]) {
            Pe = 1 + Pesq[0][bms]-Pesq[i][bms];
            Ie = i-(Pe-1);
        } else {
            Ie = Pesq[0][bms]-Pesq[i][bms];
            Pe = i-Ie+1;
        }

        ans += Pe*Id+Pd*Ie;
    }
    cout << ans << endl;
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