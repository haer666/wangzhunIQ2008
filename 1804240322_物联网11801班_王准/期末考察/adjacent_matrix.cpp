#include"GRAPH_HEAD.h"
bool* visited;//存储顶点的访问状态
void CREATE_GRAPH_ADJACENT_MATRIX(M_GRAPH& graph ) {
	//创建图(邻接矩阵)的菜单函数
	cout << "- - - - - - - - - - - - - - - -adjacent matrix - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "······1.directed graph" << endl;
	cout << "······2.direct net " << endl;
	cout << "······3.undirected graph " << endl;
	cout << "······4.undirected net" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << endl << endl << "Enter the kind of graph :";
	int kind = 0;
	cin >> kind;
	switch (kind)
	{
	case 1:
		graph.kind = DG;
		CREATE(graph);
		break;
	case 2:
		graph.kind = DN;
		CREATE(graph);
		break;
	case 3:
		graph.kind = AG;
		CREATE(graph);
		break;
	case 4:
		graph.kind = AG;
		CREATE(graph);
		break;
	default:
		cout << "············Please Enter the suitable choice !············";
		break;
	}
}
void CREATE(M_GRAPH& graph) {
	cout << "Please Enter the number of vertices and edges of the graph(separated by spaces) : ";
	cin >> graph.vexnum >> graph.arcnum;
	graph.vexs = new char[graph.vexnum];
	if (!graph.vexs)exit(-1);
	cout<<endl << "Please Enter each vertex in turn (separated by spaces) :" << endl;
	for (int i = 0; i < graph.vexnum; i++) {
		cin >> graph.vexs[i];
	}
	graph.arcs = new DEFINE_ARC * [graph.vexnum];
	//动态分配空间存储边的信息
	if (!graph.arcs)exit(-2);
	for (int i = 0; i < graph.vexnum; i++) {//初始化加权的边
		graph.arcs[i] = new DEFINE_ARC[graph.vexnum];
		//动态分配空间存储边的信息
		for (int j = 0; j < graph.vexnum; j++) {
			graph.arcs[i][j].weight = INFINIY;
			graph.arcs[i][j].info = NULL;
			//初始化边的信息
		}
	}
	char va, vb;
	int weight=1;
	if (graph.kind ==DN||graph.kind==AN ) {
		cout << "Please Enter the starting vertex, end vertex, and weight of the edge (separated by spaces) :" << endl;
		int i, j;
		for (int k = 0; k < graph.arcnum; k++) {
			cin >> va >> vb >> weight;
			i = Locate_Vex(graph, va);
			j = Locate_Vex(graph, vb);
			graph.arcs[i][j].weight = weight;
			if (graph.kind == AN) graph.arcs[j][i].weight = weight;
		}
	}
	else {
		cout << "Please Enter the starting vertex and end vextex of the edge (separated by spaces) :" << endl;
		int i, j;
		for (int k = 0; k < graph.arcnum; k++) {
			cin >> va >> vb;
			i = Locate_Vex(graph, va);
			j = Locate_Vex(graph, vb);
			graph.arcs[i][j].weight = weight;
			if (graph.kind == AG) graph.arcs[j][i].weight = weight;
		}
	
	}
}
int Locate_Vex(M_GRAPH G, char v) {
	//定位，确定点的坐标
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v)return i;
	}
	return -1;

}



int Found_Vex(M_GRAPH graph, char v) {
	//查找graph中与v相邻的顶点，返回值为顶点的地址，查找失败返回-1
	int k = Locate_Vex(graph, v);
	for (int i = 0; i < graph.vexnum; i++) {
		if (visited[i]==0 && graph.arcs[k][i].weight!=0) {
			return i;
		}
	}
	return -1;
}
void DFS_TRAVER_M(M_GRAPH graph, char v) {
	//从顶点v出发递归的深度优先遍历图graph
	int i = Locate_Vex(graph, v);
	visited[i]=1;
	cout << graph.vexs[i]<<"\0\0";
	for (int j = Found_Vex(graph, v); j != -1; j = Found_Vex(graph, v)) {
		DFS_TRAVER_M(graph, graph.vexs[j]);
	}

}
void DFS_M_GRAPH(M_GRAPH graph) {
	char start;
	//bool visited[graph.vexnum];why???
	visited = new bool[graph.vexnum];
	//0表示顶点未被访问，1表示访问
	for (int i = 0; i < graph.vexnum; i++) {
		visited[i] = 0;
	}//初始化
	cout<<endl << "Please Enter the starting vex for depth-first traversing :";
	cin >> start;
	cout << endl << endl << "···the order of depth-first traversing is :"<<endl;
	cout << "\t\t\t";
	DFS_TRAVER_M(graph, start);
	for (int i = 0; i < graph.vexnum; i++) {
		if (!visited[i])DFS_TRAVER_M(graph, graph.vexs[i]);
	}//访问其他与点start不连通的顶点
	delete []visited;
	
}

