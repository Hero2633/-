#pragma once
#include<stdio.h>
#include<stdlib.h>
void PrintfArr(int* nums, int len);
//1、插入排序
void InsertSort(int*nums,int len);//直接插入排序
void ShellSort(int* nums, int len);//希尔排序
//2、选择排序
void SelectSort(int* nums, int len);//选择排序
void HeapSort(int* nums, int len);//堆排序
//3、交换排序
void BubbleSort(int* nums, int len);//冒泡排序
void QuickSort(int* nums, int len);//快速排序
//4、归并排序
void MergeSort(int* nums, int len);//归并排序