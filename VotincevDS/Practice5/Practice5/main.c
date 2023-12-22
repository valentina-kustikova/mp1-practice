#include <stdio.h>
#include <windows.h>
#include <fileapi.h>
#include <time.h>
#include <string.h>

typedef struct  {
    char* first;  
    UINT64 second;
} pair;

pair* get_way_files(char* way,int cf);

void ask_sort();

void qsort(pair* files_ns, int n);

int count_files(char way[]);

void pr_files(pair* files_ns, int cf);

void make_way(char* way);

int check_way(char* way);

void merge(pair* a, int left, int mid, int right);

void mergesort(pair* a, int left, int right);

int sort(pair files_ns[], int left, int right, char el, int cf);

void cpy(pair* a, pair* b, int cf);

void select_sort(pair* files_ns, int cf);

void insert_sort(pair* files_ns, int cf);

void swap(pair* files_ns,int i ,int j);

int main() {
    system("chcp 1251");
    pair *files_ns; 
    // массив, содержащий информацию о файлах в каталоге
    // содержит имя и размер каждого файла
    while (1) {
        int i;
        char way[255];
        int cw; // check way
        int cf;
        printf("\t\tВведите полный путь к папке\n");
        printf("\t (для завершения работы введите 0 )\n");
        scanf("%s", &way);
        if (way[0] == '0') {
            break;
        }
        make_way(&way);

        cw = check_way(&way);
        if (cw == 0) {
            printf("Неверный путь\n");
            continue;
        }
        cf =  count_files(way);
        // получение файлов по пути
        files_ns = get_way_files(&way,cf);
        
        while (1) {
            
            int check;
            char el;           
            char ans[10];
            pair* f; // копия files_ns
                        
            ask_sort();

            scanf("%s", &ans);
            printf("\n\n");
            
            el =  ans[0];
            if (el == '0') {
                break;
            }
            else if (el == '9') {
                pr_files(files_ns, cf);
                continue;
            }

            f = (pair*)malloc(cf * sizeof(pair));
            cpy(files_ns, f,cf);
            
            check = sort(f, 0, cf - 1,el, cf);
            for (i = 0; i < cf; i++)
            {
                free(f[i].first);
            }
            free(f);
            
        }
        for (i = 0; i < cf; i++)
        {
            free(files_ns[i].first);
        }
        free(files_ns);
        printf("\n\n");
    }
    
    return 0;
}

void ask_sort() {
    printf("\n\n");
    printf("Какую сортировку будем использовать?\n");
    printf(" 2 - выбором | 3 - вставкой | 4 - слиянием | 5 - быстрая\n");
    printf("(\tдля ввода нового пути введите 0  )\n");
    printf("(\tдля вывода исходного массива введите 9 )\n\n");
    printf("->");
}

void swap(pair* files_ns,int i, int j) {
    UINT64* a = &files_ns[i].second;
    UINT64* b = &files_ns[j].second;
    
    if (*a > *b) {
        UINT64 tmp = *a;  
        char* tmpw = files_ns[i].first;

        *a = *b;   
        files_ns[i].first = files_ns[j].first;
        *b = tmp;
        files_ns[j].first = tmpw;
    }
}

void cpy(pair* a, pair* b,int cf) {
    int i = 0;
    for (i; i < cf;i++) {
        b[i].first = _strdup(a[i].first);
        b[i].second = a[i].second;
    }
}




int sort(pair files_ns[], int left, int right, char el, int cf) {
    clock_t start;
    clock_t end;
    double spenttime;

    switch (el) {
    case '2':
        start = clock(); // начало отсчёта
        select_sort(files_ns, cf);
        end = clock(); // конец отсчёта
        break;
    case '3':
        start = clock(); // начало отсчёта
        insert_sort(files_ns, cf);
        end = clock(); // конец отсчёта
        break;
    case '4':
        start = clock(); // начало отсчёта
        mergesort(files_ns, 0, cf - 1);
        end = clock(); // конец отсчёта
        break;
    case '5':
        start = clock(); // начало отсчёта
        qsort(files_ns,cf);
        end = clock(); // конец отсчёта
        break;
    default:       
        return 0;
    }
    
    
    spenttime = (double)(end - start) / CLOCKS_PER_SEC;
    pr_files(files_ns,cf);
    printf("\n Время: %.8f сек \n\n\n", spenttime);
    return 1;
}



