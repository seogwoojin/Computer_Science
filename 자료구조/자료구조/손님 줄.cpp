# include <stdio.h>
# include <stdlib.h>
#define MAX_QUEUE_SIZE 1000

typedef int element;
typedef struct { // 큐 타입
	int front;
	int rear;
	element data[1000];
} QueueType;
// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("queue full");
		return;
	}
	q->data[++(q->rear)] = item;
}
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("empty");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

// 프로그램 5.2에서 다음과 같은 부분을 복사한다.
// ================ 원형큐 코드 시작 =================
typedef struct { // 요소 타입
	int id;
	int arrival_time;
	int service_time;
} element; // 교체!
// ...
// ================ 원형큐 코드 종료 =================
int main(void)
{
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	init_queue(&queue);

