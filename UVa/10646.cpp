#include<bits/stdc++.h>
// #include "bits/stdc++.h"
using namespace std;
#define ull       unsigned long long
#define SPEEDHACK ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff        first
#define ss        second
#define sz(v)     (ll)(v).size()
#define file      freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define mod             1000000007
// #define mod             998244353 
#define inv 499122177
#define pb push_back
#define all(a) a.begin(), a.end()
const double eps = 1e-2;
#define ll       long long
#define rep(i, c) for(int i = 0; i < (int)c; i++)
#define ri(i) for (auto &i : a) cin >> i
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template<class T> using P = pair<T, T>;
using vi = vector<int>;
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair
// int dx[] = { 1,0,-1,0,1,1,-1,-1 };
// int dy[] = { 0,1,0,-1,1,-1,1,-1 };
// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[] = {0,1,0,-1,0};

string stepDir = "URDL";


void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int getValue(string card) {
    char value = card[0];
    if (value >= '2' and value <= '9') return value - '0';
    else return 10;
}

string solve() {
    vector<string> pile;
    vector<string> hand;
    for (int i = 0; i < 52; i++) {
        string card;
        cin >> card;
        if (i <= 26) pile.push_back(card);
        else hand.push_back(card);
    }


    int y = 0;


    for (int i = 0; i < 3; i++) {
        string card = pile.back();
        int x = getValue(card);
        y += x;
        pile.pop_back();
        for (int j = 0; j < 10 - x; j++) {
            if (!pile.empty()) pile.pop_back();
        }
    }

    pile.insert(pile.end(), all(hand));

    return  pile[y - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    int c = 1;

    while (t--) {
        string ans = solve();
        cout << "Case " << c++ << ": " << ans << endl;

    }
}













