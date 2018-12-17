#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <locale.h>
#define N 70
#define MAX_LEN 4048
#define CLOCKS_PER_SEC 1000
#define ROFL 2000
#define MAX_FILES 1000
int kolvo=0;
#define K 150

int ListDirectoryContents(const wchar_t *sDir, ULONGLONG*filesize, wchar_t **fileNames)
{ 
    int i=0;
    WIN32_FIND_DATA fdFile; 
    HANDLE hFind = NULL; 
    wchar_t *sPath;
    sPath = (wchar_t*)malloc(ROFL * sizeof(wchar_t));
    wsprintf(sPath, L"%s\\*.*", sDir); 
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE) 
    { 
        wprintf(L"Path not found: [%s]\n", sDir); 
        return 1; 
    } 
    do
    { 
        if (wcscmp(fdFile.cFileName, L".") != 0  && wcscmp(fdFile.cFileName, L"..") != 0) 
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8; 
            fileSize |= fdFile.nFileSizeLow;
            filesize[i]=fileSize;
            fileNames[i] = (wchar_t*)malloc(ROFL * sizeof(wchar_t));
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(fileNames[i], L"%s", sPath); 
            i++;
            kolvo++;
        }
    } 
    while(FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return 0; 
}
int* quicksort(ULONGLONG* size, int n1, int n2, int n, int* id)
{
    ULONGLONG tmp;
    int i = n1, j = n2, p = size[(n1 + n2) / 2], tmp1, k;
    do {
        while (size[i] < p) i++;
        while (size[j] > p) j--;
            if (i <= j) 
            {
                if (size[i] > size[j])
                {
                    tmp = size[i];
                    size[i]=size[j];
                    size[j]=tmp;
                    tmp1=id[i];
                    id[i]=id[j];
                    id[j]=tmp1;
                }
                i++;
                j--;
            }
        }while (i <= j);
        if (i < n2)
            id = quicksort(size, i, n2, n, id);
        if (n1 < j)
            id = quicksort(size, n1, j, n, id);
        return id;
}
void podschetom(ULONGLONG*a, int n, int*newindex)
{
    int i, j, b = 0;
    ULONGLONG *count;
    ULONGLONG *dopmass;
    ULONGLONG min=a[0], max=a[n-1], k;
    dopmass=(ULONGLONG*)malloc(n*sizeof(ULONGLONG));
    for (i = 0; i < n; i++)
    {
        dopmass[i]=a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    k=max + min +1;
    count = (ULONGLONG*)malloc(k * sizeof(ULONGLONG));
    for (i = 0; i < k; i++) 
        count[i] = 0;
    for (i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[b++] = i + min;
    }
    for (j = 0; j < n; j++)
    b=0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if ((a[i]==dopmass[j]))
            {
                newindex[b] = j;
                dopmass[j] = -1;
                b++;
                break;
            }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", newindex[i]);
    }
}
void choose(ULONGLONG* filesize, int kolvo, int*newindex)
{
    int i, j, minind;
    ULONGLONG min;
    for (i = 0; i < kolvo; i++)
    {
        min=filesize[i];
        minind=i;
        
        for (j = i + 1; j < kolvo; j++)
        {
            if(filesize[j] < min)
            {
                min = filesize[j];
                minind=j;
                newindex[i]=j;
                filesize[minind]=filesize[i];
                filesize[i]=min;
            }
        }
    }
}
void bubble(ULONGLONG* filesize, int *numer, int kolvo)
{
    int i, j,  swap;
    ULONGLONG tmp;
    for (i = 0; i < kolvo; i++)
    {
        for (j = 1; j < kolvo; j++)
        {
            if(filesize[j-1] > filesize[j])
            {
                tmp=filesize[j];
                filesize[j]=filesize[j-1];
                filesize[j-1]=tmp;
                swap=numer[j];
                numer[j]=numer[j-1];
                numer[j-1]=swap;
            }
        }
    }
}
void insert(ULONGLONG* filesize, int *numer, int kolvo)
{
    int i, j, swap;
    ULONGLONG tmp;
    for ( i = 0; i < kolvo; i++)
    {
        j=i-1;
        tmp=filesize[i];
        swap=numer[i];
        while((j>=0) && (filesize[j] > tmp))
        {
            filesize[j+1]=filesize[j];
            filesize[j]=tmp;
            numer[j+1]=numer[j];
            numer[j]=swap;
            j--;
        }
    }
}
void print(ULONGLONG* filesize, wchar_t **fileNames, int kolvo)
{
    int i;
    for (i = 0; i < kolvo; i++)
    {
        wprintf(L"file  %s ������ %lld \n", fileNames[i], filesize[i]);
    }
}
void menu()
{
    printf("���� ���������!\n");
    printf("������� 1 ��� ���������� ���������!\n");
    printf("������� 2 ��� ���������� ��������!\n");
    printf("������� 3 ��� ���������� �������!");
    printf("������� 4 ��� ���������� ���������!\n");
    printf("������� 5 ��� ������� ����������(���������� �����)!\n");
    printf("������� 6 ��� ���������� ��������!\n");
    printf("�� ������� ���������� �����: \n");
}
void main()
{
    int i=0, vla=0;
    float total_time;
    wchar_t **fileNames;
    int*filesindex;
    int choice, flag=1;
    clock_t start, end;
    int*newindex=(int*)malloc(kolvo * sizeof(int));
    ULONGLONG*filesize=(ULONGLONG*)malloc(MAX_FILES * sizeof(ULONGLONG));
    char*a=(char*)malloc(MAX_LEN);
    wchar_t* ca=(wchar_t*)malloc(MAX_LEN);
    setlocale(LC_ALL, "Russian");
    printf("�������� ��������!\n");
    printf("������� ����!\n");
    fgets(a, MAX_LEN, stdin);
    a[strlen(a)-1] = '\0';
    swprintf(ca, MAX_LEN, L"%hs", a);
    fileNames = (wchar_t**)malloc(ROFL * sizeof(wchar_t*));
    filesindex = (int*)malloc((kolvo + 1) * sizeof(int));
    setlocale(LC_ALL, "Russian");
    ListDirectoryContents(ca, filesize, fileNames);
    print(filesize, fileNames, kolvo);
    for (i = 0; i < kolvo; i++)
    {
        filesindex[i]=i;
        newindex[i]=0;
    }
    menu();
    do {
         scanf("%d", &choice);
         switch (choice) 
        {
         case 1:
            start=clock();
             printf("���������� ���������!\n");
            bubble(filesize, filesindex, kolvo);
            end=clock();
            for (i = 0; i < kolvo; i++) 
                { 
                    vla=filesindex[i]; 
                    wprintf(L"file %s ������ %lld \n", fileNames[filesindex[i]], filesize[i]); 
                    vla=0; 
                }
            total_time = (float)(end - start) / CLOCKS_PER_SEC;
            printf("����� ����������: %.3f �\n", total_time);
            break;
        case 2:
            start=clock();
             printf("���������� ��������\n");
            insert(filesize, filesindex, kolvo);
            end=clock();
            for (i = 0; i < kolvo; i++) 
                { 
                    vla=filesindex[i]; 
                    wprintf(L"file %s ������ %lld \n", fileNames[filesindex[i]], filesize[i]); 
                    vla=0; 
                }
            total_time = (float)(end - start) / CLOCKS_PER_SEC;
            printf("����� ����������: %.3f �\n", total_time);
            break;
        case 3:
            start=clock();
             printf("���������� �������\n");
            choose(filesize, kolvo, newindex);
            end=clock();
            for (i = 0; i < kolvo; i++) 
                { 
                    vla=filesindex[i]; 
                    wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[i]); 
                    vla=0; 
                }
            total_time = (float)(end - start) / CLOCKS_PER_SEC;
            printf("����� ����������: %.3f �\n", total_time);
            break;
        case 4:
            start=clock();
            printf("���������� ���������!");
            podschetom(filesize, kolvo, newindex);
            end=clock();
            for (i = 0; i < kolvo; i++) 
                { 
                    vla=filesindex[i]; 
                    wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[i]); 
                    vla=0; 
                }
            total_time = (float)(end - start) / CLOCKS_PER_SEC;
            printf("����� ����������: %.3f �\n", total_time);
            break;
        case 5:
            start=clock();
            newindex = quicksort(filesize, 0, kolvo-1, kolvo, filesindex);
            end=clock();
            for (i = 0; i < kolvo; i++) 
                { 
                    vla=filesindex[i]; 
                    wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[i]); 
                    vla=0; 
                }
            total_time = (float)(end - start) / CLOCKS_PER_SEC;
            printf("����� ����������: %.3f �\n", total_time);
             break;
        case 6:
            flag=0;
            break;
         default:
             menu();
         }
    }while(flag != 0);
}