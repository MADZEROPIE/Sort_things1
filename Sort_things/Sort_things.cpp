#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "sorts1.h"
#include <string.h>
#include <locale.h>
//#include "source.cpp"



#define N 10000
#define K 12
#define Q 12
#define NUM 20

struct sorts_time
{
	int time_sort;
	char name[30];
	int num;
};
/*
int choice(char menu[][Q],int n) {
	int k=-1,i;
	for (i = 0; i < n; i++)
		printf("%s (%d)\n", menu[i],i);
        while (k < 0 || k>10) {
		printf("Please choose wisely: ");
		scanf_s("%d", &k);
	}
	return k;	
}

int input(int arr[], int len) {
	int i, n=-1;
	printf("Press 0 for default settings or any other number for choose new settings ");
	scanf_s("%d", &i);
	if (i == 0)
		return len;
	while (n < 0 || n>7777777) {
		printf("Enter number of elements");
		scanf_s("%d", &n);
	}
	arr = (int *)realloc(arr, n*sizeof(int));
	printf("Press 0 if you wanna create random array or any other number if you wanna enter it mannualy ");
	scanf_s("%d", &i);
	if (i == 0)
		create_r_arr(arr, n);
	else
		for (int j = 0; j < n;j++)
			scanf_s("%d", &arr[j]);
	return n;
	
}

void create_r_arr(int arr[], int n) {
	for (int i = 0; i < n; i++)
		arr[i] = rand();
}

*/

int c_arr[N];
//c_arr = (int*)malloc(N * sizeof(int));

int main()
{

    int n=N;
	int *arr=(int*)malloc(N*sizeof(int));    
    char menu[Q][25] = {"Input","Output","Bubble sort","Shaker sort","Quick sort","Selection sort","Shell sort","Merge sort","Insertion sort (binary)","Insertion sort (linear)","Merge sort (down-top)","Exit"};
	int k,flag=1,flag1=0;
	sorts_time sorts_arr[K] = { {0," ",0} };
    //int time_arr[Q];
    int s_time,e_time,count=0;
	srand(time(0));
	create_r_arr(c_arr, N);
    FILE* file;
    fopen_s(&file,"sorts_time.txt", "a");
   /* if (file != NULL) {
        fprintf(file, "\n%d \n", N);
        for (int i = 0; i < K; i++)
            fprintf(file, "%s \t\t %d\n", sorts_arr[i].name, sorts_arr[i].time_sort);
                }
*/
	while (flag) {
        k = choice(menu, 11);
		
		switch (k)
		{
		case 0:
			n = input(c_arr, N);
			free(arr);
			arr = (int *)malloc(n*sizeof(c_arr[0]));
			copy_arr(c_arr,arr,n);
			break;

        case 1:
                printf("Default array :\n");
                print_arr(c_arr,NUM);
                printf("\nSorted array :\n");
                print_arr(arr,NUM);
				printf("\n\n");
                if (file != NULL) {
                	fprintf(file, "\n%d \n", n);
                	if (flag1)
                		for (int i = count; i < K; i++){
                        	fprintf(file, "%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
                        	printf("%d\t%s\t %d \n",  sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);}
                    for (int i = 0; i < count; i++){
                        	fprintf(file, "%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);
                        	printf("%d\t%s\t %d \n", sorts_arr[i].num, sorts_arr[i].name, sorts_arr[i].time_sort);}

                    }
                 break;

        case 2:
			copy_arr(c_arr, arr, n);
                s_time=clock();
                bubble_sort(arr,n);
            	e_time=clock();
            	sorts_arr[count++]={e_time-s_time,"Bubble sort",n};
                break;

        case 3:
			copy_arr(c_arr, arr, n);
        	s_time=clock();
            shaker_sort(arr,n);
            e_time=clock();
            sorts_arr[count++]={e_time-s_time,"Shaker sort",n };
            break;

        case 4:
			copy_arr(c_arr, arr, n);
        	s_time=clock();
            quick_sort(arr,0,n);
            e_time=clock();
            sorts_arr[count++]={e_time-s_time,"Quick sort",n };
            break;

        case 5:
			copy_arr(c_arr, arr, n);
        	s_time=clock();
            selection_sort(arr,n);
            e_time=clock();
            sorts_arr[count++]={e_time-s_time,"Selection sort",n };
            break;

        case 6:
			copy_arr(c_arr, arr, n);
        	s_time=clock();
            shaker_sort(arr,n);
            e_time=clock();
            sorts_arr[count++]={e_time-s_time,"Shell sort",n };
            break;

        case 7:
			copy_arr(c_arr, arr, n);
        	s_time=clock();
            merge_sort(arr, 0,n-1);
            e_time=clock();
            sorts_arr[count++]={e_time-s_time,"Merge sort",n };
            break;

		case 8:
			copy_arr(c_arr, arr, n);
        	s_time=clock();
            insertion_sort(arr,n);
            e_time=clock();
            sorts_arr[count++]={e_time-s_time,"Insertion sort (binary)",n };
            break;

        case 9:
			copy_arr(c_arr, arr, n);
        	s_time=clock();
            insertion_sort(n,arr);
            e_time=clock();
            sorts_arr[count++]={e_time-s_time,"Insertion sort (linear)",n };
            break;

        case 10:
        	copy_arr(c_arr, arr, n);
        	s_time=clock();
			merge_sort(arr,n);
            e_time=clock();
            sorts_arr[count++]={e_time-s_time,"Merge sort (down-top)",n };
            break;

		default:
			flag = 0;
			break;
		}

		if (count==K){
			count=count % K;
			flag1=1;} 
		}

    fclose(file);
    return 0;
}

