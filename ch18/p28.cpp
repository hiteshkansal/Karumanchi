#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
typedef struct point
{
    int x, y;
}point;

int compareX(const void* a, const void* b)
{
    point *p1 = (point *)a,  *p2 = (point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    point *p1 = (point *)a,   *p2 = (point *)b;
    return (p1->y - p2->y);
}

float dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(point p[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(p[i], p[j]) < min)
                min = dist(p[i], p[j]);
    return min;
}

float stripClosest(point strip[], int size, float d)
{
    qsort(strip, size, sizeof(point), compareY);
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < d; ++j)
            if (dist(strip[i],strip[j]) < d)
                d = dist(strip[i], strip[j]);
    return d;
}

float closestUtil(point p[], int n)
{
    if (n <= 3)
        return bruteForce(p, n);

    int mid = n/2;
    point midpoint = p[mid];
    float dl = closestUtil(p, mid);
    float dr = closestUtil(p + mid, n-mid);
    float d = min(dl, dr);
    point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(p[i].x - midpoint.x) < d)
            strip[j] = p[i], j++;
    return min(d, stripClosest(strip, j, d) );
}

float closest(point p[], int n)
{
    qsort(p, n, sizeof(point), compareX);
    return closestUtil(p, n);
}

int main()
{
    point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(p) / sizeof(p[0]);
    cout<<"Minimun distance is: "<<closest(p,n);
    return 0;
}
