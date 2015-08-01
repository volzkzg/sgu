#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int Maxn = 210000;

int w[Maxn];
int k, m, n, c[Maxn];

int sumW[Maxn], sumC[Maxn];

int main()
{
	while(scanf("%d%d%d", &n, &m, &k) == 3)
	{
		for(int i = 1; i <= n; ++i)
		{
			int x;
			scanf("%d%d", &w[i], &c[i]);
			sumC[i] = sumC[i - 1] + c[i];
			sumW[i] = sumW[i - 1] + w[i];
		}
		for(int i = 1; i <= n; ++i)
			sumW[i] *= k;
		int wh, wt;
		wh = wt = 0;
		for(int i = 1; i <= n - m; ++i)
			wh += w[i];
		for(int i = n - m + 1; i <= n; ++i)
			wt += w[i];
		int cur = 0;
		int ans = 0, nowC = 0;
		int ansPos = 0, ansPos2 = 0		;
		for(int i = 0; ; ++i)
		{
			if(wh * k < wt)
				break;
			int pos = lower_bound(sumW + 1, sumW + (n - m - i + 1), wh * k - wt + 1) - sumW;
			pos--;
		//	ans = max(ans, nowC + sumC[pos]);
			if(ans < nowC + sumC[pos])
			{
				ans = nowC + sumC[pos];
				ansPos = i, ansPos2 = pos;
			}
			wh -= w[n - m - i];
			wt = wt - w[n - i] + w[n - m - i];
			nowC += c[n - i];
		}
		printf("%d %d\n", ansPos + ansPos2, ans);
		for(int i = 0; i < ansPos; ++i)
			putchar('H');
		for(int i = 0; i < ansPos2; ++i)
			putchar('T');
		puts("");
	}
	return 0;
}
