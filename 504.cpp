#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i = j; i <= k; ++i)
#define rrep(i,j,k) for (int i = j; i >= k; --i)

using namespace std;

const int MAX = 711;
int n, m, tmp, t;
string line[MAX], row[MAX], col[MAX];
int row_z[MAX][MAX * 2], col_z[MAX][MAX * 2];
int row_palinlen[MAX][MAX][2], col_palinlen[MAX][MAX][2];
int maxlen, sx, sy, ex, ey;

void match(int start, int &z, string &s,int len)
{
    while (start - z >= 0 && start + z < len && s[start - z] == s[start + z]) 
	z++;
}
void calc_z(string s, int *z)
{
    static int mid,right,len,reflect_i,suply_pos;
    
    z[0] = 1;
    len = s.size();
    mid = right = 0;
    
    rep(i,1,len-1)
	{
	    reflect_i = 2 * mid - i;
	    suply_pos = i + z[reflect_i] - 1;
	    if (i > right)
		{
		    match(i,z[i] = 0,s,len);
		    mid = i,right = i + z[i] - 1;
		}
	    else if (suply_pos == right)
		{
		    match(i,z[i] = z[reflect_i],s,len);
		    mid = i,right = i + z[i] - 1;
		}
	    else
		z[i] = min(z[reflect_i],right - i + 1);
	}
}

int main()
{
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    rep(i,0,n-1) 
	{
	    row[i] = "#";
	    cin >> line[i];
	    rep(j,0,m-1)
		{
		    row[i] += line[i][j];
		    row[i] += '#';
		}
	    calc_z(row[i],row_z[i]);
	    for (int j = 0, cnt = 1; j < m; ++j, cnt += 2)
		{
		    row_palinlen[i][j][1] = row_z[i][cnt] - 1;
		    row_palinlen[i][j][0] = row_z[i][cnt + 1] - 1;
		}
	}

    rep(i,0,m-1)
	{
	    col[i] = "#";
	    rep(j,0,n-1)
		{
		    col[i] += line[j][i];
		    col[i] += "#";
		}
	    calc_z(col[i],col_z[i]);
	    for (int j = 0, cnt = 1; j < n; ++j, cnt += 2)
		{
		    col_palinlen[j][i][1] = col_z[i][cnt] - 1;
		    col_palinlen[j][i][0] = col_z[i][cnt + 1] - 1;
		}
	}

    tmp = min(n,m);
    maxlen = 1;
    sx = sy = ex = ey = 0;

    for (int i = 0; i < n; ++i) 
	for (int j = 0; j < m; ++j)
	    {
		int k,c;
		t = tmp;
		for (k = 1, c = 0; k <= t; k += 2, c++)
		    {
			if (i - c < 0 || i + c >= n || j - c < 0 || j + c >= m) break;
			t = min(t, row_palinlen[i - c][j][1]);
			t = min(t, row_palinlen[i + c][j][1]);
			t = min(t, col_palinlen[i][j - c][1]);
			t = min(t, col_palinlen[i][j + c][1]);
			if (k > t) break;
			if (t <= maxlen) break;
		    }
		if (k - 2 > maxlen)
		    {
			c--;
			maxlen = k - 2;
			sx = i - c; ex = i + c;
			sy = j - c; ey = j + c;
		    }

		t = tmp;
		for (k = 2, c = 0; k <= t; k += 2, c++)
		    {
			if (i - c < 0 || i + c + 1 >= n || j - c < 0 || j + c + 1 >= m) break;
			t = min(t, row_palinlen[i - c][j][0]);
			t = min(t, row_palinlen[i + c + 1][j][0]);
			t = min(t, col_palinlen[i][j - c][0]);
			t = min(t, col_palinlen[i][j + c + 1][0]);
			if (k > t) break;
			if (t <= maxlen) break;
		    }
		if (k - 2 > maxlen)
		    {
			c--;
			maxlen = k - 2;
			sx = i - c; ex = i + c + 1;
			sy = j - c; ey = j + c + 1;
		    }
	    }
    cout << sx + 1 << " " << sy + 1 << " " 
	 << ex + 1 << " " << ey + 1 << endl;
    
    return 0;
}
