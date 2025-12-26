#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#define MAX_PATH_LEN 1024
#define MAX_COMMAND_LEN 2048
#define MAX_METHOD_NAME 20

typedef struct {
    wchar_t name[MAX_PATH];
    int size;
} FileInfo;

// Sorts
void SimpleSort(int a[], int n);
void ChoiceSort(int a[], int n);
void InsertionSort(int a[], int n);
void MergeSort(int a[], int n);
void _MergeSort(int a[], int l, int r, int tmp[]);
void QuickSort(int a[], int n);
void _QuickSort(int a[], int l, int r);
void RadixSort(int a[], int n);

// !!!GLOBALS!!!
char current_path[MAX_PATH_LEN] = "";
char current_method[MAX_METHOD_NAME] = "simple";
FileInfo* file_list = NULL;
int file_count = 0;

void (*sort_funcs[])(int[], int) = {
    SimpleSort,    // simple
    ChoiceSort,    // choice
    InsertionSort, // insertion
    MergeSort,     // merge
    QuickSort,     // quick
    RadixSort      // radix
};

char* method_names[] = {
    "simple",
    "choice",
    "insertion",
    "merge",
    "quick",
    "radix"
};
int method_count = sizeof(method_names) / sizeof(method_names[0]);

// commands
void help();
void path(char* arg);
void method(char* arg);
void list();

// utility
void parse_input(char* input, char* command, char* arg);
int get_method_index(char* method_name);
void free_file_list();
void read_directory();

// sort
void sort_with_indices(int indices[], int count);
int cmp_size(int idx1, int idx2);

int main() {
    char input[MAX_COMMAND_LEN];
    char command[50];
    char arg[MAX_PATH_LEN];

    printf("File Manager with Sorting\n");
    printf("Type 'help' for commands list\n");

    while (1) {
        printf("\n> ");
        fgets(input, MAX_COMMAND_LEN, stdin);
        input[strcspn(input, "\n")] = 0;

        parse_input(input, command, arg);

        if (strcmp(command, "help") == 0) {
            help();
        }
        else if (strcmp(command, "path") == 0) {
            path(arg);
        }
        else if (strcmp(command, "method") == 0) {
            method(arg);
        }
        else if (strcmp(command, "list") == 0) {
            list();
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            free_file_list();
            break;
        }
        else {
            printf("Unknown command. Type 'help' for commands list.\n");
        }
    }

    return 0;
}

void help() {
    printf("Available commands:\n");
    printf("  help                 - Show this help message\n");
    printf("  path [directory]     - Set working directory\n");
    printf("  method [name]        - Set sorting method (simple, choice, insertion, merge, quick, radix)\n");
    printf("  list                 - List files in directory sorted by size\n");
    printf("  exit                 - Exit program\n");
    printf("\nCurrent path: %s\n", current_path[0] ? current_path : "(not set)");
    printf("Current method: %s\n", current_method);
}

void path(char* arg) {
    LPCTSTR path_name;
    size_t arg_len = strlen(arg);
    wchar_t* tmp = (wchar_t*)malloc(MAX_PATH_LEN * sizeof(wchar_t));
    if (arg_len == 0) {
        printf("Usage: path [directory]\n");
        return;
    }
    mbstowcs_s(&arg_len, tmp, MAX_PATH_LEN, arg, arg_len);

    path_name = tmp;
    DWORD attrib = GetFileAttributes(path_name);
    free(tmp);
    if (attrib == INVALID_FILE_ATTRIBUTES || (attrib & FILE_ATTRIBUTE_DIRECTORY == 0)) {
        printf("Error: Invalid directory path\n");
        return;
    }

    strncpy_s(current_path, MAX_PATH_LEN, arg, MAX_PATH_LEN - 1);
    current_path[MAX_PATH_LEN - 1] = '\0';
    printf("Path set to: %s\n", current_path);

    free_file_list();
}

void method(char* arg) {
    if (strlen(arg) == 0) {
        printf("Usage: method [name]\n");
        printf("Available methods: ");
        for (int i = 0; i < method_count; i++) {
            printf("%s ", method_names[i]);
        }
        printf("\n");
        return;
    }

    int idx = get_method_index(arg);
    if (idx == -1) {
        printf("Error: Unknown method '%s'\n", arg);
        printf("Available methods: ");
        for (int i = 0; i < method_count; i++) {
            printf("%s ", method_names[i]);
        }
        printf("\n");
        return;
    }

    strncpy_s(current_method, MAX_METHOD_NAME, arg, MAX_METHOD_NAME - 1);
    printf("Method set to: %s\n", current_method);
}

