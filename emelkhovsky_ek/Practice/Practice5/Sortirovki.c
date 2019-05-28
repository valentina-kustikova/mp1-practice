#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define BUF 2048
#define MAX 65535

void INPUT_PATH(wchar_t **sDir)
{
    char *str;
    *sDir = (wchar_t*)malloc(BUF * sizeof(wchar_t));
    str = (char*)malloc(BUF * sizeof(char));
    fgets(str, BUF, stdin);
    str[strlen(str) - 1] = '\0';
    swprintf(*sDir, BUF, L"%hs", str);
    free(str);
}

int DIRECTORY(const wchar_t *sDir, wchar_t ***fName, ULONGLONG **fSize)
{
    int i = 0;
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *ssPath;
    ssPath = (wchar_t*)malloc(BUF * sizeof(wchar_t));

    wsprintf(ssPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(ssPath, &fdFile)) == INVALID_HANDLE_VALUE)
        return -1;

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
            i++;
    } while (FindNextFile(hFind, &fdFile));

    hFind = FindFirstFile(ssPath, &fdFile);
    *fName = (wchar_t**)malloc(i * sizeof(wchar_t*));//выделяю память под массив названий
    *fSize = (ULONGLONG*)malloc(i * sizeof(ULONGLONG)); // выделяю память под массив размеров
    i = 0;
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;

            (*fName)[i] = (wchar_t*)malloc(BUF * sizeof(wchar_t));//выделяю память под каждое название
            (*fSize)[i] = fileSize;
            wsprintf(ssPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf((*fName)[i], L"%s", ssPath);
            i++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);

    free(ssPath);
    return i;
}


void OUTPUT(int *fIndex, wchar_t **fName, ULONGLONG *fSize, int kol)
{
    int i;
    for (i = 0; i < kol; i++) {
        wprintf(L"%d: Файл: %s Размер: ", i, fName[fIndex[i]]);
        printf("%d , байт\n", (int)fSize[fIndex[i]]);
    }
}


void SORT_CHOICE(ULONGLONG *sizes, int *idxes, int kol) {
    int i, j, minidx, tmp;
    ULONGLONG min;
    for (i = 0; i < kol; i++) {
        minidx = i;
        for (j = i + 1; j < kol; j++)
            if (sizes[idxes[minidx]] >sizes[idxes[j]])
                minidx = j;
        tmp = idxes[i];
        idxes[i] = idxes[minidx];
        idxes[minidx] = tmp;
    }
}


void SORT_INSERT(ULONGLONG *sizes, int *idxes, int kol) {
    int i, j;
    ULONGLONG tmp;
    for (i = 1; i < kol; i++) {
        tmp = sizes[idxes[i]];
        j = i - 1;
        while ((j >= 0) && (sizes[idxes[j]]>tmp)) {
            idxes[j + 1] = idxes[j];
            idxes[j] = i;
            j--;
        }
    }
}

void SORT_BUBBLE(ULONGLONG *sizes, int *idxes, int kol)
{
    ULONGLONG tmp;
    int i, j, *newIndex;
    for (i = 0; i < kol; i++)
        for (j = 1; j < kol - i; j++)
            if (sizes[idxes[j - 1]] > sizes[idxes[j]]) {
                tmp = sizes[idxes[j - 1]];
                sizes[idxes[j - 1]] = sizes[idxes[j]];
                sizes[idxes[j]] = tmp;
            }
}

void SORT_COUNT(ULONGLONG *sizes, int *idxes, int kol) {
    ULONGLONG E, min, max;
    int* c;
    int i, j, idx = 0, p = 0;
    min = sizes[0];
    max = sizes[0];
    for (i = 1; i < kol; i++) {
        if (sizes[i] < min)
            min = sizes[i];
        if (sizes[i] > max)
            max = sizes[i];
    }
    E = max - min + 1;//создаем диапазон
    if (E > MAX) {
        printf("Слишком большой диапозон размеров, попробуйте другую сортировку\n");
        return -1;
    }
    c = (int*)malloc(E * sizeof(int));
    for (i = 0; i < E; i++)
        c[i] = 0;
    for (i = 0; i < kol; i++)
        c[sizes[i] - min]++;//заполняем новый массив с новой нумерацией
    for (i = 0; i < E; i++)
        if (c[i]>0) {
            p = 0;
            for (j = 0; j < c[i]; j++) {
                while (sizes[p] != i)  //пока в ячейке нового массива не закончились значения
                    p++;
                idxes[idx] = p;
                p++;
                idx++;
            }
        }
    free(c);
}


