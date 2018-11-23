#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "sorts1.h"


#define N 20000 //КОЛИЧЕСТВО ЭЛЕМЕНТОВ МАССИВА(ПО УМОЛЧАНИЮ)
#define K 10 // КОЛИЧЕСТВО РЕЗУЛЬТАТОВ СОРТИРОВОК СОХРАНЯЕМЫХ В ПАМЯТИ
#define Q 11 // КОЛИЧЕСТВО ПУНКТОВ МЕНЮ
#define NUM 20 //КОЛИЧЕСТВО ЭЛЕМЕНТОВ МАССИВА ВЫВОДЯЩИХСЯ НА ЭКРАН

struct sorts_time
{
	int time_sort; 
	char name[33];
	int num;
	int sorted_arr[NUM];
};


int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n = N;//КОЛИЧЕСТВО ЭЛЕМЕНТОВ МАССИВА (ИЗМЕНЯЕМОЕ)
	int *C_ARR = (int*)malloc(N * sizeof(int));//СОЗДАНИЕ ДИНАМИЧЕСКОГО МАССИВА (МАССИВ ПО УМОЛЧАНИЮ)
	int *arr = (int*)malloc(N * sizeof(int));//СОЗДАНИЕ ДИНАМИЧЕСКОГО МАССИВА (МАССИВ ДЛЯ СОРТИРОВКИ)
	//char menu[Q][25] = { "Input","Output","Bubble sort","Shaker sort","Quick sort","Selection sort","Shell sort","Merge sort","Insertion sort (binary)","Insertion sort (linear)","Merge sort (down-top)","Exit" };
	char menu[Q][33] = { "Ввод","Вывод","Сортировка пузырьком","Шейкерная сортировка","Быстрая сортировка","Сортировка выбором","Сортировка слиянием (нисходящая)","Сортировка слиянием (восходящая)","Сортировка вставками (линейная)","Сортировка вставками (бинарная)","Выход" };
	int k = 0, flag1 = 0;
	sorts_time sorts_arr[K] = { {0," ",0,0} };
	int s_time, e_time, count = 0;
	srand(time(0));//ПРОКРУТКА СЧЁТЧИКА ПСЕВДОСЛУЧАЙНЫХ ЧИСЕЛ
	create_r_arr(C_ARR, N);//ЗАПОЛНЯЕМ МАССИВ СЛУЧАЙНЫМИ ЧИСЛАМИ
	FILE* file;//СОЗДАНИЕ ФАЙЛА В КОТОРОМ БУДУТ ХРАНИТЬСЯ РЕЗУЛЬТАТЫ СОТИРОВОК
	fopen_s(&file, "sorts_time.csv", "w");// ОТКРЫВАЕМ ФАЙЛ ДЛЯ ЗАПИСИ
	if (file != NULL) {
		while (k != 10) {
			k = choice(menu, Q);
			switch (k)
			{
			case 0:
				C_ARR = input(C_ARR, &n);
				free(arr);
				arr = (int *)malloc(n * sizeof(C_ARR[0]));
				copy_arr(C_ARR, arr, n);
				break;

			case 1:
				//printf("Default array :\n");
				printf("Исходный массив :\n");
				print_arr(C_ARR, NUM);
				printf("\n\n");
				//fprintf(file, "\sep=, \n");
				if (flag1) {
					for (int i = count; i < K; i++) {
						fprintf(file, "%d,%s,%d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						//printf("Sorted array :\n");
						printf("Отсортированный массив :\n");
						print_arr(sorts_arr[i].sorted_arr, NUM);
						printf("\n\n");
					}
				}
				for (int i = 0; i < count; i++) {
					fprintf(file, "%d,%s, %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					//printf("Sorted array :\n");
					printf("Отсортированный массив :\n");
					print_arr(sorts_arr[i].sorted_arr, NUM);
					printf("\n\n");
					}
				break;

			case 2:
				copy_arr(C_ARR, arr, n);//КОПИРОВАНИЕ ЭЛ-ТОВ ИЗ ОСНОВНОГО МАССИВА В "СОРТИРОВОЧНЫЙ" МАССИВ
				s_time = clock();//ВРЕМЯ РАБОТЫ ПРОГРАММЫ ДО СОРТИРОВКИ
				bubble_sort(arr, n);//ВЫЗОВ СОРТИРОВКИ
				e_time = clock();//ВРЕМЯ РАБОТЫ ПРОГРАММЫ ПОСЛЕ СОРТИРОВКИ
				sorts_arr[count] = { e_time - s_time,"Сортировка пузырьком",n };//ЗАПИСЬ РЕЗУЛЬТАТОВ
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 3:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				shaker_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Шейкерная сортировка",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 4:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				quick_sort(arr, 0, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Быстрая сортировка",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 5:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				selection_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Сортировка выбором",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
/*
			case 6:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				shaker_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Shell sort",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
*/
			case 6:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				merge_sort(arr, 0, n - 1);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Сортировка слиянием (нисходящая)",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
			
			case 7:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				merge_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Сортировка слиянием (восходящая)",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 8:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				insertion_sort(n, arr);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Сортировка вставками (линейная)",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 9:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				insertion_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Сортировка вставками (бинарная)",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
			}

			if (count == K) { 
				count = 0; //СБРОС СЧЕТЧИКА ПРИ МАКСИМАЛЬНОМ КОЛИЧЕСТВЕ РЕЗУЛЬТАТОВ
				flag1 = 1;
			}
		}

	free(C_ARR);//ОСВОБОЖДАЕМ ПАМЯТЬ ОТ МАССИВОВ
	free(arr);
	fclose(file);//ЗАКРЫВАЕМ ФАЙЛ
	}
	return 0;
}

