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
void Merge(int*& R, int low, int high);
void Msort(int*& R, int low, int high, int level, int& count);
int Sort[10][16];

void InitSqLIst(SqList& L, unsigned int lenth) {
	if (lenth == 0)lenth = MAXSIZE;
	L.lenth = lenth;
	L.R = new int[L.lenth + 1];
}
void CreateSqList(SqList& L) {
	int lenth = 0;
	int key, i = 1;
	cout << "���������Ա�ĳ��� :";
	cin >> lenth;
	InitSqLIst(L, lenth);
	cout << "������ؼ�ֵ :" << endl;
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
		cout << "���Ա�����" << endl;
	return;
	cout << "���Ա�ĳ���Ϊ ��" << L.lenth << endl;
	for (int i = 1; i <= L.lenth; i++)
		cout << L.R[i] << ' ';
	cout << endl;
}
void menu4() {//2-·�鲢����
	//int* R = new int[17];
	SqList L;
	int level = 1, count = 0;
	CreateSqList(L);
	Msort(L.R, 1, L.lenth, level, count);
	PrintSqList(L);
	cout << "2-·�鲢���������Ϊ ��" << count << endl;
	for (int k = count; k > 0; k--) {
		cout << "��" << count - k + 1 << "�� ��";
		for (int j = 1; j <= L.lenth; j++) {
			cout << Sort[k][j] << ' ';
		}
		cout << endl;
	}
	DestorySqList(L);
}
void Merge(int*& R, int low, int high) {
	int* TR = new int[high - low + 1];//TR�ķ���ռ�
	int mid = (high + low) / 2;
	int i, j, low1;
	for (i = 0, low1 = low, j = mid + 1; low1 <= mid && j <= high; i++) {
		if (R[low1] < R[j])TR[i] = R[low1++];
		else TR[i] = R[j++];
	}
	while (low1 <= mid)TR[i++] = R[low1++];
	while (j <= high)TR[i++] = R[j++];//i��ֵ����high��һ
	while (low <= high) {
		R[high--] = TR[--i];
	}
	//delete []TR;
}
void Msort(int*& R, int low, int high, int level, int& count) {
	if (low < high) {
		int center = (low + high) / 2;
		if (level > count)count = level;
		Msort(R, low, center, level + 1, count);
		Msort(R, center + 1, high, level + 1, count);
		Merge(R, low, high);
		for (int i = low; i <= high; i++) {
			Sort[level][i] = R[i];
			//��ÿһ�˵���������¼������ע�⣡����������Ϊ����ʱ�����һ���ؼ�ֵ�����¼�ڵ�һ����
		}
	}
	if (low == high)Sort[level][high] = R[high];
	//������Ϊ����ʱ�������һ�������Ĺؼ�ֵ��¼�ڵ�һ����
}
//19 38 12 40 41 39 54 76 35 47 80 14 9 44 19
int mian() {
	menu4();
	return 0;
}