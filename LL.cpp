#include<iostream>
using namespace std;

class List{

	private:
		struct Node{
			
			int data;
			Node *next, *prev;
			
		};
		
		Node *head, *tail;

	public:
		
		void Insert(int a, int b, int d){
			
			Node *newNode = new Node;
			newNode->data = d;
			
			if(head == NULL){
				
				newNode->next=NULL;
				head = newNode;
				
			}else{
				
				Node *curr = head;
				Node *previ;
				
				while(curr->data != b && previ->data != a && curr != NULL){
					
					previ = curr;
					curr = curr->next;
				}
				
				if( curr == NULL){
					
					
					cout<<"Nodes not found."<<endl;
				}else{
					
					previ->next = newNode;
					newNode->prev = previ;
					newNode->next = curr;
					curr->prev = newNode;
				}
				
			}
			
		}
		
		void Display(){
			
			if(head == NULL){
				
				cout<<"List empty.";
				
			}else{
				
				Node *temp = head;
				
				while(temp != NULL){
					
					cout<<temp->data<<"  ";
					temp = temp->next;
				}
				
			}
			
			
		}
		
		void Insert_Tail(int a){
			
			Node *newNode = new Node;
			newNode->data = a;
			
			if(head == NULL){
				
				newNode->next=NULL;
				head = newNode;
				
			}else{
				
				Node *curr = head;
				
				while(curr->next != NULL){
					curr=curr->next;
				}
				newNode->next = NULL;
				curr->next = newNode;
			
		}
	}
	
	void Delete(int k){
		
		Node *curr = head;
		Node *previ;
		
		while(previ->data != k && curr != NULL){
			
			previ = curr;
			curr = curr->next;
		}
		
		curr->prev = previ->prev;
		previ->prev->next = curr;
		delete previ;
		
	}
	
	void Selection(){
		
		Node *temp = head;
		Node *small;
		
		while(temp!=NULL){
			
			Node *small = temp;
			
			Node *j = temp->next;
			
			while(j != NULL){
				
				if(j->data < small->data){
					
					small = j;
					
				}
				
				j = j->next;
				
			}
			
			int swap = temp->data;
			temp->data = small->data;
			small->data = swap;
			
			temp = temp->next;
		}
		
	}
	
	void Bubble(){
		
		Node *i = head;
		Node *j;
		
		while(i->next != NULL){
			
			j = i->next;
			
			while(j != NULL){
				
				if(j->data < i->data){
				
				int temp = i->data;
				i->data = j->data;
				j->data = temp;
			
				}
				
				j = j->next;
				
			}
			
			i = i->next;
			
		}
		
	}
};


int main(){
	
	
	List l;
	
	l.Insert_Tail(5);
	l.Insert_Tail(6);
	l.Insert_Tail(1);
	l.Insert_Tail(7);
	l.Insert_Tail(4);
	l.Insert_Tail(10);
	l.Insert_Tail(2);
	
	l.Insert(6,7,8);
	l.Bubble();
	//l.Delete(6);
	l.Display();
	
	
	return 0;
}
