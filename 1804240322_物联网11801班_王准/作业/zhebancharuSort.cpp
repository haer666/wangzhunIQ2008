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
void InitBin(int**& ALL, int size);
void DestoryBin(int**& ALL);
void Binsort(int*& R, int**& ALL);
void menu2() {//’€∞Î≤Â»Î≈≈–Ú
	SqList L;
	CreateSqList(L);
	int** ALL = NULL;
	InitBin(ALL, L.lenth);
	Binsort(L.R, ALL);
	PrintSqList(L);
	cout << "’€∞Î≤Â»Î≈≈–ÚµƒÃÀ ˝Œ™ £∫" << L.lenth - 1 << endl;
	for (int i = 0; i < L.lenth - 1; i++) {
		cout << "µ⁄" << i + 1 << "ÃÀ £∫";
		for (int j = 0; j < L.lenth; j++)
			cout << ALL[i][j] << ' ';
		cout << endl;
	}
	//DestoryBin(ALL);
	DestorySqList(L);
}
void Binsort(int*& R, int**& ALL) {//’€∞Î≤Â»Î≈≈–Ú
	int low, high, mid;
	for (int i = 2, k = 0; i < 16; i++, k++) {
		R[0] = R[i];
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (R[mid] < R[0])low = mid + 1;
			else high = mid - 1;
		}
		for (int j = i - 1; j >= low; j--) {
			R[j + 1] = R[j];
		}
		R[low] = R[0];
		for (int a = 0; a < 15; a++) {
			ALL[k][a] = R[a + 1];
		}
	}
}
void DestoryBin(int**& ALL) {
	int i = 0;
	while (ALL[i]) {
		delete ALL[i];
		i++;
	}
	delete ALL;
}
int main() {
	menu2();
	return 0;
}