#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define REP 45
#define FILES 50000 // масимальное число файлов
#define BUFFER 2048 //максимльная длина строки

//объявим прототипы функций:

void Menu(int *method)
void Input(wchar_t **sDir)
void Output(wchar_t **filesName, ULONGLONG *filesSize, int *filesIndex, int N)
int ListDirectoryContents(const wchar_t *sDir, wchar_t **filesName, ULONGLONG *filesSize)
void BubbleSort(ULONGLONG *filesSize, int *filesIndex, int N)
void InsertionSort(ULONGLONG *filesSize, int *filesIndex, int N)
void SelectionSort(ULONGLONG *filesSize, int *filesIndex, int N)
void intSwap(int *arg1, int *arg2)
void ULONGLONGSwap(ULONGLONG *a1, ULONGLONG *a2)
void CountingSort(ULONGLONG *filesSize, int *filesIndex, int N)
void QuickSort(ULONGLONG *filesSize, int *filesIndex, int first, int last)
void MergeSort(ULONGLONG *filesSize, int *filesIndex, int first, int last)
void QuickSplit(ULONGLONG *filesSize, int *i, int *j, int mid, int *filesIndex)
void Merge(ULONGLONG *filesSize, int *filesIndex, int first, int midIndex, int last)


void Menu(int *method)// Функция меню (показывает сортировки, осуществялет ввод переменной,определяющий метод сортировки)
{
	do
	{
		printf("\n Choose the type of sorting:\n 1. BubbleSort\n 2. InsertionSort\n "
			"3. SelectionSort\n 4. CountingSort\n "
			"5. QuickSort\n 6. MergeSort\n7");
		scanf("%d", method);//пользователь определяет алгоритм
	} 
	while ((*method < 0) || (*method > 7));//условие проверки
}
/***работа с файлами****/

void Input(wchar_t **sDir)  // Функция ввода (запишем в sDir путь до директории,это массив)   
//ПОСТУПАЮЩИЕ ЗНАЧЕНИЯ - массив	
{
	char *vvodstring;

	*sDir = (wchar_t*)malloc(BUFFER * sizeof(wchar_t)); //выделение памяти
	vvodstring = (char*)malloc(BUFFER * sizeof(char)); // выделение памяти для массива, в который поместим путь

	fgets(vvodstring, BUFFER, stdin); // принимает :указатель на массив, в который будет помещена считанная строка, максимально допустимая длинна считываемой строки, потом ввода
	vvodstring[strlen(vvodstring) - 1] = '\0';  // убираем ноль в коцнце                  

	swprintf(*sDir, BUFFER, L"%hs", vvodstring); //запись форматированного вывода: указатель на строку, максимальная длинна строки, строка
}

void Output(wchar_t **filesName, ULONGLONG *filesSize, int *filesIndex, int N) // Функция вывода (выводит список файлов с размерами)
//ПОСТУПАЮЩИЕ ЗНАЧЕНИЯ - массив с именами файлов из папки, размеры файлов из папки, индексы файлов, N- количество файлов из заданной папки
{
	int i; // счетчик для вывода

	printf("\n Folder contents:\n");

	for (i = 0; i < N; i++)
		wprintf(L" %d. File: %s Size: %lld bytes\n", i + 1, filesName[filesIndex[i]], filesSize[filesIndex[i]]); //нумерация,имя файла,размер
}
int ListDirectoryContents(const wchar_t *sDir, wchar_t **filesName, ULONGLONG *filesSize) //Функция содержания (запись файлов в каталоге(имена+размеры)
//ПОСТУПАЮЩИЕ ЗНАЧЕНИЯ - путь до директории, имена,размеры
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL; //первое-декскриптор объекта, в данном случае файла
	wchar_t *sPath; //буфер
	int j = 0;//количество файлов

	sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t)); //выделение памяти
	wsprintf(sPath, L"%s\\*.*", sDir); //буфер,формат,аргумент

	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE) //проверка на правильность ввода
	{
		wprintf(L"Path not found: [%s].\n", sDir);
		return -1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)//функция wcscmp сравнивает строки
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
			filesSize[j] = fileSize;

			filesName[j] = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));//выделяем память
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);//вывод
			wsprintf(filesName[j++], L"%s", sPath);//вывод
		}
	} while (FindNextFile(hFind, &fdFile));

	FindClose(hFind);
	return j; //количество файлов созранено
}
//ПОСТУПАЮЩИЕ ЗНАЧЕНИЯ - размер файлов, индексы, их количество одинаковы(почти) для всех функций 

												  /****функции сортировок****/

