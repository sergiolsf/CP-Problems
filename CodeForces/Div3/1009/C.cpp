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

const int MAXB = 33;

int x; 

bool existe(int &y) {
    for (int i = 1; i <= MAXB; i++) {
        int Y = 1LL<<(i-1);
        if (!(x&Y)) {
            if(Y+y < x) {
                y += Y;
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> x;
    
    for (int i = 1; i <= MAXB; i++) {
        int Y = 1LL<<(i-1);
        if (x&Y) {
            if(existe(Y)) {
                cout << Y << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
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