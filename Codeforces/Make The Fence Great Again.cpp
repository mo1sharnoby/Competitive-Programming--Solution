#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define mod 10000000007
/**

      ___           ___                       ___           ___
     /\  \         /\  \                     /\  \         /\  \
    /::\  \       /::\  \         ___       /::\  \        \:\  \
   /:/\:\  \     /:/\:\__\       /|  |     /:/\:\  \        \:\  \
  /:/ /::\  \   /:/ /:/  /      |:|  |    /:/ /::\  \   _____\:\  \
 /:/_/:/\:\__\ /:/_/:/__/___    |:|  |   /:/_/:/\:\__\ /::::::::\__\
 \:\/:/  \/__/ \:\/:::::/  /  __|:|__|   \:\/:/  \/__/ \:\~~\~~\/__/
  \::/__/       \::/~~/~~~~  /::::\  \    \::/__/       \:\  \
   \:\  \        \:\~~\      ~~~~\:\  \    \:\  \        \:\  \
    \:\__\        \:\__\          \:\__\    \:\__\        \:\__\
     \/__/         \/__/           \/__/     \/__/         \/__/

**/
////////////////////////////////////////////////////
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll q;
	cin >> q;
	while (q--)
	{
		ll n, i;
		ll arr[300005];
		ll arr1[300005];
		ll dp[300005][3];
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
			cin >> arr1[i];
			dp[i][0] = 1000000000000000000;
			dp[i][1] = 1000000000000000000;
			dp[i][2] = 1000000000000000000;
		}
		ll j, k;
		dp[0][0] = 0;
		dp[0][1] = arr1[0];
		dp[0][2] = arr1[0] * 2;
		for (i = 1; i < n; i++)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{

					if ((arr[i] + k) != (arr[i - 1] + j))
						dp[i][k] = min(dp[i][k], dp[i - 1][j]+arr1[i]*k);
				}

			}
		}
		cout << min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<"\n";

	}
}