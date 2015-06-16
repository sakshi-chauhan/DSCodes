//http://ideone.com/wygTux
//Priority Queue represented as an array

#include<iostream>
#include<cstdlib>
#include<climits>

using namespace std;

struct item{
	
	int data;
	int priority;
	
};

struct P_Queue{
	
	int front,rear,size;
	item *arr;
	int capacity;
	
};


P_Queue* createQueue( int capacity ){
	
	P_Queue *queue = new P_Queue;
	queue -> capacity = capacity;
	queue -> front = queue -> size = 0;
	queue -> rear = capacity - 1;
	queue -> arr = (item*) malloc( capacity * sizeof(item) );
	
	return queue;
	
}

bool isEmpty( P_Queue *q ){
	
	return ( q -> size == 0 );

}


bool isFull( P_Queue *q ){
	
	return (q -> size == q -> capacity);
	
}

void enqueue( P_Queue *q , int item , int priority ){
	
	if( !isFull(q) ){
		
		q -> rear = ( q -> rear + 1 ) % q -> capacity;
		q -> arr[ q -> rear ].data = item;
		q -> arr[ q -> rear ].priority = priority;
		q -> size = q -> size + 1;
			
		cout<<item<<" with priority "<<priority<<" enqueued\n";	
		
	}
	else
		cout<<"Queue already full!!\n";
}

item* dequeue( P_Queue *q ){
	
	if( !isEmpty(q) ){
		
		item* it = new item;
		it -> data = q->arr[q->front].data;
		it -> priority = q->arr[q->front].priority;
		
    	q->front = (q->front + 1)%q->capacity;
    	q->size = q->size - 1;
    	
    	return it;
		
	}
	
	else
		return NULL;
}


int main(){
	
	P_Queue *q = createQueue(5);
	enqueue( q , 2 , 3);
	enqueue( q , 1 , 2);
	enqueue( q , 7 , 5);
	enqueue( q , 6 , 1);
	enqueue( q , 9 , 0);
	
	item *i = dequeue(q);
	cout<<i -> data<<" with priority "<<i -> priority<<" dequeued ";
	
	return 0;
	
}
