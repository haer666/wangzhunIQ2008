#include"GRAPH_HEAD.h"
bool Initqueue(squeue& Q, int maxsize) {//初始化队列，默认队列长度为30
	if (maxsize == 0)
	{
		maxsize = MAXSIZE;
	}
	Q.base = new char[maxsize];
	if (!Q.base) return 0;
	Q.head = Q.rear = 0;
	Q.queuesize = maxsize;
	return 1;
}
bool Fullqueue(squeue Q) {//判断队满
	if ((Q.rear + 1) % Q.queuesize == Q.head) return 1;
	else return 0;
}
bool Emptyqueue(squeue Q) {//判断队空
	if (Q.head == Q.rear) return 1;
	else return 0;
}
void INqueue(squeue& Q, char e) {//入队
	if (Fullqueue(Q))
		cout << "队列已满！！！" << endl;

	else {
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % Q.queuesize;
	}
}
bool Outqueue(squeue& Q, char& e) {//出队
	if (Emptyqueue(Q))
		cout << "队列为空！！！" << endl;

	e = Q.base[Q.head];
	Q.head = (Q.head + 1) % Q.queuesize;
	return 1;
}
bool Distory_Queue(squeue& Q) {
	if (!Q.base) return 0;
	Q.rear = Q.head = 0;
	Q.queuesize = 0;
	delete Q.base;
	return 1;
}