#include<locale.h>
#include<time.h>
#include"dirent.h"

DIR* d;
struct dirent* ent;

typedef struct file_data {
    char* name;
    long int size;
}file_data;


int stat(const char* path, struct stat* buf);

char* file_path(const char* str1, const char* str2) {

    size_t str1_len = strlen(str1), str2_len = strlen(str2),new_str_len = str1_len + 1 + str2_len + 1;
    char* new_str = malloc(new_str_len * sizeof(char));
    if (new_str == NULL) {
        printf("Memory error\n");
        return NULL;
    }

    strcpy(new_str, str1);
    strcat(new_str, "/");
    strcat(new_str, str2);

    return new_str;
}

char* convert(const char* str1) {
    size_t str1_len = strlen(str1), new_str_len = str1_len + 1;
    char* new_str = (char *)malloc(new_str_len * sizeof(char));
    strcpy(new_str, str1);

    return new_str;
}

int file_num(char path[100]) {
    int n = 0;
    d = opendir(path);
    if (d) {
        while ((ent = readdir(d)) != NULL) {
            if (ent->d_type != DT_REG) {
                continue;
            }
            n++;
        }
        closedir(d);
    }
    return n;
}

int cmp_size(const void* a, const void* b){
    file_data* c = (file_data*)a;
    file_data* d = (file_data*)b;
    return (c->size - d->size);
}

void select_sort(file_data *files, int N) {
    int min;
    file_data tmp_s;
    for (int i = 0; i < N; i++)
    {
        min = i;
        for (int j = i + 1; j < N; j++)
            if (files[min].size > files[j].size)
                min = j;

        tmp_s = files[min];
        files[min] = files[i];
        files[i] = tmp_s;
    }
}

void insert_sort(file_data* files, int N)
{
    int loc;
    file_data new_file;
    for (int i = 1; i < N; i++)
    {
        new_file = files[i];
        loc = i - 1;
        while (loc >= 0 && files[loc].size > new_file.size)
        {
            files[loc + 1] = files[loc];
            loc = loc - 1;
        }
        files[loc + 1] = new_file;
    }
}

void print_files(file_data* files, int N) {
    for (int i = 0; i < N; i++) {
        printf("Имя: %s Размер: %ld байт\n", files[i].name, files[i].size);
    }

}

void qsort_s(file_data* files, int left, int right) {
    int pilot;
    char* pilot_name;

    int l_border = left;
    int r_border = right;
    pilot = files[left].size;
    pilot_name = files[left].name;
    
    while (left < right) {
        while ((files[right].size >= pilot) && (left < right))
            right--;
        if (left != right) {
            files[left].size = files[right].size;
            files[left].name = files[right].name;
            left++;
        }
        while ((files[left].size <= pilot) && (left < right))
            left++;
        if (left != right) {
            files[right].size = files[left].size;
            files[right].name = files[left].name;
            right--;
        }
    }
    files[left].size = pilot;
    files[left].name = pilot_name;
    pilot = left;
    left = l_border;
    right = r_border;
    if (left < pilot)
        qsort_s(&files[0], left, pilot - 1);
    if (right > pilot)
        qsort_s(&files[0], pilot + 1, right);
}


void main() {
    char path[100];
    int i = 0, num, input = 0;
    clock_t t_start;
    clock_t t_finish;
    struct stat fileStat;
    double time_f;
    struct file_data* files_origin;
    struct file_data* files;

    setlocale(LC_ALL, "Rus");
    printf("Путь: ");
    scanf("%s", path);
    num = file_num(path);
    files_origin = (file_data*)malloc(num * sizeof(file_data));

    d = opendir(path);
    if (d) {
        while ((ent = readdir(d)) != NULL) {
            char* filePath;
            if (ent->d_type != DT_REG) {
                continue;
            }
            filePath = file_path(path, ent->d_name);
            stat(filePath, &(fileStat));
            free(filePath);

            file_data new = { convert(ent->d_name) , fileStat.st_size };

            files_origin[i].name = (char *)malloc((strlen(new.name) + 1) * sizeof(char));
            memcpy(files_origin[i].name, new.name, strlen(new.name) + 1);
            files_origin[i].size = new.size;
            i++;
        }
        closedir(d);
    }
    
    files = (file_data*)malloc(num * sizeof(file_data));
    do {
        //memcpy(files, files_origin, num * sizeof(file_data));
        for (i = 0; i < num; i++) {
            files[i].name = (char*)malloc((strlen(files_origin[i].name) + 1) * sizeof(char));
            memcpy(files[i].name, files_origin[i].name, strlen(files_origin[i].name) + 1);
            files[i].size = files_origin[i].size;
        }
        printf("Выберите команду: 0 - вывести оригинал\n");
        printf("Сортировки: 1 - выбором, 2 - вставками, 3 - быстрая \n");
        printf("4 - завершить программу\n");

        scanf("%d", &(input));

        switch (input) {
        case 0:
            print_files(&files_origin[0], num);
            break;
        case 1:
            t_start = clock();
            select_sort(&files[0], num);           
            t_finish = clock();
            print_files(&files[0], num);
            time_f = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
            
            printf("Время сортировки: %.5lf\n", time_f);
            break;
        case 2:
            t_start = clock();
            insert_sort(&files[0], num);
            t_finish = clock();
            print_files(&files[0], num);
            time_f = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
            printf("Время сортировки: %.5lf\n", time_f);
            break;
        case 3:
            t_start = clock();
            //qsort(files, num, sizeof(struct file_data), cmp_size);
            qsort_s(&files[0], 0, num - 1);
            t_finish = clock();
            print_files(&files[0], num);
            time_f = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
            printf("Время сортировки: %.5lf\n", time_f);
            break;
        case 4:
            break;
        default:
            printf("Input error\n");
        }
        for (i = 0; i < num; i++)
        {
            free(files[i].name);
        }       

    } while (input != 4);
    
    free(files);
    for (i = 0; i < num; i++)
    {
        free(files_origin[i].name);
    }
    free(files_origin);
}


