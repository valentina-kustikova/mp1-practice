#include <stdio.h>

#define MAX_LINE_LEN 100

typedef struct{

	double x;
	double y;

}Point;

typedef struct {
	Point A;
	Point B;
	Point C;

}Triangle;

//х1 y1; x2 y2; x3 y3

Triangle* file_open(const char* filename, int* n) {

    Triangle* triangles;
    char line[MAX_LINE_LEN];
    int i = 0;
    int triangle_count;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return NULL;
    }

    fscanf(file, "%d\n", &triangle_count);

    triangles = (Triangle*)malloc(sizeof(Triangle) * triangle_count);

    while (i < triangle_count && fgets(line, MAX_LINE_LEN, file) != NULL) {
        sscanf(line,
            "%lf %lf; %lf %lf; %lf %lf",
            &triangles[i].A.x,
            &triangles[i].A.y,
            &triangles[i].B.x,
            &triangles[i].B.y,
            &triangles[i].C.x,
            &triangles[i].C.y);
        i++;
    }

    fclose(file);

    *n = i;
    return triangles;
}

void show_dots(Triangle* triangles, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%lf %lf; %lf %lf; %lf %lf",
            &triangles[i].A.x,
            &triangles[i].A.y,
            &triangles[i].B.x,
            &triangles[i].B.y,
            &triangles[i].C.x,
            &triangles[i].C.y);
    }
    printf("\n");
}

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double perimetr(Triangle t) { 

    a = dist(t.A, t.B);
    b = dist(t.B, t.C);
    c = dist(t.A, t.C);

    return a + b + c;
}

double area(Triangle T) { //формула Герона

    a = dist(t.A, t.B);
    b = dist(t.B, t.C);
    c = dist(t.A, t.C);

    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

//h=2S/a a-сторона к которой проведена высота 
void hights(Triangle t, double* ha, double* hb, double* hc) {

    a = dist(t.A, t.B);
    b = dist(t.B, t.C);
    c = dist(t.A, t.C);

    double S = area(t);
    *ha = 2 * S / a;
    *hb = 2 * S / b;
    *hc = 2 * S / c;
}

void triangle_type(Triangle t) {

    a = dist(t.A, t.B);
    b = dist(t.B, t.C);
    c = dist(t.A, t.C);

}


int main() {
	char* filename = "triangle.txt";

}