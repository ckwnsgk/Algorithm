#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX_DOTS 30

typedef struct {
    double x, y;
} Point;

double distance(Point a, Point b) 
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double prim(Point points[], int n) {
    double minDist[MAX_DOTS];
    int selected[MAX_DOTS] = { 0 };  
    double total = 0.0;

    for (int i = 0; i < n; i++) {
        minDist[i] = DBL_MAX;
    }

    minDist[0] = 0.0; 

    for (int i = 0; i < n; i++) {
        double min = DBL_MAX;
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!selected[j] && minDist[j] < min) {
                min = minDist[j];
                u = j;
            }
        }

        selected[u] = 1;
        total += min;

        for (int v = 0; v < n; v++) {
            if (!selected[v]) {
                double dist = distance(points[u], points[v]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    return total;
}

int main() 
{
    int n;
    Point points[MAX_DOTS];

    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf_s("%lf %lf", &points[i].x, &points[i].y);
    }

    double result = prim(points, n);
    printf("%.2f\n", result);

    return 0;
}
