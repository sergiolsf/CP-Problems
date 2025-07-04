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

signed main() {
    fastio();
    int lo = 0, hi = 1'000'000'000;
    while (hi-lo > 1) {
        int y = (lo+hi)/2;
        cout << "? " << y << endl;
        cout.flush();
        string ans; cin >> ans;
        if (ans == "YES") lo = y;
        else hi = y;
    }
    cout << "! " << hi << endl;
    cout.flush();  
    return 0;
}