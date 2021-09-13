#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct queue{
	struct node *head;
	struct node *tail;
	int size;
};

struct queue *init_queue(void)
{
	//1.为管理结构体申请空间
	struct queue *q = malloc(sizeof(struct queue));
	if (NULL == q)
		printf("malloc queue error!\n");

	//2.为管理结构体赋值
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;

	return q;
}

void in_queue(struct queue *q, int num)
{
	//1.为新节点申请空间
	struct node *new = malloc(sizeof(struct node));
	if (NULL == new)
		printf("malloc new error\n");

	//2.为数据域与指针域赋值
	new->data = num;
	new->next = NULL;     	  //新排队的人后面肯定没有人

	if (0 == q->size)         //如果插入的节点是第一个节点，则需要特殊处理
	{
		q->head = new;        //如果队列中只有你一个人，那么队头队尾都是你
		q->tail = new;
	}
	else {
		q->tail->next = new;  //让现在队尾的那个元素的指针域指向新节点
		q->tail = new;        //让指向队尾的那个指针指向新节点new
	}

	q->size++;  //元素个数 +1
	return;
}

int show_queue(struct queue *q)
{
	//1.判断是否为空队
	if (q->size == 0)
	{
		return -1;
	}

	//2.遍历队列
	struct node *p = NULL;
	for (p = q->head; p != NULL; p = p->next)
	{
		printf("%d -> ",p->data);
	}
	printf("\n");

	return 0;
}

int out_queue(struct queue *q, int *a)
{
	//1.判断队列是否为空
	if (q->size == 0)
		return -1;

	//2.不为空，就可以正常的出队
	struct node *tmp = q->head;  //tmp就是指向将来出队的那个节点

	//3.分情况讨论
	if (q->size == 1)  //整个队列就剩一个节点
	{
		q->head = NULL;
		q->tail = NULL;
	}
	else{              //不止一个节点
 	 	q->head = q->head->next;
	}
	*a = tmp->data;
	free(tmp);
	q->size--;

	return 0;
}

int main(int argc, char const *argv[])
{
	//1.初始化一条空队
	struct queue *q = NULL;
	q = init_queue();

	//2.入队
	in_queue(q,10);
	in_queue(q,20);
	in_queue(q,30);

	//3.遍历队列
	show_queue(q);

	//4.出队
	int a;
	while (q->size != 0)
	{
		out_queue(q, &a);
		printf("出队的元素是:%d\n", a);
		show_queue(q);
		printf("---------------\n");
	}

	//5.释放
	free(q);

	return 0;
}