void pr_files(pair* files_ns,int cf) {
    int i = 0;
    for (i;i < cf;i++) {
        printf("%s   %llu байт \n", files_ns[i].first, files_ns[i].second);
    }
}


void make_way(char* way) {
    int ln = strlen(way);
    if (way[ln - 1] != '*') {
        way[ln + 1] = way[ln];
        way[ln] = '*';

    }
}


int check_way(char* way) {

    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(way, &finddata);
    if (hFind == INVALID_HANDLE_VALUE) {
        
        return 0;
    }
    return 1;
}



int count_files(char way[]) {
    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(way, &finddata);
    int c = 0;
    
    do {
        if (finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }
        c++;
    } while (FindNextFileA(hFind, &finddata) != NULL);
    return c;
}





pair* get_way_files(char* way,int cf) {
    int i = 0;
    pair* files_ns;
    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(way, &finddata);
    
    
    files_ns = (pair*)malloc(cf * sizeof(pair));
    
    do {
        char* filename = finddata.cFileName;       
        ULARGE_INTEGER fullsize;
        fullsize.HighPart = finddata.nFileSizeHigh;
        fullsize.LowPart = finddata.nFileSizeLow;
        UINT64 filesize = fullsize.QuadPart;
        
        if (!(finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            files_ns[i].first = _strdup(finddata.cFileName);
            
            files_ns[i].second = filesize;
            
            i++;
            continue;
            
        } 

        

        // FILE_ATTRIBUTE_DIRECTORY
        
        
    } while (FindNextFileA(hFind, &finddata) != NULL);
    FindClose(hFind);
        
    return files_ns;
}





void insert_sort(pair* files_ns, int cf) {
    for (int i = 1; i < cf; i++) {
        UINT64 key = files_ns[i].second;
        char* keyw = files_ns[i].first;
        int j = i - 1;
        while (j >= 0 && files_ns[j].second > key) {
            files_ns[j + 1].second = files_ns[j].second;
            files_ns[j + 1].first = files_ns[j].first;
            j--;
        }
        files_ns[j + 1].second = key;
        files_ns[j + 1].first = keyw;
    }
}



void select_sort(pair* files_ns, int cf) {
    int i = 0, j;
    for (i; i < cf - 1; i++) {
        for (j = i + 1; j < cf; j++) {

            swap(files_ns, i, j);
        }
    }
}




void merge(pair* arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;   
    pair* L = (pair*)malloc(n1 * sizeof(pair));
    pair* R = (pair*)malloc(n2 * sizeof(pair));   
    
    for (i = 0; i < n1; i++) {
        L[i].second = arr[left + i].second;
        L[i].first = arr[left + i].first;
    }
    for (j = 0; j < n2; j++) {
        R[j].second = arr[middle + 1 + j].second;
        R[j].first = arr[middle + 1 + j].first;
    }
   
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].second <= R[j].second) {
            arr[k].second = L[i].second;
            arr[k].first = L[i].first;
            i++;
        }
        else {
            arr[k].second = R[j].second;
            arr[k].first = R[j].first;
            j++;
        }
        k++;
    }   
    while (i < n1) {
        arr[k].second = L[i].second;
        arr[k].first = L[i].first;
        i++;
        k++;
    }
   while (j < n2) {
        arr[k].second = R[j].second;
        arr[k].first = R[j].first;
        j++;
        k++;
    }
   free(L);
   free(R);
}


void mergesort(pair* arr, int left, int right) {
    if (left < right) { 
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);       
        merge(arr, left, mid, right);
    }
}


void qsort(pair* a, int n) {


    int i = 0, j = n - 1;
    UINT32 pivot = a[(n - 1) / 2].second;

    while (i <= j) {
        while (a[i].second < pivot) {
            i++;
        }
        while (a[j].second > pivot) {
            j--;
        }
        if (i <= j) {
            UINT64 tmp = a[i].second;
            char* tmpw = a[i].first;

            a[i].second = a[j].second;
            a[i].first = a[j].first;
            a[j].second = tmp;
            a[j].first = tmpw;
            i++;
            j--;
        }
    }

    if (j > 0) {
        qsort(a, j + 1);
    }
    if (i < n - 1) {
        qsort(&a[i], n - i);
    }
}