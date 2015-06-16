//ideone.com/lbpUa0
//Queue represented as an array

#include<iostream>
#include<cstdlib>
#include<climits>

using namespace std;

struct Queue{
	
	int front,rear,size;
	int *arr;
	int capacity;
	
};


Queue* createQueue( int capacity ){
	
	Queue *queue = new Queue;
	queue -> capacity = capacity;
	queue -> front = queue -> size = 0;
	queue -> rear = capacity - 1;
	queue -> arr = (int*) malloc( capacity * sizeof(int) );
	
}

bool isEmpty( Queue *q ){
	
	return ( q -> size == 0 );
}


bool isFull( Queue *q ){
	
	return (q -> size == q -> capacity);
	
}

void enqueue( Queue *q , int item ){
	
	if( !isFull(q) ){
		
		q -> rear = ( q -> rear + 1 ) % q -> capacity;
		q -> arr[ q -> rear ] = item;
		q -> size = q -> size + 1;
			
		cout<<item<<" enqueued\n";	
		
	}
	else
		cout<<"Queue already full!!\n";
}

int dequeue( Queue *q ){
	
	if( !isEmpty(q) ){
		
		int item = q->arr[q->front];
    	q->front = (q->front + 1)%q->capacity;
    	q->size = q->size - 1;
    	return item;
		
	}
	else
		return INT_MIN;
}


int main(){
	
	
	
	return 0;
	
}
