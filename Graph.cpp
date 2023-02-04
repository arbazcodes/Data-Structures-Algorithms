#include<iostream>
#include<stack>
#include<queue>
using namespace std;

/*class stack{
	
	private:
		
		
	public:
		
		struct Node{
			
			int data;
			Node *next;
		};
		
		Node *top;
		
		stack(){
			
			top = NULL;
	
		}
		
		bool empty(){
			
			if(top == NULL)
				return true;
			else
				return false;			
		}
		
	int Top(){
		
		int a = top->data;
		return a;
		
	}
		
	void push(int value){
		
		Node *newNode = new Node;
		newNode->data = value;
		newNode->next = top;
		top = newNode;
		
	}
	
	void pop(){
		
		if(top == NULL){
			
			cout<<"Stack is empty."<<endl;
			
		}else{
			Node *temp = top;
			top = top->next;
			delete temp;
		}
		
		
	}	
	
};*

class Queue{
	
	private: 
		struct Node{
			
			int data;
			Node *next;
		};
		Node *head, *tail;
		bool visited[1000];
	public: 
		
		Queue(){
			
			head = tail = NULL;
			
			
		}
		
		bool Empty(){
			
			if(head == NULL)
				return true;
			else 
				return false;
			
		}
		
		int front(){
			
			return head->data;
			
		}
		
		void push(int k){
			
			Node *newNode = new Node;
			newNode->data = k;
			newNode->next = NULL;
			
			if(head == NULL){
				
				head = tail = newNode;
				
			}else{
				
				tail->next = newNode;
				tail = newNode;
			}
			
		}
		
		int pop(){
			
			if(head == NULL){
				
				cout<<"Empty list."<<endl;
				return -1;
				
			}else if(head->next == NULL){
				
				int j = head->data;
				delete head;
				head = tail = NULL;
				return j;
				
			}else{
				
				Node *temp = head;
				int j = head->data;
				head = head->next;
				delete temp;
				return j;
				
			}
			
			
		}
	
};
*/
class Graph{
	
	private:
		
		
		struct Neighbour{
			
			int data;
			Neighbour *next;
			int weight;
			
		};
		struct Node{
			
			int data;
			Node *next;
			Neighbour *neighbours;
			string color;
			
		};
		
		Node *head;
		
		bool visited[1000];
		public:
			
			Graph(){
				
				head = NULL;
				
				for(int i = 0; i < 1000; i++){
					
					visited[i] = false;	
					
				}
				
			}
			
			void Vertex(int data){
				
				Node *newNode = new Node;
				newNode->data = data;
				newNode->neighbours = NULL;
				newNode->next = NULL;
				newNode->color = "white";
				
				if(head == NULL){
					
					head = newNode;
					
				}else{
					
					Node *temp = head;
					
					while(temp->next != NULL){
						
						temp = temp->next;
						
					}
					
					temp->next = newNode;
				}
			}
			
			void Edge(int src, int dest, int w){
				
				Node *temp = head;
				
				while(temp != NULL && temp->data != src){
					
					temp = temp->next;
					
				}
				
				if(temp == NULL)
					cout<<"Node not found.";
				else{
					
					Neighbour *n = new Neighbour;
					n->data = dest;
					n->weight = w;
					n->next = NULL;
					
					if(temp->neighbours == NULL)
						temp->neighbours = n;
					else{
						
						Neighbour *temp2 = temp->neighbours;
						
						while(temp2->next != NULL){
							
							temp2 = temp2->next;
							
						}
							
							
						temp2->next = n;
						
					}
				 
				}
				
				
				
				Node *tempp = head;
				
				while(tempp != NULL && tempp->data != dest){
					
					tempp = tempp->next;
					
				}
				
				if(tempp == NULL)
					cout<<"Node not found.";
				else{
					
					Neighbour *nn = new Neighbour;
					nn->data = src;
					nn->weight = w;
					nn->next = NULL;
					
					if(tempp->neighbours == NULL)
						tempp->neighbours = nn;
					else{
						
						Neighbour *temp2 = tempp->neighbours;
						
						while(temp2->next != NULL)
							temp2 = temp2->next;
							
						temp2->next = nn;
						
					}
				 
				}
			}
			
			void Display(){
				
				
				Node *temp = head;
				
				while(temp!=NULL){
					
					cout<<temp->data<<": ";
					Neighbour *n = temp->neighbours;
					
					while(n != NULL){
						
						cout<<n->data<<"  ";
						n = n->next;
					}
					
					cout<<endl;
					temp = temp->next;
				}
				
			}
			
			void BFS(int start){
				
				int pred[100];
				
				queue<int>q;
				
				Node *temp = head;
				
				while(temp->data != start){
					
					temp = temp->next;
					
				}
				
				q.push(temp->data);
				temp->color = "black";
				pred[temp->data] = -1;
				
				do{
					
					Neighbour *n = temp->neighbours;
					
					
					while(n != NULL){
						
						Node *tt = head;
						
						while(tt->data != n->data){
					
							tt = tt->next;
					
						}
						
						if(tt->color == "white"){
							
							q.push(n->data);
							tt->color = "black";
							pred[n->data] = temp->data;
						}
						
						n = n->next;
			
					}
					
					cout<<q.front()<<"  ";
					q.pop();
					int p = q.front();
					
					Node *cc = head;
						
					while(cc->data != p){
					
						cc = cc->next;
					
					}
					
					temp = 	cc;
					
				}while(!q.empty());
				
				for(int i = start; pred[i] != -1; i++){
					
					cout<<i<<"->"<<pred[i];
					
				}
				
			}
			
			void DFS(int v){
				
				stack<int>s;
				
				Node *temp = head;
				
				while(temp->data != v)
					temp = temp->next;
					
					
				visited[temp->data] = true;
				s.push(temp->data);
				
				while(!s.empty()){
					
					int b = s.top();
					cout<<b<<"  ";
					s.pop();
					
					Neighbour *n = temp->neighbours;
					
					while(n != NULL){
						
						if(visited[n->data] == false){
							
							s.push(n->data);
							visited[n->data] = true;
							
						}
						
						n = n->next;
					}
					
					int p = s.top();
					
					Node *tt = head;
						
					while(tt->data != p){
					
						tt = tt->next;
					
					}
					
					temp = tt;
					
				}
    		
			}
};

int main(){
	
	Graph g;
	
	g.Vertex(1);
	g.Vertex(2);
	g.Vertex(3);
	g.Vertex(4);
	g.Vertex(5);
	
	
	g.Edge(1,2,10);
	g.Edge(1,5,10);
	g.Edge(5,3,10);
	g.Edge(5,4,10);
	g.Edge(4,2,10);
	
	g.Display();
	//g.DFS(3);
	
	g.BFS(2);
	
	return 0;
}
