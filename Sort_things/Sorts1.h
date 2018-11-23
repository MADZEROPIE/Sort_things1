#pragma once

int bin_search(int arr[], int k);
int lin_search(int arr[], int k);
void shift(int arr[], int s, int k);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int l, int mid, int r);
void copy_arr(int c_arr[], int t_arr[], int n);
//void shell_sort(int arr[], int n);
void selection_sort(int arr[], int len);
void quick_sort(int arr[], int left, int right);
void insertion_sort(int arr[], int len);
void insertion_sort(int len, int arr[]);
void shaker_sort(int arr[], int len);
void bubble_sort(int arr[], int n);
void print_arr(int arr[], int len);
void swap(int &a, int &b);
int choice(char menu[][33], int n);
int *input(int *arr, int *len);
void create_r_arr(int arr[], int n);
void merge_sort(int *arr, int n);