void BFS_M_GRAPH(M_GRAPH graph) {//广度优先遍历
	visited = new bool[graph.vexnum];
	for (int i = 0; i < graph.vexnum; i++) {
		visited[i] = 0;
	}//初始化数组visited
	squeue Q;
	char start;
	Initqueue(Q, graph.vexnum);
	cout <<endl<<endl<< "Please Enter the starting vex for breadth-first traversing : ";
	cin >> start;
	int  i = Locate_Vex(graph, start);
	visited[i] = 1;
	cout << endl << endl << "···the order of depth-first traversing is :" << endl;
	cout << "\t\t\t";
	cout << graph.vexs[i]<<' ';
	INqueue(Q, start);
	char ch;
	int k;
	while (!Emptyqueue(Q)) {
		Outqueue(Q, ch);
		k = Locate_Vex(graph, ch);
		for (int i = 0; i < graph.vexnum; i++) {
			if (graph.arcs[k][i].weight && !visited[i]) {
				visited[i] = 1;
				cout << graph.vexs[i] << ' ';
				INqueue(Q, graph.vexs[i]);
			}
		}
	}//while
	Distory_Queue(Q);
	delete[]visited;
}
void PRINT_M_GRAPH(M_GRAPH graph) {
	//打印图的邻接矩阵
	cout << endl << endl << "···············the adjacent matrix of the graph is :";
	cout << endl << "\t\t\t     ";//五个空格
	for (int i = 0; i < graph.vexnum; i++) {
		cout << setiosflags(ios::left) << setfill('\0') << setw(6)<<graph.vexs[i];
	}
	cout << endl;
	for (int i = 0; i < graph.vexnum; i++) {
		cout <<"\t\t\t"<< graph.vexs[i]<<"- - ";
		for (int j = 0; j < graph.vexnum; j++) {
			if (graph.arcs[i][j].weight == INFINIY)cout << setiosflags(ios::left) << setfill('\0') << setw(6) << "MAX";//0表示路径不存在
			else cout<< setiosflags(ios::left) << setfill('\0') << setw(6) << graph.arcs[i][j].weight ;
		}
		cout << endl;

	}
}
//cout << setiosflags(ios::left) << setfill('\0') << setw(3) 
void Dijkstra(M_GRAPH G,char start) {
	//迪杰斯特拉算法
	int* path = new int[G.vexnum];
	int* dist = new int[G.vexnum];
	bool* mark = new bool[G.vexnum];
	int first = Locate_Vex(G, start);
	for (int i = 0; i < G.vexnum; i++) {
		dist[i] = G.arcs[first][i].weight;
		mark[i] = 0;
		path[i] = first;
	}
	dist[first] = 0;
	mark[first] = 1;
	for (int times = 0; times < G.vexnum; times++) {
		int min = INFINIY;
		int index=-1;
		for (int j = 0; j < G.vexnum; j++) {
			if (!mark[j] && dist[j] < min) {
				min = dist[j];
				index=j;
			}
		}
		if (index > -1) {
			mark[index] = 1;
		}
		for (int j = 0; j < G.vexnum; j++) {
			if (!mark[j] && min + G.arcs[index][j].weight < dist[j]) {
				dist[j] = min + G.arcs[index][j].weight;
				path[j] = index;

			}
		}
	}
	

	cout << endl << endl << "the shortest path for start to others :" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << endl << "\t\t" << start << "- - - ->" << G.vexs[i] << " :" << dist[i] << endl;
		cout << "the shartest path is :";
		for (int j = i; j != first; j = path[j]) {
			cout << G.vexs[j] << "<- - ";
		}
		cout << start << endl;
	}
	delete[]dist;
	delete[]path;
	delete[]mark;
}

void Floyd(M_GRAPH G) {
	//弗洛伊德算法
	int** dist = new int* [G.vexnum];
	for (int i = 0; i < G.vexnum; i++) {
		dist[i] = new int[G.vexnum];
	}
	int** path = new int* [G.vexnum];
	for (int i = 0; i < G.vexnum; i++) {
		path[i] = new int[G.vexnum];
	}
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			dist[i][j] = G.arcs[i][j].weight;
			path[i][j] = j;
		}
	}
	//初始化dist,和path
	for (int k = 0; k < G.vexnum; k++) {

		for (int i = 0; i < G.vexnum; i++) {

			for (int j = 0; j < G.vexnum; j++) {

				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			if (i != j&& dist[i][j] < INFINIY) {
				int p = i;
				cout << G.vexs[i] << "- ->" << G.vexs[j] << " : " << "  weight :"<< setiosflags(ios::left) << setfill('\0') << setw(10) <<dist[i][j];
				cout <<"path : "<< G.vexs[i];
				do {
					p = path[p][j];
					cout << "- ->" << G.vexs[p];
				} while (p != j);
				cout << endl;
			}
		}
	}
}

void menu1() {
	M_GRAPH graph;
	CREATE_GRAPH_ADJACENT_MATRIX(graph);
	PRINT_M_GRAPH(graph);
	Floyd(graph);
}
