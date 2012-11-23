#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define dis(a, b) sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
typedef struct { double x, y; } point;
const double pi = 3.1415926535897932384626;
 
double r, phi, delta;
point v[151], mid, o;
int N, a, b;
 
int main()
{
    scanf("%d %d %d", &N, &a, &b);
    scanf("%lf %lf %lf %lf", &v[a].x, &v[a].y, &v[b].x, &v[b].y);
    if (a > b) swap(a, b);
    //三角函数求半径
    r = dis(v[a], v[b]) / sin(pi * (b - a) / N) / 2;
    //求两点连线的中点
    mid.x = (v[a].x + v[b].x) / 2;
    mid.y = (v[a].y + v[b].y) / 2;
    //求出多边形重心坐标
    o.x = mid.x + (v[b].y - v[a].y) / tan(pi * (b - a) / N) / 2;
    o.y = mid.y - (v[b].x - v[a].x) / tan(pi * (b - a) / N) / 2;
    //求出旋转的角度phi
    phi = asin((v[a].y - o.y) / r);
    //如果这个角的角度大于平角
    //那么显然我们要把它化为<pi/2的
    if (acos((v[a].x - o.x) / r) > pi / 2)
       if (phi >= -1e10) phi = pi - phi;
          else           phi = -pi - phi;
    //进行变换
    for (int i = 1; i <= N; ++i)
        if (i != a && i != b)
        {
           delta = phi + 2 * pi * (a - i) / N;
           v[i].x = o.x + r * cos(delta);
           v[i].y = o.y + r * sin(delta);
        }
    //输出
    for (int i = 1; i <= N; ++i)
        printf("%.6lf %.6lf\n", v[i].x, v[i].y);
    return 0;
}
