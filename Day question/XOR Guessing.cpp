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

    //cout << (1 << 7) << endl;    
    //cout << (1 << 1) << endl;    
    //cout << (1 << 13) << endl;    


    cout << "?";
    for (int i = 1; i <= 100; i++) {
        cout << " " << i;
    }
    cout << endl; cout.flush();

    int ansq1; cin >> ansq1;

    cout << "?";
    for (int i = 1; i <= 100; i++) {
        int p = (i << 7);
        cout << " " << p;
    }
    cout << endl; cout.flush();

    int ansq2; cin >> ansq2;

    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans += (ansq2&(1<<i));
    }
    for (int i = 7; i < 14; i++) {
        ans += (ansq1&(1<<i));
    }

    cout <<"! " << ans << endl;
    cout.flush();

    return 0;
}