//СОРТИРОВКА ПУЗЫРЬКОМ
void BubbleSort(ULONGLONG *filesSize, int *filesIndex, int N)
{
	int i, j;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (filesSize[j] > filesSize[j + 1]) //если один больше другого-меняем, в результате первого шага получим больший индекс
			{
				ULONGLONGSwap(&filesSize[j], &filesSize[j + 1]);
				intSwap(&filesIndex[j], &filesIndex[j + 1]); //меняем связанные индексы
			}
		}
	}
}
//СОРТИРОВКА ВСТАВКАМИ
void InsertionSort(ULONGLONG *filesSize, int *filesIndex, int N) //принимает массивы с размерами с индексами и количество элементов, для небольших массивов более эффективна
{
	int i, location, newIndex;//расположение - location
	ULONGLONG tmpIndex; //выбран этот тип, так как размеры файлов в нем же

	for (i = 1; i < N; i++)
	{
		tmpIndex = filesIndex[i];
		location = i - 1;

		while ((location >= 0) && (filesSize[filesIndex[location]] > filesSize[newIndex])) //если не выполняется то переходим к фор и след элементу
		{
			filesIndex[location + 1] = filesIndex[j];
			location = location - 1;
		}
		filesIndex[location + 1] = newIndex;
	}
}
//СОРТИРОВКА ВЫБОРОМ
void SelectionSort(ULONGLONG *filesSize, int *filesIndex, int N)
{   // v- выбранный
	int i, j, minIndex, minIndex1;// i-счетчик

	for (i = 0; i < N; i++)
	{   //в первом проходе цикла нужно выбрать минимальный элемент и меняется местами с первым( fileSize[i=1])
		minIndex = i;
		minIndex1 = filesIndex[i];

		for (j = i + 1; j < N; j++) //поиск минимума со второй позиции
		{
			if (filesSize[filesIndex[j]] < filesSize[minIndex1]) //если один меньше другого-меняем
			{
				minIndex1 = filesIndex[j];
				minIndex = j;
			}
		}
		intSwap(&filesIndex[i], &filesIndex[minIndex]);
	}
}
//Функции перемены значений(ПОСТУПАЮЩИЕ ЗНАЧЕНИЯ - две переменные), разделены, так как переменная для обмена будет разного типа.
void intSwap(int *arg1, int *arg2)//функция меняет местами аргументы типа int
{
	int tmp = *arg1;//tmp- переменная для обмена
	*arg1 = *arg2;
	*arg2 = tmp;
}
void ULONGLONGSwap(ULONGLONG *a1, ULONGLONG *a2)//Функция обмена типа ULOMGLONG
{
	ULONGLONG tmp = *a1;//введем переменную tmp, в которую запишем значение а1
	*a1 = *a2;//значение а2 переходит в а1
	*a2 = tmp; //приравниваем к значению а1, которое хранилось в tmp
}