void list() {
    if (strlen(current_path) == 0) {
        printf("Error: Path not set. Use 'path' command first.\n");
        return;
    }

    read_directory();

    if (file_count == 0) {
        printf("No files found in directory.\n");
        return;
    }

    int* indices = (int*)malloc(file_count * sizeof(int));
    for (int i = 0; i < file_count; i++) {
        indices[i] = i;
    }

    LARGE_INTEGER freq;
    LARGE_INTEGER start_time, end_time;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start_time);
    sort_with_indices(indices, file_count);
    QueryPerformanceCounter(&end_time);

    double time_taken = ((double)(end_time.QuadPart - start_time.QuadPart)) * 1.0e9 / freq.QuadPart;

    wprintf(L"\n%-30s %15s\n", L"File Name", L"Size (bytes)");
    wprintf(L"%-30s %15s\n", L"---------", L"------------");

    for (int i = 0; i < file_count; i++) {
        int idx = indices[i];
        wprintf(L"%-30s %15d\n", file_list[idx].name, file_list[idx].size);
    }

    wprintf(L"\nSorting time: %.3f ns\n", time_taken);

    free(indices);
}

void parse_input(char* input, char* command, char* arg) {
    command[0] = '\0';
    arg[0] = '\0';

    char* space = strchr(input, ' ');
    if (space) {
        int cmd_len = space - input;
        strncpy_s(command, 50, input, cmd_len);
        command[cmd_len] = '\0';
        strcpy_s(arg, MAX_PATH_LEN, space + 1);
    }
    else {
        strcpy_s(command, 50, input);
    }
}

int get_method_index(char* method_name) {
    for (int i = 0; i < method_count; i++) {
        if (strcmp(method_name, method_names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void free_file_list() {
    if (file_list) {
        free(file_list);
        file_list = NULL;
        file_count = 0;
    }
}

void read_directory() {
    free_file_list();

    char search_path[MAX_PATH_LEN];
    snprintf(search_path, MAX_PATH_LEN, "%s\\*", current_path);
    int search_len = strlen(search_path);
    LPCTSTR path_name;
    wchar_t* tmp = (wchar_t*)malloc(MAX_PATH_LEN * sizeof(wchar_t));
    mbstowcs_s(&search_len, tmp, MAX_PATH_LEN, search_path, search_len);

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(tmp, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Error: Cannot read directory\n");
        return;
    }

    int count = 0;
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            count++;
        }
    } while (FindNextFile(hFind, &findFileData));

    if (count == 0) {
        FindClose(hFind);
        return;
    }

    file_list = (FileInfo*)malloc(count * sizeof(FileInfo));
    file_count = 0;

    hFind = FindFirstFile(tmp, &findFileData);
    free(tmp);
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            wcsncpy_s(file_list[file_count].name, MAX_PATH, findFileData.cFileName, MAX_PATH - 1);
            file_list[file_count].name[MAX_PATH - 1] = '\0';

            LARGE_INTEGER fileSize;
            fileSize.LowPart = findFileData.nFileSizeLow;
            fileSize.HighPart = findFileData.nFileSizeHigh;
            file_list[file_count].size = (int)fileSize.QuadPart;

            file_count++;
        }
    } while (FindNextFile(hFind, &findFileData) && file_count < count);

    FindClose(hFind);
}

int cmp_size(int idx1, int idx2) {
    return file_list[idx1].size - file_list[idx2].size;
}

void sort_with_indices(int indices[], int count) {
    int method_idx = get_method_index(current_method);
    if (method_idx == -1) {
        method_idx = 0;
    }

    sort_funcs[method_idx](indices, count);
}

void SimpleSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (cmp_size(a[i], a[j]) > 0) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

void ChoiceSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++)
            if (cmp_size(a[j], a[min_idx]) < 0)
                min_idx = j;
        int t = a[i];
        a[i] = a[min_idx];
        a[min_idx] = t;
    }
}

void InsertionSort(int a[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int t = a[i];
        j = i - 1;
        while (j >= 0 && cmp_size(a[j], t) > 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}

void MergeSort(int a[], int n) {
    int* tmp = malloc(n * sizeof(int));
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
}

void _MergeSort(int a[], int l, int r, int* tmp) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    _MergeSort(a, l, m, tmp);
    _MergeSort(a, m + 1, r, tmp);

    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (cmp_size(a[i], a[j]) <= 0)
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];

    memcpy(a + l, tmp, k * sizeof(int));
}

void QuickSort(int a[], int n) {
    _QuickSort(a, 0, n - 1);
}

void _QuickSort(int a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    int mid = l + (r - l) / 2;
    int pivot = a[mid];

    do {
        while (cmp_size(a[i], pivot) < 0) i++;
        while (cmp_size(a[j], pivot) > 0) j--;
        if (i <= j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++, j--;
        }
    } while (i <= j);

    if (l < j) _QuickSort(a, l, j);
    if (i < r) _QuickSort(a, i, r);
}

void RadixSort(int a[], int n) {
    int* output = (int*)malloc(n * sizeof(int));
    int* count = (int*)malloc(256 * sizeof(int));
    for (int shift = 0; shift < 24; shift += 8) {
        memset(count, 0, 256 * sizeof(int));
        for (int i = 0; i < n; i++) {
            int size = file_list[a[i]].size;
            int byte_val = (size >> shift) & 0xFF;
            count[byte_val]++;
        }
        for (int i = 1; i < 256; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            int size = file_list[a[i]].size;
            int byte_val = (size >> shift) & 0xFF;
            output[count[byte_val] - 1] = a[i];
            count[byte_val]--;
        }
        memcpy(a, output, n * sizeof(int));
    }

    free(output);
    free(count);
}
