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

void ans(int A, int B) {
    if (A > B) cout << "BOB\n";
    else if (A < B) cout << "ALICE\n";
    else cout <<"DRAW\n";
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    int quant0 = 0;
    for (int i = 0; i < n; i++) if (s[i] == '0') quant0++;
    int x = 0;
    int r = 0, l = n-1;
    while (r < l) {
        if (s[r] != s[l]) x++;
        r++;
        l--;
    }
    int A = 0, B = 0;
    if (x == 0) {
        if (n%2 == 0 || s[n/2] == '1') {
            int k = quant0/4;
            A += 2*k;
            B += 2*k;
            A += min(quant0%4, 2LL);
            B += max(quant0%4-2, 0LL);
        } else {
            A++;
            int k = (quant0-1)/4;
            A += 2*k;
            B += 2*k;
            B += min((quant0-1)%4, 2LL);
            A += max((quant0-1)%4-2, 0LL);
        }
    } else {
        if (n%2 == 0 || s[n/2] == '1') {
            B += x;
            int k = (quant0-x)/4;
            A += 2*k;
            B += 2*k;
            A += min((quant0-x)%4, 2LL);
            B += max((quant0-x)%4-2, 0LL);
        } else {
            int A1 = 0, B1 = 0;
            int A2 = 0, B2 = 0;
            ///
            B1 += x;
            if (quant0-x > 0) A1++;
            int k = (quant0-x-1)/4;
            A1 += 2*k;
            B1 += 2*k;
            B1 += min((quant0-x-1)%4, 2LL);
            A1 += max((quant0-x-1)%4-2, 0LL);
            ///
            B2 += x+1;
            k = (quant0-x-1)/4;
            A2 += 2*k;
            B2 += 2*k;
            A2 += min((quant0-x-1)%4, 2LL);
            B2 += max((quant0-x-1)%4-2, 0LL);
            ///
            if (A1 < A2) {
                B = B1;
                A = A1;
            } else {
                B = B2;
                A = A2;
            }
        }
    }

    ans(A, B);
    return;
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