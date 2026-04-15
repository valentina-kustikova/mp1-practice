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

//õ1 y1; x2 y2; x3 y3

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

int main() {
	char* filename = "triangle.txt";

}