//СОРТИРОВКА ПОДСЧЕТОМ
void CountingSort(ULONGLONG *filesSize, int *filesIndex, int N)
{
	int *c = (int*)malloc(FILES * sizeof(int));
	int i, j, idx = 0, h = 0;
	for (i = 0; i < FILES; i++)
		c[i] = 0;
	for (i = 0; i < N; i++)
	{
		if (filesSize[filesIndex[i]] > FILES)
		{
			printf("Error\n");
			return;
		}
		c[filesSize[filesIndex[i]]]++;
	}
	for (i = 0; i < FILES; i++)
	{
		if (c[i] > 0)
		{
			h = 0;
			for (j = 0; j < c[i]; j++)
			{
				while (filesSize[h] != i)
					h++;
				filesIndex[idx++] = h++;
			}
		}
	}
	free(c);
}
//БЫСТРАЯ СОРТИРОВКА(рекурсивная)
void QuickSort(ULONGLONG *filesSize, int *filesIndex, int first, int last)
{
	int midIndex, i = first, j = last;

	midIndex = (first + last) / 2;//если число надове неделиться,здесь тип инт, поэтому ответом будет не дробь. средний индекс

	QuickSplit(filesSize, &i, &j, filesSize[midIndex], filesIndex); // вспомогательная функция

	if (j > first)
		QuickSort(filesSize, filesIndex, first, j);
	if (i < last)
		QuickSort(filesSize, filesIndex, i, last);
}
//СОРТИРОВКА СЛИЯНИЕМ
void MergeSort(ULONGLONG *filesSize, int *filesIndex, int first, int last)
{
	int midIndex = (last + first) / 2;

	if (first >= last)
		return;

	MergeSort(filesSize, filesIndex, first, midIndex);
	MergeSort(filesSize, filesIndex, midIndex + 1, last);//смещение индексов
	Merge(filesSize, filesIndex, first, midIndex, last); //вызов дополнительной функции
}
//Функция разделения
void QuickSplit(ULONGLONG *filesSize, int *i, int *j, int mid, int *filesIndex)
{
	do
	{
		while (filesSize[*i] < mid)//идем с начала массива  к середине
			(*i)++;
		while (filesSize[*j] > mid)//идем от конца к серединному элементу
			(*j)--;

		if (*i <= *j)
		{
			ULONGLONGSwap(&(filesSize[*i]), &(filesSize[*j]));
			intSwap(&(filesIndex[*i]), &(filesIndex[*j]));

			(*i)++; //i уходит вправо, а j влево
			(*j)--;
		}
	} while (*i <= *j);
}
//вспомогательная функция для MergeSort
void Merge(ULONGLONG *filesSize, int *filesIndex, int first, int midIndex, int last)
{
	int i = first, j = midIndex + 1, it;
	int *forIndex = (int*)malloc((last - first + 1) * sizeof(int));//массив для индексов
	ULONGLONG *R = (ULONGLONG*)malloc((last - first + 1) * sizeof(ULONGLONG));//массив для размеров

	for (it = 0; it < last - first + 1; it++)
		if ((j > last) || ((i <= midIndex) && (filesSize[i] < filesSize[j])))
		{
			R[it] = filesSize[i];
			forIndex[it] = filesIndex[i++];
		}
		else
		{
			R[it] = filesSize[j];
			forIndex[it] = filesIndex[j++];
		}

	for (it = first; it < last + 1; it++)
	{
		filesSize[it] = R[it - first];
		filesIndex[it] = forIndex[it - first];
	}

	free(R);
	free(forIndex);
}


//ОСНОВНАЯ ФУНКЦИЯ
void main()
{
	wchar_t *filesPath, **filesName;// путь, имена
	ULONGLONG *filesSize, *tmpSizes;//размер,обмен размеров
	clock_t start, end;// для времени
	int *filesIndex;// индексы
	int j = -1, i = 0;
	int method = 0, f = 0;

	filesName = (wchar_t**)malloc(FILES * sizeof(wchar_t*));//выделение памяти для имен
	filesSize = (ULONGLONG*)malloc(FILES * sizeof(ULONGLONG));//выделение памяти для размеров

	printf("\t\t\t\tFile Manager");
	printf("\n\tWay to the folder:");

	while (j == -1)
	{
		Input(&filesPath);
		j = ListDirectoryContents(filesPath, filesName, filesSize);//
	}

	filesIndex = (int*)malloc(j * sizeof(int));//выделение памяти
	for (i = 0; i < j; i++)
		filesIndex[i] = i;

	Output(filesName, filesSize, filesIndex, j, 1);

	do
	{
		Menu(&method);
		if (method == 0) return;

		tmpSizes = (ULONGLONG*)malloc(j * sizeof(ULONGLONG));    //выделения массива       
		for (i = 0; i < j; i++)
			tmpSizes[i] = filesSize[i];

		printf("\nType of sort - %d.", method);
		start = clock();

		switch (method)
		{
		case 1:
			BubbleSort(tmpSizes, filesIndex, j);
			break;
		case 2:
			InsertionSort(tmpSizes, filesIndex, j);
			break;
		case 3:
			SelectionSort(tmpSizes, filesIndex, j);
			break;
		case 4:
			CountingSort(tmpSizes, filesIndex, j);
			break;
		case 5:
			QuickSort(tmpSizes, filesIndex, 0, (j - 1));
			break;
		case 6:
			MergeSort(tmpSizes, filesIndex, 0, (j - 1));
			break;
		}

		end = clock();

		Output(filesName, filesSize, filesIndex, j);

		printf("\n Time: %.4lf sec.\n", (double)(end - start) / CLOCKS_PER_SEC);//вывод времени в секундах с заданной точностью 41 знак после запятой

		for (i = 0; i < j; i++)
			filesIndex[i] = i;
		start = end = 0;
		free(tmpSizes);
	} while (1);
}
