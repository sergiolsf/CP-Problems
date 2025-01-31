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

int ans = -1;

vi prefix_function(string s) {
    int n = (int)s.length();
    vi pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// Function to count the number of occurrences of each
// prefix of string s in the same string s that also occurs
// as the suffix of s
void prefix_occurrence_with_suffix(string s)
{
    int n = s.size();

    vector<int> pi = prefix_function(s), count(n + 1, 0);

    // Count the occurrences of each value in the Prefix
    // Function
    for (int i = 0; i < n; i++)
        count[pi[i]]++;

    for (int i = n - 1; i > 0; i--)
        count[pi[i - 1]] += count[i];

    for (int i = 1; i <= n; i++) {
        count[i]++;
    }

    int j = pi[n - 1];

    while (j > 0) {
        if (count[j] > 2) {
            ans = j;
            return;
        }
        j = pi[j - 1];
    }
}

signed main() {
    fastio();
    string s;
    cin >> s;

    prefix_occurrence_with_suffix(s);

    if (ans == -1) {
        cout << "Just a legend";
    } else {
        for (int i = 0; i < ans; i++) {
            cout << s[i];
        }
    }

    cout << endl;
    
    return 0;
}