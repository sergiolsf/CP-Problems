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
    string s; cin >> s;
    
    if (s == "red") cout << "SSS\n";
    else if (s == "blue") cout << "FFF\n";
    else if (s == "green") cout << "MMM\n";
    else cout << "Unknown\n";

  
    return 0;
}