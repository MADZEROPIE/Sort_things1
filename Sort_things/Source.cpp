#include "stdafx.h"
#include "sorts1.h"
#include <stdlib.h>
#include <time.h>
//#include "sorts1.h"
#define Q 11


int choice(char menu[Q][25], int n) {
	int k = -1, i;
	for (i = 0; i < n; i++)
		printf("%s (%d)\n", menu[i], i);
	while (k < 0 || k>10) {
		printf("Please choose wisely: ");
		scanf_s("%d", &k);
	}
	return k;
}


/*
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap(int a[], int x, int y) {
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

struct sorts_time
{
	int time_sort;
	char name[30];
};*/

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
/*
int choice(char menu[Q][25],int n) {
	int k=-1,i;
	for (i = 0; i < n; i++)
		printf("%s (%d)\n", menu[i],i);
        while (k < 0 || k>10) {
		printf("Please choose wisely: ");
		scanf_s("%d", &k);
	}
	return k;	
}*/

int input(int arr[], int len) {
	int i;
	printf("Press 0 for default settings or any other number for choose new settings ");
	scanf_s("%d", &i);
	if (i == 0)
		return len;
	len = -1;
	while (len < 0 || len>7777777) {
		printf("Enter number of elements: ");
		scanf_s("%d", &len);
	}
	//arr = (int *)realloc(arr, n*sizeof(int));
	arr = (int *)malloc(len*sizeof(int));
	printf("Press 0 if you wanna create random array or any other number if you wanna enter it mannualy ");
	scanf_s("%d", &i);
	if (i == 0)
		create_r_arr(arr, len);
	else
		for (int j = 0; j < len;j++)
			scanf_s("%d", &arr[j]);
	return len;
	
}

void create_r_arr(int arr[], int n) {
	for (int i = 0; i < n; i++)
		arr[i] = rand();
}

void print_arr(int arr[], int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

void bubble_sort(int arr[], int n) {
	int flag = 1, i;
	while (flag) {
		for (i = 0, flag = 0; i<n - 1; i++)
			if (arr[i] > arr[i + 1]) {
				flag = 1;
				swap(arr[i], arr[i + 1]);
			}
		n--;
	}
}

/*
void stone_sort(int arr[], int n) {
	int flag = 1, i, k = 0;
	while (flag) {
		for (i = n - 1, flag = 0; i > k; i--)
			if (arr[i] < arr[i - 1]) {
				flag = 1;
				swap(arr, i, i - 1);
			}
		k++;
	}
}*/

void shaker_sort(int arr[], int len) {
	int i, j, flag = 1;
	for (i = 0; i < len / 2; i++) {
		flag = 0;
		for (j = i; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		for (j = len - 2 - i; j > i; j--)
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				flag = 1;
			}
		if (!flag)
			break;
	}
}

/*
void insertion_sort(int arr[], int len) {
	int i, j;
	for (i = 0; i < len; i++) {
		j = i;
		for (; j > 0 && arr[j] < arr[j - 1]; j--)
			swap(arr, j - 1, j);
	}
}
*/
void quick_sort(int arr[], int left, int right) {
	if (left < right) {
		int k = left;
		for (int i = left + 1; i < right; i++)
			if (arr[i] < arr[left])
				swap(arr[i], arr[++k]);
		swap(arr[left], arr[k]);
		quick_sort(arr, left, k);
		quick_sort(arr, k + 1, right);
	}
}

void selection_sort(int arr[], int len) {
	int k = 0, flag = 1;
	for (int i = 0; i < len && (flag); i++) {
		for (int j = k = i, flag = 0; j < len; j++)
			if (arr[j] < arr[k]) {
				k = j;
				flag = 1;
			}
		swap(arr[i], arr[k]);
	}
}

void shell_sort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}

void copy_arr(int c_arr[], int t_arr[], int n) {
	for (int i = 0; i < n; i++)
		t_arr[i] = c_arr[i];
}

