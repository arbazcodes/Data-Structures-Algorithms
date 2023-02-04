#include<iostream>
using namespace std;

class BST{
	
	private:
		struct Node{
			
			int value;
			Node *left, *right;
			int height;
		};
		
		
		
		Node *root;
		
		int max(int a, int b){
			
			if(a>b)
				return a;
			else
				return b;
			
		}
		
		int height(Node *r){
			
			if(r == NULL){
				
				return 0;
				
			}else{
				
				return r->height;
				
			}
			
		}
		
		int BF(Node *r){
			
			if(r == NULL)
				return 0;
				
			else
				return height(r->left)-height(r->right);
			
		}
		
		Node *leftRotation(Node *y){
			
			Node *x = y->right;
			Node *T = x->left;
			
			x->left = y;
			y->right = T; 
			
			x->height = max(height(x->left), height(x->right)) + 1;
			y->height = max(height(x->left), height(x->right)) + 1;
			
			return x;
		}
		
		Node *rightRotate(Node *x){
			
			Node *y = x->left;
			Node *T2 = y->right;
			
			y->right = x;
			x->left = T2;
			
			x->height = max(height(x->left), height(x->right)) + 1;
 			y->height = max(height(y->left), height(y->right)) + 1;
			
			return y;
		}
		
		Node *insert(Node *r, Node *n){
			
			if(r == NULL){
					
				r = n;
				return r;
					
			}else if(r->value > n->value){
				
				r->left = insert(r->left, n);
				
			}else if(r->value < n->value){
				
				r->right = insert(r->right, n);
				
			}else{
				
				cout<<"Duplicate not allowed."<<endl;
				return r;
			}
			
			int bf = BF(r);
			
			if(bf > 1 &&  n->value < r->left->value){
				
				return rightRotate(r);
				
			}else if(bf < -1 && n->value > r->right->value){
				
				return leftRotation(r);
				
			}else if(bf > 1 && n->value > r->left->value){
				
				r->left = leftRotation(r->left);
				return rightRotate(r);
				
			}
			else if(bf < -1 && n->value < r->right->value){
				
				r->right = rightRotate(r->right);
				return leftRotation(r);
				
			}
			
			return r;
		}
		
		Node *deleteNode(Node *r, int k){
			
			if(r==NULL)
				return r;
			
			else if(k > r->value)
				r->right = deleteNode(r->right, k);
				
			else if(k < r->value)
				r->left = deleteNode(r->left, k);	
			
			else{
				
				Node *temp;
				
				if(r->left == NULL){
				
					temp = r->right;
					delete r;
					return temp;

				}else if(r->right == NULL){
					
					temp = r->left;
					delete r;
					return temp;
					
				}else{
					
					temp = r->right;
					
					while(temp->left){
						
						temp = temp->left;
						
					}
					
					temp->left = r->left;
					temp = r->right;
					delete r;
					r = temp;
				}
				
				int bf = BF(r);
				
				if(bf == 2 &&  BF(r->left) >= 0){
					
					return rightRotate(r);
					
				}else if(bf == 2  && BF(r->left) == -1){
				
					r->left = leftRotation(r->left);
					return rightRotate(r);
				}else if(bf == -2 &&  BF(r->right) <= 0){
					
					return leftRotation(r);
					
				}else if(bf == -2  && BF(r->left) == 1){
				
				
					r->right = rightRotate(r->right);
					return leftRotation(r);
				}
				
				return r;
			
			}
			
		
			
	}
		void displayInorder(Node *r){
			
			if(r == NULL)
				return;
			
			displayInorder(r->left);
			cout<<r->value<<"  ";
			displayInorder(r->right);	
		}
		
		
	public:
	
		
		/*void Insert(int k){
			
			Node *newNode = new Node;
			newNode->value = k;
			newNode->left = newNode->right = NULL;
			
			if(root == NULL){
				
				root = newNode;
				
			}else {
				
				Node *temp = root;
				
				
					
					while(temp != NULL){
					
						if(temp->value > k){
							
						if(temp->left != NULL){
						
							temp = temp->left;
						
						}else{
						
							temp->left = newNode;
							break;
						
						}
					}else if(temp->value < k){
						
						if(temp->right != NULL){
							
							temp = temp->right;
							
						}else{
							
							temp->right = newNode;
							break;
							
						}
						
						
					}
		
			}
	
		}
		
	}*/
	
	
	void removeNode(int k){
		
		deleteNode(root, k);
		
	}
	
	void Inorder(){
		
		displayInorder(root);
		
		
	}
	
	void Add(int k){
		
		Node *newNode = new Node;
		newNode->value = k;
		newNode->left = newNode->right = NULL;
		newNode->height = 1;
		root = insert(root, newNode);
		
	}
	
};


int main(){
	
	BST t;
	
	t.Add(5);
	t.Add(9);
	t.Add(8);
	t.Add(6);
	t.Add(7);
	
	t.Inorder();
	cout<<endl;
	
	t.removeNode(7);
	
	t.Inorder();
	
	return 0;
}
