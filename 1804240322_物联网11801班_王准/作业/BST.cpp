

#include <iostream>
using namespace std;
typedef int keytype;
typedef struct BITNode {
	int data;
	struct BITNode* lchild, * rchild;
}BITNode ,*BITree;
bool Search(BITree T, keytype key, BITree f, BITree& p);//查找
bool Insert(BITree& T, int e);//插入
void CreateBITree(BITree& T);//创建
void Display(BITree T);//输出
void Inorder(BITree T);//中序递归遍历
void DeleteNode(BITree& p);//删除节点
bool DeleteBITree(BITree& T, keytype key);//删除节点
void Destory(BITree& T);//销毁树
void Delete(BITree& T);
void menu();//菜单
bool Search(BITree T, keytype k, BITree f, BITree& p) {
	//寻找与关键值相对应的节点
	if (!T) {
		p = f;
		return 0;//节点不存在返回零
	}
	if (k == T->data) {
		p = T;
		return 1;
	}
	else if (k < T->data)return Search(T->lchild, k, T, p);//左子树递归
	else return Search(T->rchild, k, T, p);//右子树递归
}
bool Insert(BITree& T, int e) {
	BITree p;
	if (!Search(T, e, NULL, p)) {//寻找不到时，插入
		BITree s = new BITNode;
		s->data = e;
		s->lchild = s->rchild = NULL;//初始化s节点
		if (!p) T = s;//树空，根节点不存在
		else if (e < p->data)
			p->lchild = s;
		//要插入的节点的关键值小于p节点的关键值，节点作为左节点
		else p->rchild = s;
		//要插入的节点的关键值大于p节点的关键值，节点作为右节点
		return 1;
	}
	return 0;
}
void CreateBITree(BITree& T) {//创建二叉排序树
	int e;
	cin >> e;
	while (e != -1) {
		Insert(T, e);
		cin >> e;
	}
}
void Display(BITree T) {//输出节点的关键值
	if (!T)cout << "节点不存在";
	else cout << T->data<<" ";
}
void Inorder(BITree T) {//中序递归遍历输出二叉排序树
	if (T) {
		Inorder(T->lchild);
		Display(T);
		Inorder(T->rchild);
	}
}
void DeleteNode(BITree& p){
	//删除二叉排序树的节点
	if (!p->rchild) {
		BITree q = p;
		p = p->lchild;
		delete q;
	}
	else if (!p->lchild) {
		BITree q = p;
		p = p->rchild;
		delete q;
	}
	else {//删除节点的左右节点均存在时，找前驱
		BITree q = p;
		BITree s = p->lchild;
		while (s->rchild) {//s有右孩子时
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (p != q)//判断p的左孩子是否为p的中序前驱
			q->rchild = s->rchild;
		//此时，使s与树无关，为释放s做准备
		else q->lchild = s->lchild;
		//此时s为p（q）的前驱
		delete s;
	}
}
bool DeleteBITree(BITree &T, keytype key){
	//删除树T中关键值为key的节点，删除失败返回0，成功返回1。
	if (!T)return 0;
	else {
		if (key == T->data) {
			DeleteNode(T);
			return 1;
		}
		else if (key < T->data)return DeleteBITree(T->lchild,key);
		else return DeleteBITree(T->rchild, key);
	}

}
void Delete(BITree &T) {
	cout << "请输入要删除节点的关键值：";
	keytype key;
	cin >> key;
	cout << endl;
	if (DeleteBITree(T, key))
		cout << "删除成功！！！" << endl << endl;
	else cout << "删除失败！！树为空或树中不存在您输入的关键值" << endl<<endl;
}
void Destory(BITree& T) {
	if (T) {
		Destory(T->lchild);
		Destory(T->rchild);
		T = NULL;
		delete T;
	}
}
void menu() {
	cout << "========================菜单========================" << endl;
	cout << "1.构造二叉排序树        2.中序遍历输出" << endl;
	cout << "3.删除节点              4.销毁二叉树" << endl;
	cout << "5.退出菜单" << endl;
	cout << "====================================================" << endl;
	cout << "请输入您的选择：";
	int choice;
	BITree T=NULL;
	cin >> choice;
	cout << endl;
	while (choice != 5) {
		switch (choice)
		{	
		case 1:
			cout << "请输入关键字序列（中间用空格隔开，输入-1截止）：" << endl ;
			CreateBITree(T);
			cout << endl;
			break;
		case 2:
			Inorder(T);
			cout << endl<<endl;
			break;
		case 3:
			Delete(T);
			break;
		case 4:
			Destory(T);
			break;
		default:
			cout << "请输入正确的选择！！！" << endl<<endl;
			break;
		}
		cout << "请输入您的选择：";
		cin >> choice;
		cout << endl;
	}

}
int main() {
	menu();
	return 0; 
}


