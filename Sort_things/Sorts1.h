#define Q 11
#pragma once

//void radix_sort(int a[], int n);
//void count_sort(int a[], int n, int num);
//int get_max(int a[], int n);
//void heap_sort(int a[], int n);
//void heap(int a[], int i, int n);
//void insertion_sort(int arr[], int len, int flag);
int bin_search(int arr[], int k);
int lin_search(int arr[], int k);
void shift(int arr[], int s, int k);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int l, int mid, int r);
void copy_arr(int c_arr[], int t_arr[], int n);
void shell_sort(int arr[], int n);
void selection_sort(int arr[], int len);
void quick_sort(int arr[], int left, int right);
void insertion_sort(int arr[], int len);
void insertion_sort( int len,int arr[]);
void shaker_sort(int arr[], int len);
//void stone_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void print_arr(int arr[], int len);
//void swap(int a[], int x, int y);
//void swap(int *a, int *b);
void swap(int &a, int &b);
int choice(char menu[][25],int n);
int input(int arr[], int len);
void create_r_arr(int arr[], int n);
void merge_sort(int *arr, int n);