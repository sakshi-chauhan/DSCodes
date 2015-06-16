// http://ideone.com/Pv67Ga
//Singly Linked Lists

#include<iostream>

//Define a node
class SLLNode{
      
      public:
             //Members - data to be stored and address of the next node in sequence
             int data;
             SLLNode* next;    
      
             //Constructor
             SLLNode(){
                       
                       next = 0;          
                       
             }
             SLLNode( int d , SLLNode* n = 0 ){
                       
                       data = d;          
                       next = n;
                       
             }
};

//Define a list of nodes

class SLL{
      
      //head points to first node while tail points to last node of the list
      SLLNode *head , *tail;       
      
      public:
             SLL(){
                   
                   head = tail = 0;      
                   
             }
             
             bool isempty(){
                  
                  return head==0;     
             }
             
             //void AddToList( SLLNode **head, int d , int pos );
			 void printList();
			 void AddToHead( int e );
			 void AddToTail( int e );
			 void AddMid( int e , int pos );
			 int DeleteFromHead();
			 int DeleteFromTail();
			 int DeleteFromPos( int pos );
			 int DeleteElement( int el );
};

void SLL::AddToHead( int e ){

	head = new SLLNode ( e , head );
	if( tail == 0 )
		tail = head;
}

void SLL::AddToTail( int e ){

	if( tail != 0 ){
		tail->next = new SLLNode( e );
		tail = tail->next;
	}
	else
		head = tail = new SLLNode( e ) ;
}


void SLL::AddMid( int e , int pos ){
	
	SLLNode *newnode = new SLLNode( e );
	SLLNode *p,*q;
	p = head;
	int k = 1;
	
	
	if( pos == 1 ){
		
		newnode->next = p;
		head = newnode;
		
	}
	
	else{
		while( p != NULL && k < pos ){
			
			k++;
			q = p;
			p = p -> next;
			
		}
		
		q -> next = newnode;
		newnode -> next = p;
	}
}


int SLL::DeleteFromHead(){
	
	SLLNode *p = head;
	int e1 = p->data;
	
	if( head == tail )
		head = tail = 0;
		
	else
		head = head -> next;
	
	delete(p);
	
	return e1;
}

int SLL::DeleteFromTail(){
	
	int e1 = tail->data;
	
	if( head == tail ){
		
		delete head;
		head = tail = 0;
	}
	
	else{
		
		SLLNode *temp;
		
		for( temp = head ; temp->next != tail ; temp = temp -> next );
		
		delete tail;
		
		tail = temp;
		tail->next = NULL;
		
	}
		
	return e1;
}

int SLL::DeleteFromPos( int pos ){
	
	SLLNode *p,*q;
	int k = 1;
	int el;
	
	p = head;
	
	if( pos == 1 ){
		
		el = p->data;
		head = head -> next;
		delete(p);
		return el;
	}
	
	else{
		while( p != NULL && k < pos ){
			
			q = p;
			k++;
			p = p-> next;
			
		}
		
		q->next = p->next;
		p->next = NULL;
		el=p->data;
		delete(p);
		return el;
	}
}

int SLL::DeleteElement( int el ){
	
	SLLNode *p,*q;
	
	p = head;
	
	if( head->data == el ){
		
		head = head -> next;
		delete(p);
		return el;
	}
	
	else{
		while( p != NULL && p->data != el ){
			
			q = p;
			p = p-> next;
			
		}
		
		q->next = p->next;
		p->next = NULL;
		
		delete(p);
		return el;
	}
	
	
}

void SLL::printList( ){

	SLLNode *p = head;
	
	while( p != NULL ){
	
		std::cout<<p->data<<"->";
		p = p->next;
		
	}

}

int main(){
    
    SLL list;
    list.AddToHead(45);
    list.AddToHead(21);
    list.AddToHead(3);
    list.printList();
    std::cout<<"\n";
    /*list.AddToTail(40);
    list.AddToTail(4);
    list.AddToTail(5);
    list.printList();
    std::cout<<"\n";
    list.AddMid(0,2);
    list.printList();
    list.AddMid(14,3);
    list.printList();
    list.AddMid(15,2);
    list.printList();*/
    
    list.DeleteElement(21);
    list.printList(); 
    return 0;   
}
