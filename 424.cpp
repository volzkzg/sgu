#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX = 111;
struct node{
        int u,v;
}edge[MAX*MAX];
int n,now,edge_num;

void insert(int u,int v)
{
        edge_num++;
        edge[edge_num].u = u,edge[edge_num].v = v;
}

int main()
{
        ios::sync_with_stdio(false);
        
        cin >> n;
        if (n == 1) {
                cout << 1 << " " << 0 << endl;
        } else if (n == 2) {
                cout << 2 << " " << 1 << endl;
                cout << 1 << " " << 2 << endl;
        } else if (n == 3) {
                cout << 3 << " " << 3 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 2 << " " << 3 << endl;
                cout << 1 << " " << 3 << endl;
        } else {
                insert(1,3);
                insert(2,3);
                for (int i = 4; i <= n; ++i) {
                        insert(1,i);
                        insert(i,2);
                }
                cout << n << " " << edge_num << endl;
                
                for (int i = 1; i <= edge_num; ++i)
                        cout << edge[i].u << " " << edge[i].v << endl;
                
        }
        return 0;
}