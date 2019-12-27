
#include"GRAPH_HEAD.h"
void CREATE_GRAPH_ADJACENT_TABLE(AL_GRAPH& G) {
	//����ͼ(�ڽӱ�)�Ĳ˵�����
	cout << "- - - - - - - - - - - - - - - -adjacent table - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "������������1.directed graph" << endl;
	cout << "������������2.direct net " << endl;
	cout << "������������3.undirected graph " << endl;
	cout << "������������4.undirected net" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << endl << endl << "Enter the kind of graph :";
	int kind = 0;
	cin >> kind;
	switch (kind)
	{
	case 1:
		G.kind = DG;
		CREATE_Table(G);
		break;
	case 2:
		G.kind = DN;
		CREATE_Table(G);
		break;
	case 3:
		G.kind = AG;
		CREATE_Table(G);
		break;
	case 4:
		G.kind = AN;
		CREATE_Table(G);
		break;
	default:
		cout << "������������������������Please Enter the suitable choice !������������������������";
		break;
	}
}
int Locate_Vex(AL_GRAPH G, char v) {
	//��λ��ȷ���������
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (G.varray[i].vex == v)return i;
	}
	return -1;
}
void CREATE_Table(AL_GRAPH& G) {
	cout << "Please Enter the number of vertices and edges of the graph(separated by spaces) :" << endl;
	cin >> G.vexnum >> G.arcnum;
	G.varray = new VEX_NODE[G.vexnum];
	cout << "Please Enter each vertex in turn (separated by spaces) :" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.varray[i].vex;//���붥��
		G.varray[i].firstarc = NULL;
		//��ʼ������ͷָ��Ϊ��
	}
	char start, endvex;
	int weight = 1;
	if (G.kind == DN || G.kind == AN) {//��������������
		cout << "Please Enter the starting vertex, end vertex, and weight of the edge (separated by spaces) :" << endl;
		for (int i = 0; i < G.arcnum; i++) {
			cin >> start >> endvex >> weight;
			Insert_Arc(G, start, endvex, weight);
		}
	}
	else {//����ͼ������ͼ
		cout << "Please Enter the starting vertex and end vertex of the edge (separated by spaces) :" << endl;
		for (int i = 0; i < G.arcnum; i++) {
			cin >> start >> endvex;
			Insert_Arc(G, start, endvex, weight);
		}
	}

}
void Insert_Arc(AL_GRAPH& G, char start, char endvex, int weight) {
	//�����
	ARC_NODE* pi = new ARC_NODE;
	if (!pi)exit(-1);
	int i = Locate_Vex(G, start);
	int j = Locate_Vex(G, endvex);
	pi->endvex = endvex;
	pi->index = j;
	pi->weight = weight;
	pi->info = NULL;
	pi->nextarc = NULL;
	//Ϊpi��ֵ
	pi->nextarc = G.varray[i].firstarc;
	G.varray[i].firstarc = pi;
	if (G.kind == AN || G.kind == AG) {
		ARC_NODE* pj = new ARC_NODE;
		if (!pj)exit(-1);
		pj->endvex = start;
		pj->index = i;
		pj->weight = weight;
		pj->info = NULL;
		pj->nextarc = NULL;
		pj->nextarc = G.varray[j].firstarc;
		G.varray[j].firstarc = pj;
	}
}
void PRINT_AL_GRAPH(AL_GRAPH G) {
	//��ӡͼ���ڽӱ�
	cout << "������������������������������the adjacent table of the graph is :";
	cout << endl << endl << "\t\t\t" << "index" << "\t" << "start vex" << "\t\0\0" << "end vex" << endl;
	ARC_NODE* p;
	for (int i = 0; i < G.vexnum; i++) {
		p = G.varray[i].firstarc;
		cout << "\t\t\t\0" << i << "           ";
		cout << G.varray[i].vex<< "----------->>";
		while (p)
		{
			if (G.kind == DN || G.kind == AN) {
				cout << p->endvex << '(' << p->weight << ')' << "-->";
			}
			else cout << p->endvex << "  ";
			p = p->nextarc;
		}
		cout << endl;
	}
}
bool* visited2;

void DFS_AL(AL_GRAPH G,char v) {
	//�Ӷ���v�����ݹ�ض�ͼG���������������
	int i = Locate_Vex(G, v);
	cout << v <<"  ";//v��Ϊ���
	visited2[i] = 1;//���Ϊ�ѷ���
	for ( ARC_NODE* p = G.varray[i].firstarc; p; p = p->nextarc) {
		//pΪָ���Զ���vΪ���ıߵ�ָ�룬
		if (!visited2[p->index])DFS_AL(G, p->endvex);
	
	}

}

void DFS_TRAVER_AL(AL_GRAPH G) {
	//�����ڽӱ��ʾ��ͼG������ȱ���
	visited2 = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++) {
		visited2[i] = 0;
	}
	char v;
	cout << endl << endl << "Pleaae Enter the strat vex for depth-first traversing :";
	cin >> v;
	cout << endl << endl << "������the order of depth-first traversing is :" << endl;
	cout << "\t\t\t";
	DFS_AL(G, v);
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited2[i])DFS_AL(G, G.varray->vex);
	}//����ͼG���붥��v����ͨ�Ķ���
}

void menu2() {
	AL_GRAPH G;
	CREATE_GRAPH_ADJACENT_TABLE(G);
	//G.kind = DG;
	//CREATE_Table(G);
	PRINT_AL_GRAPH(G);
	DFS_TRAVER_AL(G);

}
