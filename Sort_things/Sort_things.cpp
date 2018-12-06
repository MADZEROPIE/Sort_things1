#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "sorts1.h"


#define N 20000 //���������� ��������� �������(�� ���������)
#define K 10 // ���������� ����������� ���������� ����������� � ������
#define Q 11 // ���������� ������� ����
#define NUM 20 //���������� ��������� ������� ����������� �� �����

typedef struct //��������� ������ ��� �������� ����������� ����������
{
	int time_sort; //����� ����������
	char *name; //��������� �� ������ ������ � ��������� ����������
	int num;//���������� ���������
	int sorted_arr[NUM]; //�������� ���������������� �������
} sorts_time;

const int NotUsed = system("color F0");//������ ����� ������� (F - BRIGHT WHITE BACKGROUD, 0 - BLACK TEXT)

int main()
{
	setlocale(LC_CTYPE, "Russian");//�����������
	int n = N;//���������� ��������� ������� (����������)
	int *C_ARR = (int*)malloc(N * sizeof(int));//�������� ������������� ������� (������ �� ���������)
	int *arr = (int*)malloc(N * sizeof(int));//�������� ������������� ������� (������ ��� ����������)
	char menu[Q][33] = { "����","�����","���������� ���������","��������� ����������","������� ����������","���������� �������","���������� �������� (����������)",
		"���������� �������� (����������)","���������� ��������� (��������)","���������� ��������� (��������)","�����" };
	int k = 0, flag1 = 0;
	sorts_time sorts_arr[K] = { {0," ",0,0} };
	int s_time, e_time, count = 0;
	srand(time(0));//��������� �ר����� ��������������� �����
	create_r_arr(C_ARR, N);//��������� ������ ���������� �������
	FILE* file;//�������� ����� � ������� ����� ��������� ���������� ���������
	fopen_s(&file, "sorts_time.csv", "w");// ��������� ���� ��� ������
	if (file != NULL) {
		while (k != 10) {
			k = choice(menu, Q);
			switch (k)
			{
			case 0:
				C_ARR = input(C_ARR, &n);
				free(arr);//����������� ������
				arr = (int *)malloc(n * sizeof(C_ARR[0]));//������� ������ ������ �������
				break;

			case 1:
				printf("�������� ������ :\n");
				print_arr(C_ARR, NUM);
				printf("\n\n");
				fprintf(file, "\sep=,\n���������� ���������,�������� ����������,�����\n");
				if (flag1) {
					for (int i = count; i < K; i++) {
						fprintf(file, "%d,%s,%d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
						printf("��������������� ������ :\n");
						print_arr(sorts_arr[i].sorted_arr, NUM);
						printf("\n\n");
					}
				}
				for (int i = 0; i < count; i++) {
					fprintf(file, "%d,%s, %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
					printf("��������������� ������ :\n");
					print_arr(sorts_arr[i].sorted_arr, NUM);
					printf("\n\n");
					}
				break;

			case 2:
				copy_arr(C_ARR, arr, n);//����������� ��-��� �� ��������� ������� � "�������������" ������
				s_time = clock();//����� ������ ��������� �� ����������
				bubble_sort(arr, n);//����� ����������
				e_time = clock();//����� ������ ��������� ����� ����������
				sorts_arr[count].time_sort =  e_time - s_time;//������ �����������
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 3:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				shaker_sort(arr, n);
				e_time = clock();
				sorts_arr[count].time_sort = e_time - s_time;//������ �����������
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 4:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				quick_sort(arr, 0, n);
				e_time = clock();
				sorts_arr[count].time_sort = e_time - s_time;//������ �����������
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 5:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				selection_sort(arr, n);
				e_time = clock();
				sorts_arr[count].time_sort = e_time - s_time;//������ �����������
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 6:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				merge_sort(arr, 0, n - 1);
				e_time = clock();
				sorts_arr[count].time_sort = e_time - s_time;//������ �����������
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
			
			case 7:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				it_merge_sort(arr, n);
				e_time = clock();
				sorts_arr[count].time_sort = e_time - s_time;//������ �����������
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 8:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				lin_insertion_sort(n, arr);
				e_time = clock();
				sorts_arr[count].time_sort = e_time - s_time;//������ �����������
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;

			case 9:
				copy_arr(C_ARR, arr, n);
				s_time = clock();
				bin_insertion_sort(arr, n);
				e_time = clock();
				sorts_arr[count].time_sort = e_time - s_time;//������ �����������
				sorts_arr[count].name = menu[k];
				sorts_arr[count].num = n;
				copy_arr(arr, sorts_arr[count++].sorted_arr, NUM);
				break;
			}

			if (count == K) { 
				count = 0; //����� �������� ��� ������������ ���������� �����������
				flag1 = 1;
			}
		}
	fclose(file);//��������� ����
	}
	free(C_ARR);//����������� ������ �� ��������
	free(arr);
	return 0;
}

