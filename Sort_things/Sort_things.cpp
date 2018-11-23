#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "sorts1.h"


#define N 20000 //���������� ��������� �������(�� ���������)
#define K 10 // ���������� ����������� ���������� ����������� � ������
#define Q 11 // ���������� ������� ����
#define NUM 20 //���������� ��������� ������� ����������� �� �����

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
	int n = N;//���������� ��������� ������� (����������)
	int *c_arr = (int*)malloc(N * sizeof(int));//�������� ������������� ������� (������ �� ���������)
	int *arr = (int*)malloc(N * sizeof(int));//�������� ������������� ������� (������ ��� ����������)
	//char menu[Q][25] = { "Input","Output","Bubble sort","Shaker sort","Quick sort","Selection sort","Shell sort","Merge sort","Insertion sort (binary)","Insertion sort (linear)","Merge sort (down-top)","Exit" };
	char menu[Q][33] = { "����","�����","���������� ���������","��������� ����������","������� ����������","���������� �������","���������� �������� (����������)","���������� �������� (����������)","���������� ��������� (��������)","���������� ��������� (��������)","�����" };
	int k = 0, flag1 = 0;
	sorts_time sorts_arr[K] = { {0," ",0,0} };
	int s_time, e_time, count = 0;
	srand(time(0));//��������� �ר����� ��������������� �����
	create_r_arr(c_arr, N);//��������� ������ ���������� �������
	FILE* file;//�������� ����� � ������� ����� ��������� ���������� ���������
	fopen_s(&file, "sorts_time.csv", "w");// ��������� ���� ��� ������
	if (file != NULL) {
		while (k != 11) {
			k = choice(menu, Q);
			switch (k)
			{
			case 0:
				c_arr = input(c_arr, &n);
				free(arr);
				arr = (int *)malloc(n * sizeof(c_arr[0]));
				copy_arr(c_arr, arr, n);
				break;

			case 1:
				//printf("Default array :\n");
				printf("�������� ������ :\n");
				print_arr(c_arr, NUM);
				printf("\n\n");
				//fprintf(file, "\sep=, \n");
				if (flag1) {
					for (int i = count; i < K; i++) {
						fprintf(file, "%d,%s,%d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						//printf("Sorted array :\n");
						printf("��������������� ������ :\n");
						print_arr(sorts_arr[i].sorted_arr, NUM);
						printf("\n\n");
					}
				}
				for (int i = 0; i < count; i++) {
					fprintf(file, "%d,%s, %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					//printf("Sorted array :\n");
					printf("��������������� ������ :\n");
					print_arr(sorts_arr[i].sorted_arr, NUM);
					printf("\n\n");
					}
				break;

			case 2:
				copy_arr(c_arr, arr, n);//����������� ��-��� �� ��������� ������� � "�������������" ������
				s_time = clock();//����� ������ ��������� �� ����������
				bubble_sort(arr, n);//����� ����������
				e_time = clock();//����� ������ ��������� ����� ����������
				sorts_arr[count] = { e_time - s_time,"���������� ���������",n };//������ �����������
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 3:
				copy_arr(c_arr, arr, n);
				s_time = clock();
				shaker_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"��������� ����������",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 4:
				copy_arr(c_arr, arr, n);
				s_time = clock();
				quick_sort(arr, 0, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"������� ����������",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 5:
				copy_arr(c_arr, arr, n);
				s_time = clock();
				selection_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"���������� �������",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
/*
			case 6:
				copy_arr(c_arr, arr, n);
				s_time = clock();
				shaker_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"Shell sort",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
*/
			case 6:
				copy_arr(c_arr, arr, n);
				s_time = clock();
				merge_sort(arr, 0, n - 1);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"���������� �������� (����������)",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
			
			case 7:
				copy_arr(c_arr, arr, n);
				s_time = clock();
				merge_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"���������� �������� (����������)",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 8:
				copy_arr(c_arr, arr, n);
				s_time = clock();
				insertion_sort(n, arr);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"���������� ��������� (��������)",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 9:
				copy_arr(c_arr, arr, n);
				s_time = clock();
				insertion_sort(arr, n);
				e_time = clock();
				sorts_arr[count] = { e_time - s_time,"���������� ��������� (��������)",n };
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
			}

			if (count == K) { 
				count = 0; //����� �������� ��� ������������ ���������� �����������
				flag1 = 1;
			}
		}

	free(c_arr);//����������� ������ �� ��������
	free(arr);
	fclose(file);//��������� ����
	}
	return 0;
}

