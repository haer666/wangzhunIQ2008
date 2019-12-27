#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
#define ture '1'
#define INFINIY 200000000//最大权值
#define MAX_VERTEX_NUM 20//最大顶点个数
#define MAXSIZE 30
//·················队列···················
typedef struct {
	char* base;
	int head;
	int rear;
	int queuesize;
}squeue;//定义队列结构
bool Initqueue(squeue& Q, int maxsize);//初始化队列
bool Fullqueue(squeue Q);//判断队满
bool Emptyqueue(squeue Q);//判断队空
void INqueue(squeue& Q, char e);//入队
bool Outqueue(squeue& Q, char& e);//出队
bool Distory_Queue(squeue& Q);//销毁队列

typedef enum{DG=1,DN,AG,AN}Graph_Kind;//图的类型（有向图，有向网，无向图，无向网）
//----------------------------------邻接矩阵-----------------------------------------
typedef struct ArcCell {
	int weight;//边的权值对无权图0表示边不存在，1表示存在；对有全图表示权重
	char* info;//边的其他相关信息
}DEFINE_ARC;
typedef struct {
	char *vexs;//顶点信息
	DEFINE_ARC** arcs;//表示顶点之间关系（边）的指针；
	int vexnum, arcnum;//图的点数和边数
	Graph_Kind kind;//图的类型
}M_GRAPH;
void Dijkstra(M_GRAPH G, char start);
//----------------------------------邻接表-------------------------------------------
typedef struct ARC_NODE {
	//边结点的结构
	int index;//终点坐标
	char endvex;//该边的终点
	struct ARC_NODE* nextarc;//指向下一条边的指针
	int weight;//权重
	char* info;//边的其他相关信息
}ARC_NODE;

typedef struct VEX_NODE {
	//顶点的结构
	char vex;//顶点信息
	ARC_NODE* firstarc;//指向第一条以该顶点为起点的边
}VEX_NODE,*VEX_LIST;

typedef struct {
	VEX_LIST varray;//顶点数组
	int vexnum, arcnum;//顶点数，边数
	Graph_Kind kind;//图的类型
}AL_GRAPH;


void CREATE_GRAPH_ADJACENT_MATRIX(M_GRAPH& graph); //创建图（邻接矩阵）的菜单函数
void CREATE(M_GRAPH& graph);
int Locate_Vex(M_GRAPH graph, char v);
int Found_Vex(M_GRAPH graph, char v);
void DFS_TRAVER_M(M_GRAPH graph, char v);
void DFS_M_GRAPH(M_GRAPH graph);
void PRINT_M_GRAPH(M_GRAPH graph);//打印图的邻接矩阵
void menu1();


void CREATE_GRAPH_ADJACENT_TABLE(AL_GRAPH& graph);////创建图（邻接表）的菜单函数
int Locate_Vex(AL_GRAPH G, char v);
void CREATE_Table(AL_GRAPH& G);//邻接表创建加权有向图
void Insert_Arc(AL_GRAPH& G, char start, char endvex, int weight);
//根据图的类型，以及起点，终点插入边
void PRINT_AL_GRAPH(AL_GRAPH G);//打印图的邻接表
void menu2();