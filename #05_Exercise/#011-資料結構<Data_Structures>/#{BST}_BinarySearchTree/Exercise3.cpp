#include <stdio.h> 
#include <stdlib.h>

#define MAX 80



int Output[MAX] = {0};
int OutputIndex = 0;

struct node {
	int data;
	int level;
	node *llink, *rlink;
	node() {
		llink=NULL;
		rlink=NULL;
	}
};

int pow(int, int);

struct BS_tree {
	node *head;
	int height;
	BS_tree(const char *filename);
	void Insert(int num);		//包含建立以及插入節點
	void Delete(int num);		//從Ｂinary Seerch Tree中刪除一個節點
	//void ShowTree();			//以樹狀圖形將此Binary Search Tree印出
	node* Search(int num);		//當呼叫此函數時，傳入一個欲搜尋的數值進行搜尋
								//若找到則傳回此節點的父親節點如果沒有找到則回傳null
	void LevelTraversal();				
}; 

struct Queue {
	node* seq[MAX];
	int front, rear;
	Queue() {
		front=0;
		rear=0;
	}
	bool IsFull() {
		if((rear+1)%MAX == front) {			
			return true;
		}
		else
			return false;
	}
	bool IsEmpty() {
		if(rear == front)
			return true;
		else
			return false;
	}
	void Add(node* tmp) {
		if(IsFull()==false)	{
			seq[rear]=tmp;
			rear=(rear+1)%MAX;
		} else {
			printf("The Queue is Full\n");
		}		
	}
	node* Del()	{
		node *tmp=NULL;
		if(IsEmpty()==false) {
			tmp=seq[front];
			front = (front+1)%MAX;
		} else {
			printf("The Queue is Empty\n");
		}
		return tmp;
	}
	void ShowTree(BS_tree myTree);
};

int main() {
	BS_tree myTree("input.txt");
	myTree.LevelTraversal();


	Queue Q; 
	Q.ShowTree(myTree);
	return 0;
} 

//======================================
BS_tree::BS_tree(const char *filename) {
	FILE *fptr;
	int num;
	head=NULL;
	height=0;
	fptr=fopen(filename, "r");
	
	printf("讀檔:");

	while(!feof(fptr)) {
		fscanf(fptr,"%d",&num);
		printf("%2d ",num);
		this->Insert(num);
	}
	printf("\n");
}
//======================================
void BS_tree::Insert(int num) {
	if(head == NULL) {
		head=(node*)malloc(sizeof(node));
		// head = new node;
		head->data=num;
		head->level=1;
		head->llink=NULL;
		head->rlink=NULL;
	} else {
		node *tmp, *child;
		tmp = this->Search(num);		//檢查有沒有存在在此樹當中
				
		//child=new node;
		child=(node*)malloc(sizeof(node));
		child->rlink=NULL;
		child->llink=NULL;
		child->data=num;
		child->level=tmp->level+1;
		if(this->height<child->level) {
			this->height=child->level;		//加height
		} 

		//判斷數值放左方 or 右方
		if(num > tmp->data) {	//較大的在右邊
			tmp->rlink=child;			
		} else {
			tmp->llink=child;
		}
	}
}
//======================================
node* BS_tree::Search(int num) {
	node *tmp=head, *pre=NULL;
	while(tmp!=NULL) {
		pre=tmp;
		//g
		if(num>tmp->data) {			
			tmp=tmp->rlink;
		} else {
			tmp=tmp->llink;	
		}
	}
	return pre;
}
//======================================
void BS_tree::LevelTraversal() {
	Queue Q;
	node *tmp=head;
	Q.Add(tmp);
	
	bool Flag = true;

	printf("Queue:");
	while(Q.IsEmpty() != true) {
		tmp = Q.Del();
		printf("%2d ",tmp->data);	//Output

		if(Flag){
			Output[OutputIndex] = tmp->data;
			OutputIndex++;
			Flag = false;
		}


		//左邊
		if(tmp->llink != NULL) {		
			Q.Add(tmp->llink);
			Output[OutputIndex] = tmp->llink->data;
			OutputIndex++;
		} else {
			Output[OutputIndex] = -1;
			OutputIndex++;
		}

		//右邊
		if(tmp->rlink != NULL) {
			Q.Add(tmp->rlink);
			Output[OutputIndex] = tmp->rlink->data;
			OutputIndex++;			
		} else {
			Output[OutputIndex] = -1;
			OutputIndex++;
		}
	}

	printf("\n");
}
//======================================
int pow(int base, int exp) {
	int ans = 1;
	int i=0;

	for(i=0;i<exp;i++) {
		ans *= base;
	}

	return ans;
}
//======================================

void Queue::ShowTree(BS_tree myTree) {
	Queue Q;
	node* tmp = myTree.head;
	int counter = pow(2,myTree.height);

	int index = 0;
	int target = 0;
	printf("Test Counter: %d\n", counter);

	index = counter;

	for(int i=0; i<9; i++)
		printf("%d ", Output[i]);
	puts("");

	target = 0;
	for(int i=0; i<myTree.height; i++){

		index /=2;	//總長度除以二

		for(int j=0; j<pow(2,i); j++){
			//輸出空白
			for(int k=0; k<index; k++){
				printf("  ");
			}

			//輸出資料
			if(Output[target] > 0)
				printf("\b\b%2d", Output[target]);
			else
				printf("\b\b  ");

			target++;
			//輸出空白
			for(int k=0; k<index; k++){
				printf("  ");
			}

		}
		printf("\n");
		

	}
}