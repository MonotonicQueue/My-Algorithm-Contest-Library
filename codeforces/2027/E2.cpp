#include <bits/stdc++.h>

using namespace std;

int dp[32][32][6][2][2];

const int mod = 1000000007;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> A(n);
		for (int i = 0; i < n; i++)
			cin >> A[i];
		vector<int> B(n);
		for (int i = 0; i < n; i++)
			cin >> B[i];
		vector<int> curr(32);
		curr[0] = 1; // identity
		for (int i = 0; i < n; i++)
		{
			memset(dp, 0, sizeof dp);
			dp[0][0][0][0][0] = 1;
			for (int j = 0; j <= 29; j++)
			{
				int p = 29 - j; // place we are going to add a bit in
				for (int k = 0; k <= 29; k++)
				{ // position of most significant one in a'
					for (int type = 0; type < 6; type++)
					{ // 0, 1, 11111, 11110, 10000, else
						for (int good = 0; good < 2; good++)
						{ // good=1 iff good bit has occured
							for (int low = 0; low < 2; low++)
							{ // low=1 iff prefix below b
								for (int bit = 0; bit < 2; bit++)
								{ // bit in x
									if (dp[j][k][type][good][low] == 0)
										continue; // no point in transition since count is 0
									if (!low && (B[i] & (1 << p)) == 0 && bit == 1)
										continue; // x can't go higher than B[i]
									if (bit == 0)
									{
										int good2 = good || (A[i] & (1 << p)) != 0; // check good bit
										int low2 = low || (B[i] & (1 << p)) != 0;	// check if low
										// nothing added to a' so nothing else changes
										(dp[j + 1][k][type][good2][low2] += dp[j][k][type][good][low]) %= mod;
									}
									else
									{
										int bita = good || (A[i] & (1 << p)) != 0; // bit in a'
										int k2 = type == 0 ? 0 : k + 1;			   // increase if MSOne exists
										int type2 = bita ? (
															   type == 0 ? 1 : // add first one
																   (type == 1 || type == 2) ? 2
																							: // 11111
																   5						  // can't add 1 after a 0
															   )
														 : (
															   (type == 0) ? 0 : // 0
																   (type == 1 || type == 4) ? 4
																							: // 10000
																   (type == 2) ? 3
																			   : // 11110
																   5			 // can't have a zero in any other case
														   );
										(dp[j + 1][k2][type2][good][low] += dp[j][k][type][good][low]) %= mod;
									}
								}
							}
						}
					}
				}
			}
			vector<int> count(32); // number of x-values for each nimber
			for (int k = 0; k <= 29; k++)
			{ // position of MSOne
				for (int good = 0; good < 2; good++)
				{ // doesn't matter
					for (int low = 0; low < 2; low++)
					{																	 // doesn't matter
						(count[0] += dp[30][k][0][good][low]) %= mod;					 // 0
						(count[1] += dp[30][k][1][good][low]) %= mod;					 // 1
						(count[k + 1] += dp[30][k][2][good][low]) %= mod;				 // 11111
						(count[0] += dp[30][k][3][good][low]) %= mod;					 // 11110
						(count[k + (k % 2 ? -1 : 1)] += dp[30][k][4][good][low]) %= mod; // 10000
						(count[k + 1] += dp[30][k][5][good][low]) %= mod;				 // else
					}
				}
			}
			count[0] -= 1;		  // remove when x=0
			vector<int> next(32); // knapsack after adding this pile
			for (int j = 0; j < 32; j++)
				for (int k = 0; k < 32; k++)
					(next[j ^ k] += 1LL * curr[j] * count[k] % mod) %= mod;
			swap(curr, next);
		}
		cout << curr[0] << "\n";
	}
	return 0;
}