void merge(int arr[], int l, int mid, int r) {
	int n2 = r - mid;
	int n1 = mid - l + 1;
	int *t_arr_1 = (int *)malloc(n1 * sizeof(arr[0]));
	int *t_arr_2 = (int *)malloc(n2 * sizeof(arr[0]));
	for (int i = 0; i < n1; i++)
		t_arr_1[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		t_arr_2[j] = arr[j + mid + 1];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (t_arr_1[i] <= t_arr_2[j])
			arr[k] = t_arr_1[i++];
		else
			arr[k] = t_arr_2[j++];
		k++;
	}
	while (i < n1) {
		arr[k] = t_arr_1[i];
		k++; i++;
	}
	while (j < n2) {
		arr[k] = t_arr_2[j];
		k++; j++;
	}
	free(t_arr_1);
	free(t_arr_2);
}

void merge_sort(int arr[], int left, int right) {
	if (left < right) {
		int m = left + (right - left) / 2;
		merge_sort(arr, left, m);
		merge_sort(arr, m + 1, right);
		merge(arr, left, m, right);
	}
}

void shift(int arr[], int s, int k) {
	for (int i = k; i > s; i--)
		arr[i] = arr[i - 1];
}

int lin_search(int arr[], int k) {
	int i = 0;
	while (arr[i] < arr[k])
		i++;
	return i;
}

int bin_search(int arr[], int k) {
	int mid, left = 0, right = k - 1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[k] <= arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

void insertion_sort(int arr[], int len) {
	int k, s, r;
	for (k = 1; k < len; k++) {
		r = arr[k];
		s = bin_search(arr, k);
		shift(arr, s, k);
		arr[s] = r;
	}
}

void insertion_sort(int len,int arr[]) {
	int k, s, r;
	for (k = 1; k < len; k++) {
		r = arr[k];
		s = lin_search(arr, k);
		shift(arr, s, k);
		arr[s] = r;
	}
}

/*
void heap(int a[], int i, int n) {
	int max = i;
	while (true) {
		int child = 2 * i + 1;
		if (child < n && a[max] < a[child])
			max = child;
		child++;
		if (child < n && a[max] < a[child])
			max = child;
		if (max == i)
			break;
		else {
			swap(a, max, i);
			i = max;
		}
	}
}

void heap_sort(int a[], int n) {
	for (int i = n / 2; i >= 0; i--)
		heap(a, i, n);
	for (int i = n - 1; i > 0; i--) {
		swap(a, 0, i);
		heap(a, 0, i);

	}
}

int get_max(int a[], int n) {
	int m = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > m)
			m = a[i];
	return m;
}

void count_sort(int a[], int n, int num) {
	int *temp_arr = (int *)malloc(n*sizeof(a[0]));
	int i;
	int count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(a[i] / num) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		temp_arr[count[(a[i] / num) % 10] - 1] = a[i];
		count[(a[i] / num) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = temp_arr[i];
}

void radix_sort(int a[], int n) {
	int m = get_max(a, n);
	for (int num = 1; m / num > 0; num *= 10)
		count_sort(a, n, num);
}
*/

void iter_merge(int* a,int *b,int *c,int na,int nb) {
	int i=0,j=0,k=0;
	while (i < na && j < nb) {
		if (a[i] <= b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while (i < na) 
		c[k++] = a[i++];

	while (j < nb) 
		c[k++] = b[j++];

}

void merge_sort(int *arr, int n) {
	int* t_arr = (int*)malloc(n*sizeof(int));
	int *src=arr, *dst=t_arr;
	int len = 1;
	int len2;
	for (; len < n; len * 2) {
		int i=0;
		for (len2=len; i < n-len;i++){
			if (i+len2+len>n)
				len2=n-len-i;
			iter_merge(src+i,src+i+len,dst+i,len,len2);
		}
		if(i<n)
			copy_arr(src+i,dst+i,n-i);
		int *tmp=src;src=dst;dst=tmp;
	}
	if (src!=t_arr)
		copy_arr(t_arr,arr,n);
	free(t_arr);
}