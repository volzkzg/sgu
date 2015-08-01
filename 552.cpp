#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

map<vector<string> , int> cnt;
int bitCount[1 << 5];

int main()
{
	for(int i = 0; i < (1 << 4); ++i)
	{
		bitCount[i] = __builtin_popcount(i);
	}
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n)
	{
		vector<string> p[5];
		for(int j = 1; j < 5; ++j)
			p[j].resize(j);
		p[0].resize(4);
		for(int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			for(int j = 0; j < k; ++j)
				cin >> p[0][j];
			sort(p[0].begin(), p[0].begin() + k);
			for(int j = 1; j < (1 << k); ++j)
			{
				int c = bitCount[j], tot = 0;
				for(int t = 0; t < k; ++t)
					if((j >> t) & 1)
						p[c][tot++] = p[0][t];
			//	sort(p[c].begin(), p[c].end());
				cnt[p[c]]++;
			}
		}
		int q;
		cin >> q;
		for(int i = 0; i < q; ++i)
		{
			int k;
			cin >> k;
			for(int j = 0; j < k; ++j)
				cin >> p[k][j];
			sort(p[k].begin(), p[k].end());
			cout << cnt[p[k]] << endl;
		}
	}
	return 0;
}