void SORT_HOARA2(ULONGLONG *sizes, int *idxes, int *i, int *j, ULONGLONG m)
{
    int tmp;
    do {
        while (sizes[idxes[(*i)]] < m)
            (*i)++;
        while (sizes[idxes[(*j)]] > m)
            (*j)--;
        if ((*i) <= (*j))
        {
            tmp = idxes[(*i)];
            idxes[(*i)] = idxes[(*j)];
            idxes[(*j)] = tmp;
            (*i)++;
            (*j)--;
        }
    } while ((*i) < (*j));
}


void SORT_HOARA1(ULONGLONG *sizes, int *idxes, int n1, int n2)
{
    int middle = (n1 + n2) / 2;
    int i = n1, j = n2;
    SORT_HOARA2(sizes, idxes, &i, &j, sizes[idxes[middle]]);
    if (j > n1)
        SORT_HOARA1(sizes, idxes, n1, j);
    if (i < n2)
        SORT_HOARA1(sizes, idxes, i, n2);
}

void SORT_MERGE2(ULONGLONG *sizes, int *idxes, int l, int m, int r) {
    int i, j = m + 1, p, tmp;
    for (i = l; ((i < r) && (j <= r)); i++)
        if (sizes[idxes[i]] > sizes[idxes[j]]) {
            tmp = idxes[j];
            for (p = j; p > i; p--)//раздвигаем массивчик
                idxes[p] = idxes[p - 1];
            idxes[i] = tmp;
            j++;
        }
}

void SORT_MERGE1(ULONGLONG *sizes, int *idxes, int l, int r)
{
    int m;
    if (l >= r)
        return;
    m = (l + r) / 2;
    SORT_MERGE1(sizes, idxes, l, m);
    SORT_MERGE1(sizes, idxes, m + 1, r);
    SORT_MERGE2(sizes, idxes, l, m, r);
}

void main()
{
    int t, i, kol;
    int *fIndex;
    wchar_t *sPath;
    wchar_t **fName;
    ULONGLONG *fSize;
    clock_t start, end;
    float  T_TIME_T = 0.0f;
    setlocale(LC_ALL, "Russian");
    printf("******************************************** FILE * MANAGER *****************************************************\n");
    do {
        printf("Введите путь к папке: \n");
        INPUT_PATH(&sPath);
        kol = DIRECTORY(sPath, &fName, &fSize);
        if (kol == -1)
            printf("Указанный путь не найден. Проверьте правильность ввода.\n");
        fIndex = (int*)malloc((kol + 1) * sizeof(int));
        for (i = 0; i < kol; i++)
            fIndex[i] = i;
        printf(" Всего файлов %d:\n", kol);
        printf("Введите метод сортировки:\n1-сортировка выбором\n2-сортировка вставками\n3-сортировка пузырьком\n4-сортировка подсчётом\n5-сортировка Хоара\n6-сортировка слиянием\n");
        scanf("%d", &t);
        printf("Список файлов: \n");
        start = clock();
        switch (t)
        {
        case 1:
            SORT_CHOICE(fSize, fIndex, kol);
            OUTPUT(fIndex, fName, fSize, kol);
            break;
        case 2:
            SORT_INSERT(fSize, fIndex, kol);
            OUTPUT(fIndex, fName, fSize, kol);
            break;
        case 3:
            SORT_BUBBLE(fSize, fIndex, kol);
            OUTPUT(fIndex, fName, fSize, kol);
            break;
        case 4:
            SORT_COUNT(fSize, fIndex, kol);
            OUTPUT(fIndex, fName, fSize, kol);
            break;
        case 5:
            SORT_HOARA1(fSize, fIndex, 0, kol - 1);
            OUTPUT(fIndex, fName, fSize, kol);
            break;
        case 6:
            SORT_MERGE1(fSize, fIndex, 0, kol - 1);
            OUTPUT(fIndex, fName, fSize, kol);
            break;
        default:
            printf("Неверный ввод, попробуйте еще раз\n");
            continue;
        }
        end = clock();
        T_TIME_T = (float)(end - start) / CLOCKS_PER_SEC;
        printf("Время сортировки: %.3f с\n", T_TIME_T);

        for (i = 0; i < kol; i++)
            free(fName[i]);
        free(fName);
        free(fSize);
        free(fIndex);
        free(sPath);
    } while (1);
}