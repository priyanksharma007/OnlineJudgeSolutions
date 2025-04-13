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

class DSU {
public:
	vector<int> root;
	vector<int> size;
	int cc;


	DSU(int n) {
		root = vector<int>(n);
		size = vector<int>(n, 1);
		iota(all(root), 0);
		cc = n;
	}

	int get(int x) { return root[x] == x ? x : x = get(root[x]);};

	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) { return;}

		if (size[x] > size[y]) swap(x, y);
		size[y] += size[x];
		root[x] = y;
		cc--;
	}

	bool sameSet(int x, int y) {
		return get(x) == get(y);
	}
};

string getResult(vector<string> &deck) {
	vector<string> hand(deck.end() - 25, deck.end());
	vector<string> pile(deck.begin(), deck.end()-25);

	int y = 0;

	rep(i, 3) {
		string topCard = pile.back();
		int x = isdigit(topCard[0]) ? topCard[0] - '0' : 10;
		y += x;
		pile.pop_back();
		for (int j = 0; j < max(0, 10-x) and !pile.empty(); j++) {
			pile.pop_back();
		}
	}

	pile.insert(pile.end(), all(hand));
	return pile[y-1];
}


void solve() {
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		vector<string> deck(52);
		rep(j, 52) {
			cin >> deck[j];
		}

		string res = getResult(deck);
		cout << "Case " << i+1 << ": " << res << endl;
	}

	
}

int main() {
	setIO(); 
	// setIO("circlecross"); 
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}		