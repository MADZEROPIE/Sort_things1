#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "sorts1.h"
#include <string.h>
#include <locale.h>
//#include "source.cpp"



#define N 200000
#define K 12
#define Q 12
#define NUM 20

struct sorts_time
{
	int time_sort;
	char name[30];
	int num;
	int sorted_arr[NUM];
};



int NN;

int* input(int *arr, int len) {
	int i;
	printf("Press 0 for default settings or any other number for choose new settings ");
	scanf_s("%d", &i);
	if (i == 0)
		return arr;
	len = -1;
	while (len < 0 || len>7777777) {
		printf("Enter number of elements: ");
		scanf_s("%d", &len);
	}
	NN = len;
	//arr = (int *)realloc(arr, n*sizeof(int));
	arr = (int *)malloc(len * sizeof(int));
	printf("Press 0 if you wanna create random array or any other number if you wanna enter it mannualy ");
	scanf_s("%d", &i);
	if (i == 0 || len > 10000)
		create_r_arr(arr, len);
	else
		for (int j = 0; j < len; j++)
			scanf_s("%d", &arr[j]);
	return arr;

}

int main()
{
	int *c_arr;
	int n = N;
	int *arr = (int*)malloc(N * sizeof(int));
	c_arr = (int*)malloc(N * sizeof(int));
	char menu[Q][25] = { "Input","Output","Bubble sort","Shaker sort","Quick sort","Selection sort","Shell sort","Merge sort","Insertion sort (binary)","Insertion sort (linear)","Merge sort (down-top)","Exit" };
	int k = 0, flag1 = 0;
	sorts_time sorts_arr[K] = { {0," ",0,0} };
	//int time_arr[Q];
	int s_time, e_time, count = 0;
	srand(time(0));
	create_r_arr(c_arr, N);
	FILE* file;
	fopen_s(&file, "sorts_time.cvs", "a");
	/* if (file != NULL) {
		 fprintf(file, "\n%d \n", N);
		 for (int i = 0; i < K; i++)
			 fprintf(file, "%s \t\t %d\n", sorts_arr[i].name, sorts_arr[i].time_sort);
				 }
 */
	while (k != 11) {
		k = choice(menu, Q);

		switch (k)
		{
		case 0:
			c_arr = input(c_arr, N);
			free(arr);
			n = NN;
			arr = (int *)malloc(n * sizeof(c_arr[0]));
			copy_arr(c_arr, arr, n);
			break;

		case 1:
			printf("Default array :\n");
			print_arr(c_arr, NUM);
			//printf("\nSorted array :\n");
			//print_arr(arr,NUM);
			printf("\n\n");
			if (file != NULL) {
				//fprintf(file, "\n%d \n", n);
				if (flag1)
					for (int i = count; i < K; i++) {
						fprintf(file, "%d,%s,%d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						printf("\nSorted array :\n");
						print_arr(sorts_arr[i].sorted_arr, NUM);
						printf("\n");
					}
				for (int i = 0; i < count; i++) {
					fprintf(file, "%d,%s, %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					printf("\nSorted array :\n");
					print_arr(sorts_arr[i].sorted_arr, NUM);
					printf("\n");
				}

			}
			break;

		case 2:
			copy_arr(c_arr, arr, n);
			s_time = clock();
			bubble_sort(arr, n);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Bubble sort",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		case 3:
			copy_arr(c_arr, arr, n);
			s_time = clock();
			shaker_sort(arr, n);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Shaker sort",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		case 4:
			copy_arr(c_arr, arr, n);
			s_time = clock();
			quick_sort(arr, 0, n);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Quick sort",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		case 5:
			copy_arr(c_arr, arr, n);
			s_time = clock();
			selection_sort(arr, n);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Selection sort",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		case 6:
			copy_arr(c_arr, arr, n);
			s_time = clock();
			shaker_sort(arr, n);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Shell sort",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		case 7:
			copy_arr(c_arr, arr, n);
			s_time = clock();
			merge_sort(arr, 0, n - 1);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Merge sort",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		case 8:
			copy_arr(c_arr, arr, n);
			s_time = clock();
			insertion_sort(arr, n);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Insertion sort (binary)",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		case 9:
			copy_arr(c_arr, arr, n);
			s_time = clock();
			insertion_sort(n, arr);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Insertion sort (linear)",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		case 10:

			copy_arr(c_arr, arr, n);
			s_time = clock();
			merge_sort(arr, n);
			e_time = clock();
			sorts_arr[count] = { e_time - s_time,"Merge sort (down-top)",n };
			copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
			break;

		}

		if (count == K) {
			count = count % K;
			flag1 = 1;
		}
	}


	fclose(file);
	return 0;
}

