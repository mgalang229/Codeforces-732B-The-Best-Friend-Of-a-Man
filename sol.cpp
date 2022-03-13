#include <bits/stdc++.h>
using namespace std;

void test_case() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// this solution is a greedy approach because it is always optimal
	// to divide the walks into 2 days (whether equal or unequal) so
	// that the next day can benefit from the previous day
	vector<int> dp(n);
	dp[0] = 0;
	int total = 0;
	for(int i = 1; i < n; i++) {
		// if the value of k (walks needed) is greater than the combined value
		// of the planned walks for the current and previous day, then we should
		// the remaining walks needed for the current day so that the next day
		// will benefit from the number of walks that were placed in the current day
		if(k > a[i] + a[i-1]) {
			dp[i] = k - (a[i] + a[i-1]);
			total += dp[i];
			a[i] += dp[i];
		} else {
			dp[i] = 0;
		}
	}
	cout << total << "\n";	
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	//cin >> tc;
	for(int t = 0; t < tc; t++) {
		test_case();
	}
	return 0;
}

