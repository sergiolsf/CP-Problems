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

    vi a(n);

    map<int,int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

       if (mp.count(a[i]-1)) {
            int q = mp[a[i]-1]+1;
            if (mp.count(a[i])) {
                mp[a[i]] = max(mp[a[i]], q);
            } else {
                mp[a[i]] = q;
            }
       } else {
            mp[a[i]] = 1;
       }

    }

    int val, q = 0;

    for (auto e: mp) {
        if (e.second > q) {
            q = e.second;
            val = e.first;
        }
    }

    int pri = val-q+1;

    int j = 0;

    cout << q << endl;

    for (int i = pri; i <= val; ) {
        if (a[j] == i) {
            cout << j+1 << " ";
            i++;
        }
        j++;
    }


    
    return 0;
}