#include <iostream>
#include <cstring>
using namespace std;

struct Deque 
{
    int data[20000];
    int head;
    int tail;
};

void init(Deque* dq) 
{
	dq->head = 10000;
	dq->tail = 10000;
}

void push_front(Deque* dq, int x) 
{
	dq->data[--dq->head] = x;
}

void push_back(Deque* dq, int x) 
{
	dq->data[dq->tail++] = x;
}

int pop_front(Deque* dq) 
{
	if (dq->head == dq->tail) 
		return -1;
	return dq->data[dq->head++];
}

int pop_back(Deque* dq) 
{
	if (dq->head == dq->tail) 
		return -1;
	return dq->data[--dq->tail];
}

int size(Deque* dq) 
{
	return dq->tail - dq->head;
}

int empty(Deque* dq) 
{
	return (dq->head == dq->tail) ? 1 : 0;
}

int front(Deque* dq) 
{
	if (dq->head == dq->tail) 
		return -1;
	return dq->data[dq->head];
}

int back(Deque* dq) 
{
	if (dq->head == dq->tail) 
		return -1;
	return dq->data[dq->tail - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	Deque dq;

	init(&dq);	
	
	while (N--) 
	{
		char cmd[20];
		cin >> cmd;

		if (!strcmp(cmd, "push_front")) 
		{
			int x; cin >> x;
			push_front(&dq, x);
		}
		else if (!strcmp(cmd, "push_back")) 
		{
			int x; cin >> x;
			push_back(&dq, x);
		}
		else if (!strcmp(cmd, "pop_front")) 
		{
			cout << pop_front(&dq) << "\n";
		}
		else if (!strcmp(cmd, "pop_back")) 
		{
			cout << pop_back(&dq) << "\n";
		}
		else if (!strcmp(cmd, "size")) 
		{
			cout << size(&dq) << "\n";
		}
		else if (!strcmp(cmd, "empty")) 
		{
			cout << empty(&dq) << "\n";
		}
		else if (!strcmp(cmd, "front")) 
		{
			cout << front(&dq) << "\n";
		}
		else if (!strcmp(cmd, "back")) 
		{
			cout << back(&dq) << "\n";
		}
	}

	return 0;
}