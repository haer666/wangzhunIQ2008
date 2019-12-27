#include"GRAPH_HEAD.h"
bool Initqueue(squeue& Q, int maxsize) {//��ʼ�����У�Ĭ�϶��г���Ϊ30
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
bool Fullqueue(squeue Q) {//�ж϶���
	if ((Q.rear + 1) % Q.queuesize == Q.head) return 1;
	else return 0;
}
bool Emptyqueue(squeue Q) {//�ж϶ӿ�
	if (Q.head == Q.rear) return 1;
	else return 0;
}
void INqueue(squeue& Q, char e) {//���
	if (Fullqueue(Q))
		cout << "��������������" << endl;

	else {
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % Q.queuesize;
	}
}
bool Outqueue(squeue& Q, char& e) {//����
	if (Emptyqueue(Q))
		cout << "����Ϊ�գ�����" << endl;

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