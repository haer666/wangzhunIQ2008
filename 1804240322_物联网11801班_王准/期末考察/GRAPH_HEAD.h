#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
#define ture '1'
#define INFINIY 200000000//���Ȩֵ
#define MAX_VERTEX_NUM 20//��󶥵����
#define MAXSIZE 30
//�������������������������������������С�������������������������������������
typedef struct {
	char* base;
	int head;
	int rear;
	int queuesize;
}squeue;//������нṹ
bool Initqueue(squeue& Q, int maxsize);//��ʼ������
bool Fullqueue(squeue Q);//�ж϶���
bool Emptyqueue(squeue Q);//�ж϶ӿ�
void INqueue(squeue& Q, char e);//���
bool Outqueue(squeue& Q, char& e);//����
bool Distory_Queue(squeue& Q);//���ٶ���

typedef enum{DG=1,DN,AG,AN}Graph_Kind;//ͼ�����ͣ�����ͼ��������������ͼ����������
//----------------------------------�ڽӾ���-----------------------------------------
typedef struct ArcCell {
	int weight;//�ߵ�Ȩֵ����Ȩͼ0��ʾ�߲����ڣ�1��ʾ���ڣ�����ȫͼ��ʾȨ��
	char* info;//�ߵ����������Ϣ
}DEFINE_ARC;
typedef struct {
	char *vexs;//������Ϣ
	DEFINE_ARC** arcs;//��ʾ����֮���ϵ���ߣ���ָ�룻
	int vexnum, arcnum;//ͼ�ĵ����ͱ���
	Graph_Kind kind;//ͼ������
}M_GRAPH;
void Dijkstra(M_GRAPH G, char start);
//----------------------------------�ڽӱ�-------------------------------------------
typedef struct ARC_NODE {
	//�߽��Ľṹ
	int index;//�յ�����
	char endvex;//�ñߵ��յ�
	struct ARC_NODE* nextarc;//ָ����һ���ߵ�ָ��
	int weight;//Ȩ��
	char* info;//�ߵ����������Ϣ
}ARC_NODE;

typedef struct VEX_NODE {
	//����Ľṹ
	char vex;//������Ϣ
	ARC_NODE* firstarc;//ָ���һ���Ըö���Ϊ���ı�
}VEX_NODE,*VEX_LIST;

typedef struct {
	VEX_LIST varray;//��������
	int vexnum, arcnum;//������������
	Graph_Kind kind;//ͼ������
}AL_GRAPH;


void CREATE_GRAPH_ADJACENT_MATRIX(M_GRAPH& graph); //����ͼ���ڽӾ��󣩵Ĳ˵�����
void CREATE(M_GRAPH& graph);
int Locate_Vex(M_GRAPH graph, char v);
int Found_Vex(M_GRAPH graph, char v);
void DFS_TRAVER_M(M_GRAPH graph, char v);
void DFS_M_GRAPH(M_GRAPH graph);
void PRINT_M_GRAPH(M_GRAPH graph);//��ӡͼ���ڽӾ���
void menu1();


void CREATE_GRAPH_ADJACENT_TABLE(AL_GRAPH& graph);////����ͼ���ڽӱ��Ĳ˵�����
int Locate_Vex(AL_GRAPH G, char v);
void CREATE_Table(AL_GRAPH& G);//�ڽӱ�����Ȩ����ͼ
void Insert_Arc(AL_GRAPH& G, char start, char endvex, int weight);
//����ͼ�����ͣ��Լ���㣬�յ�����
void PRINT_AL_GRAPH(AL_GRAPH G);//��ӡͼ���ڽӱ�
void menu2();