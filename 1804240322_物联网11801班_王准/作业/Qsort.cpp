#pragma once
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef struct {
	int lenth;
	int* R;
}SqList;

void InitSqLIst(SqList& L, unsigned int lenth);
void CreateSqList(SqList& L);
void DestorySqList(SqList& L);
void PrintSqList(SqList L);
int Partition(int*& R, int low, int high);
void Qsort(int*& R, int low, int high, int level, int& count);
int Sort[10][16];
void InitSqLIst(SqList& L, unsigned int lenth) {
	if (lenth == 0)lenth = MAXSIZE;
	L.lenth = lenth;
	L.R = new int[L.lenth + 1];
}
void CreateSqList(SqList& L) {
	int lenth = 0;
	int key, i = 1;
	cout << "请输入线性表的长度 :";
	cin >> lenth;
	InitSqLIst(L, lenth);
	cout << "请输入关键值 :" << endl;
	for (i; i <= L.lenth; i++) {
		cin >> key;
		L.R[i] = key;
	}
}
void DestorySqList(SqList& L) {
	L.lenth = 0;
	if (!L.R)return;
	delete L.R;
}
void PrintSqList(SqList L) {
	if (!L.R)
		cout << "线性表不存在" << endl;
	return;
	cout << "线性表的长度为 ：" << L.lenth << endl;
	for (int i = 1; i <= L.lenth; i++)
		cout << L.R[i] << ' ';
	cout << endl;
}
void menu1() {//快速排序
	//cout << Sort[0][0] << endl;
	SqList L;
	int level = 1, count = 0;
	CreateSqList(L);
	Qsort(L.R, 1, L.lenth, level, count);
	PrintSqList(L);
	cout << "快速排序的趟数为 ：" << count << endl;
	for (int i = 1; i < count; i++) {
		cout << "第" << i << "趟 ：";
		for (int j = 1; j <= L.lenth; j++)
		{
			if (Sort[i][j] == 0)Sort[i][j] = Sort[i - 1][j];
			cout << Sort[i][j] << ' ';
		}
		cout << endl;
	}
	DestorySqList(L);
}
int Partition(int*& R, int low, int high) {
	R[0] = R[low];
	int key = R[low];
	while (low < high)
	{
		while (low < high && R[high] >= key)
			high--;
		if (low < high)R[low++] = R[high];
		while (low < high && R[low] <= key)
			low++;
		if (low < high)R[high--] = R[low];
	}
	R[low] = R[0];
	return low;
}
void Qsort(int*& R, int low, int high, int level, int& count) {
	if (low < high)
	{
		int num = Partition(R, low, high);
		if (level > count)count = level;
		for (int i = low; i <= high; i++) {
			Sort[level][i] = R[i];
		}
		Qsort(R, low, num - 1, level + 1, count);
		Qsort(R, num + 1, high, level + 1, count);
	}
}
int main() {
	menu1();
	return 1;
}
