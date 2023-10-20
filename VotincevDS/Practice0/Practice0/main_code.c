#include <stdio.h>
#include <math.h>
/*
Test cases

Test1
input:
0 0 10
999 999 1
output: No common points

Test2
input:
0 0 10
11 0 1
output: touches outside

Test3
input:
0 0 10
12 0 3
output: Touches at 2 points

Test4
input:
0 0 5
1 1 10
output: one inside other one

Test5
input:
0 0 5
3 0 2
output:


*/
int main() {
    double x1, y1, r1;
    double x2, y2, r2;
    double distance;
    printf("Type coordinates and radius of first circle\n");
    printf("in this order: x1 y1 r1\n");
    printf("(radius must be more than 0)\n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);

    printf("Now do the same with parameters with second circle\n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    
    
    distance = sqrt((x2 - x1)* (x2 - x1) + (y2 - y1) * (y2 - y1));
    // distance between centers

    double catch_error = 0.01;
    // error rate
    
    if ((distance - (r1 + r2)) >= catch_error) {
        printf("The have no common points");
        return 0;
    }
    else if (abs(distance - (r1 + r2)) < catch_error) {
        printf("They touches outside");
        return 0;
    }
    double mr; // min radius
    double mx; // max radius
    if (r1 >= r2) {
        mr = r2;
        mx = r1;
    }
    else {
        mr = r1;
        mx = r2;
    }
    double tp_dist = distance + mr - mx; // touch point distance
    if (abs(tp_dist) <= catch_error) {
        printf("Circles touches inside");
        return 0;
    }
    else if (tp_dist < -catch_error) {
        printf("One inside other one");
        return 0;
    }
    printf("They touches in 2 points");
    return 0;
    
}
