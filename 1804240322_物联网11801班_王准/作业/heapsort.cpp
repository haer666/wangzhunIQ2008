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
void HeapAdjust(SqList& L, int s, int m);
void HeapSort(SqList& L, int**& ALL);
void InitBin(int**& ALL, int size);
void swap(int& a, int& b);
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

void InitBin(int**& ALL, int size) {
	ALL = new int* [size - 1];
	for (int i = 0; i < size - 1; i++) {
		ALL[i] = new int[size];
		for (int j = 0; j < size; j++) {
			ALL[i][j] = 0;
		}
	}
}
void menu3() {//堆排序
	SqList L;
	int** ALL;
	CreateSqList(L);
	InitBin(ALL, L.lenth);
	HeapSort(L, ALL);
	PrintSqList(L);
	cout << "堆排序的趟数为 ：" << L.lenth - 1 << endl;
	for (int i = 0; i < L.lenth - 1; i++) {
		cout << "第" << i + 1 << "趟 ：";
		for (int j = 0; j < L.lenth; j++)
			cout << ALL[i][j] << ' ';
		cout << endl;
	}
	DestorySqList(L);
	//DestoryBin(ALL);//why？？？
}
void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
}
void HeapAdjust(SqList& L, int s, int m) {
	int j = 0;
	L.R[0] = L.R[s];
	for (j = 2 * s; j <= m; j *= 2) {
		if (j < m&& L.R[j] < L.R[j + 1])j++;
		if (L.R[0] > L.R[j])break;
		L.R[s] = L.R[j];
		s = j;
	}
	L.R[s] = L.R[0];
}
void HeapSort(SqList& L, int**& ALL) {
	for (int i = L.lenth / 2; i > 0; i--) {
		HeapAdjust(L, i, L.lenth);
	}
	swap(L.R[1], L.R[L.lenth]);
	for (int i = 0; i < 15; i++) {
		ALL[0][i] = L.R[i + 1];
	}
	for (int i = L.lenth - 1; i > 1; i--) {
		HeapAdjust(L, 1, i);
		swap(L.R[1], L.R[i]);
		for (int j = 15 - i; j < 14; j++)
			ALL[j][i];
		for (int j = 0; j < 15; j++) {
			ALL[L.lenth - i][j] = L.R[j + 1];
		}
	}
}
int main() {
	menu3();
	return 1;
}
