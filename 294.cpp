#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const long long MOD = 1000000000;
const int LEN = 9;

class Bignum
{
public:
	long long num[10000];
	int size;

	Bignum(){size = 0;}
	Bignum(long long x)
	{
		size = 0;
		if (!x)
			num[size++] = 0;
		else {
			while (x) {
				num[size++] = x % MOD;
				x /= MOD;
			}
			while (size && !num[size-1]) --size;
		}
	}
	Bignum(string x)
	{
		int i;
		size = 0;
		for (i = x.size() - 1; i - LEN + 1 >= 0; i -= LEN)
			num[size++] = trans_to_int(x,i - LEN + 1,i);
		if (i) num[size++] = trans_to_int(x,0,i);
	}
	Bignum &operator+=(const int &Rhs)
	{
		Bignum rhs(Rhs);
		size = max(rhs.size,size);
		for (int i = 0; i < size; ++i)
			{
				if (rhs.size > i) num[i] += rhs.num[i];
				num[i+1] += num[i] / MOD;
				num[i] %= MOD;
			}
		while (num[size] > 0)
			{
				num[size+1] += num[size] / MOD;
				num[size++] %= MOD;
			}
		return *this;
	}
	Bignum &operator+=(const Bignum &rhs)
	{
		size = max(rhs.size,size);
		for (int i = 0; i < size; ++i)
			{
				if (rhs.size > i) num[i] += rhs.num[i];
				num[i+1] += num[i] / MOD;
				num[i] %= MOD;
			}
		while (num[size] > 0)
			{
				num[size+1] += num[size] / MOD;
				num[size++] %= MOD;
			}
		return *this;
	}
	Bignum &operator-=(const int &Rhs)
	{
		Bignum rhs(Rhs);
		for (int i = 0; i < size; ++i)
			{
				if (rhs.size > i) num[i] -= rhs.num[i];
				int j = i;
				while (num[j] < 0)
					{
						num[j] += MOD;
						--num[j+1];
						j++;
					}
			}
		while (size > 1 && !num[size-1]) size--;
		return *this;
	}
	Bignum &operator-=(const Bignum &rhs)
	{
		for (int i = 0; i < size; ++i)
			{
				if (rhs.size > i) num[i] -= rhs.num[i];
				int j = i;
				while (num[j] < 0)
					{
						num[j] += MOD;
						--num[j+1];
						j++;
					}
			}
		while (size > 1 && !num[size-1]) size--;
		return *this;
	}
	Bignum &operator*=(const int &rhs)
	{
		for (int i = 0; i < size; ++i)
			num[i] *= rhs;
		for (int i = 0; i < size; ++i)
			{
				num[i+1] += num[i] / MOD;
				num[i] %= MOD;
			}
		while (num[size] > 0)
			{
				num[size+1] += num[size] / MOD;
				num[size++] %= MOD;
			}
		return *this;
	}
	Bignum &operator*=(const Bignum &rhs)
	{
		Bignum lhs(*this);
		memset(num,0,sizeof(num));
		size += rhs.size;
	
		for (int i = 0; i < lhs.size; ++i)
			for (int j = 0; j < rhs.size; ++j)
				{
					num[i+j] += lhs.num[i] * rhs.num[j];
					num[i+j+1] += num[i+j] / MOD;
					num[i+j] %= MOD;
				}
		while (size && !num[size-1]) --size;
		return *this;
	}
	Bignum &operator/=(const int &rhs)
	{
		long long have = 0;
		int pos = size;
		int bound = size-1;
		size = 0;
		for ( ; pos > 0; --pos)
			{
				have = have * MOD + num[pos-1];
				if (have >= rhs) break;
			}
		for (pos-- ; pos > 0; --pos)
			{
				num[bound--] = have / rhs;
				have %= rhs;
				have = have * MOD + num[pos-1];
				size ++;
			}
		num[bound--] = have / rhs;
		size ++;
		return (this->indent(bound));
	}
	Bignum &reverse()
	{
		for (int i = 0; i < size / 2; ++ i)
			swap(num[i],num[size - i - 1]);
		return *this;
	}
	Bignum &indent(int oppset)
	{
		for (int i = 0; i < size; ++ i)
			num[i] = num[i+oppset+1];
		return *this;
	}
	friend ostream &operator<<(ostream &out,const Bignum &hs)
	{
		long long cal[LEN+3],tmp,len = 0,st;
		for (int i = hs.size - 1; i >= 0; --i) {
			for (int j = LEN - 1; j >= 0; --j) cal[j] = 0;

			len = 0;
			tmp = hs.num[i];
			while (tmp) {
				cal[len++] = tmp % 10;
				tmp /= 10;
			}
			
			st = (i == hs.size - 1) ? len - 1 : LEN - 1;
			for (int j = st; j >= 0; --j) out << cal[j];
		}
		return out;
	}
	int trans_to_int(string x,int start,int len) 
	{
		//trans string x[start,start+len-1] to int
		long long ret = 0;
		for (int i = start; i < start + len; ++i)
			ret = ret * 10 + x[i] - '0';
		return ret;
	}
};
Bignum operator+(const Bignum &lhs,const int &rhs)
{
	Bignum ret(lhs);
	ret += rhs;
	return ret;
}
Bignum operator+(const Bignum &lhs,const Bignum &rhs)
{
	Bignum ret(lhs);
	ret += rhs;
	return ret;
}
Bignum operator-(const Bignum &lhs,const int &rhs)
{
	Bignum ret(lhs);
	ret -= rhs;
	return ret;
}
Bignum operator-(const Bignum &lhs,const Bignum &rhs)
{
	Bignum ret(lhs);
	ret -= rhs;
	return ret;
}
Bignum operator*(const Bignum &lhs,const int &rhs)
{
	Bignum ret(lhs);
	ret *= rhs;
	return ret;
}
Bignum operator*(const Bignum &lhs,const Bignum &rhs)
{
	Bignum ret(lhs);
	ret *= rhs;
	return ret;
}
Bignum operator/(const Bignum &lhs,const int &rhs)
{
	Bignum ret(lhs);
	ret /= rhs;
	return ret;
}
bool operator==(const Bignum &lhs,const Bignum &rhs)
{
	if (lhs.size == rhs.size)
		{
			int pos;
			for (pos = lhs.size; pos >= 0 && lhs.num[pos] == rhs.num[pos]; --pos);
			return (pos < 0);
		}
	else 
		return false;
}
bool operator<(const Bignum &lhs,const Bignum &rhs)
{
	if (lhs.size == rhs.size)
		{
			int pos;
			for (pos = lhs.size; pos >= 0 && lhs.num[pos] == rhs.num[pos]; --pos);
			return (pos >= 0 && lhs.num[pos] < rhs.num[pos]);
		}
	else
		return (lhs.size < rhs.size);
}
bool operator>(const Bignum &lhs,const Bignum &rhs)
{
	if (lhs.size == rhs.size)
		{
			int pos;
			for (pos = lhs.size; pos >= 0 && lhs.num[pos] == rhs.num[pos]; --pos);
			return (pos >= 0 && lhs.num[pos] > rhs.num[pos]);
		}
	else 
		return (lhs.size > rhs.size);
}
bool operator<=(const Bignum &lhs,const Bignum &rhs)
{
	if (lhs.size == rhs.size)
		{
			int pos;
			for (pos = lhs.size; pos >= 0 && lhs.num[pos] == rhs.num[pos]; --pos);
			return ((pos < 0) || (pos >= 0 && lhs.num[pos] < rhs.num[pos]));
		}
	else
		return (lhs.size < rhs.size);
}
bool operator>=(const Bignum &lhs,const Bignum &rhs)
{
	if (lhs.size == rhs.size)
		{
			int pos;
			for (pos = lhs.size; pos >= 0 && lhs.num[pos] == rhs.num[pos]; --pos);
			return ((pos < 0) || (pos >= 0 && lhs.num[pos] > rhs.num[pos]));
		}
	else 
		return (lhs.size > rhs.size);
}

int gcd(int x,int y) 
{
	if (y == 0) return x;
	else return gcd(y,x % y);
}

Bignum mi(int k)
{
	Bignum ret(1);
	Bignum mult(2);
	while (k) {
		if (k & 1) ret *= mult;
		k >>= 1;
		mult = mult * mult;
	}
	return ret;
}

int exist[222222];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	Bignum ans(0);
	Bignum tmp;
	Bignum two(1);
	for (int i = 0; i < n; ++i) {
		int k;
		if (i == 0) k = n;
		else k = gcd(i,n);
		exist[k] ++;
	}
	int last = 0;
	for (int i = 0; i <= n; ++i) {
		if (exist[i]) {
			Bignum w = mi(i);
			w *= exist[i];
			ans += w;
		}
	}
	ans /= n;
	cout << ans << endl;
	
	return 0;
}
