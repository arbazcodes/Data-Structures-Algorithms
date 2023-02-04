#include<iostream>
using namespace std;

struct Node{

    int data;
    Node *next;

};


int size = 8;

int hash_func(int key){

    return (key % size);

}

void insert(int key, Node *hash_array[]){

    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = NULL;

    int hash_index = hash_func(key);

    if(hash_array[hash_index] == NULL){
		
        hash_array[hash_index] = newNode;

    }else{

        Node *temp = hash_array[hash_index];

        while(temp->next != NULL){

            temp = temp->next;

        }

        temp->next = newNode;

    }


}


void Search(int key, Node *hash_array[]){

    int hash_index = hash_func(key);
    
    Node *temp = hash_array[hash_index];

    while(temp->data != key && temp != NULL){

        temp = temp->next;

    }

    if(temp == NULL){

        cout<<endl<<"Value not found."<<endl;

    }else{

        cout<<endl<<"Searched value '"<<temp->data<<"' found at index: "<<hash_index<<endl;

    }

}


void Delete(int key, Node *hash_array[]){
	
	int hash_index = hash_func(key);
	
	Node *temp = hash_array[hash_index];
	
	
	
	if(temp->data == key){
		
		hash_array[hash_index] = temp->next;
		delete temp;
		cout<<endl<<"Value deleted."<<endl;	
		
	}else if(temp->next == NULL){
		
		hash_array[hash_index] = NULL;
		delete temp;
		cout<<endl<<"Value deleted."<<endl;
		
	}else{
		Node *prev = NULL;
		
		while(temp->data != key && temp != NULL){
			
			prev = temp;
			temp = temp->next;
			
		}
		
		if(temp == NULL){
			
			cout<<endl<<"Value not found"<<endl;
			
		}else{
			
			prev->next = temp->next;
			delete temp;
			cout<<endl<<"Value deleted."<<endl;
		}
		
	}
	
}


void Display(Node *hash_array[]){

    for(int i = 0; i < size; i++){

        Node *temp = hash_array[i];

        cout<<"At index("<<i<<"): ";

        while(temp != NULL){

            cout<<temp->data;
            temp = temp->next;
            
            if(temp != NULL){
            	
            	cout<<", ";
            	
			}
			
        }

        cout<<endl;

    }

}



int main(){

    Node *hash_array[size];

    for(int i = 0; i < size; i++){

        hash_array[i] = NULL;

    }


    insert(76, hash_array);
    insert(93, hash_array);
    insert(40, hash_array);
    insert(47, hash_array);
    insert(10, hash_array);
    insert(55, hash_array);

    Display(hash_array);
    
	Search(93, hash_array);
	
	Delete(40, hash_array);

	 cout<<endl;
	
	Display(hash_array);

    return 0;
}
