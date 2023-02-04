#include <iostream>
using namespace std;

class Hash{
	private:
		int *hash_array;
		int size;
	public:
		Hash(int s){
			size = s;
			hash_array = new int[size];
			for(int i = 0 ; i<size ; i++){
	         hash_array[i]= -1;
		   }
		}
		int hash_func(int k){
			return k%size;
		}
		void insert(int k){
			int hash_index = hash_func(k);
			if(hash_array[hash_index]==-1){
				hash_array[hash_index] = k;
			}else{
				int index;
				for(int i =0 ; i< size ; i++){
					index = (hash_index+(i*i))%size;
					if(hash_array[index]==-1){
						hash_array[index]=k;
						break;
					}
				}
			}
		}
		void display(){
			
			for(int i = 0 ; i< size ; i++){
				cout<<" "<<i<<": "<<hash_array[i]<<"\n";
				
			}
		}
	
};


int main(){
	Hash h(10);
	h.insert(3);
	h.insert(4);
	h.insert(5);
	h.insert(28);
	h.insert(12);
	h.insert(10);
	h.insert(20);
	h.insert(69);
	
	h.display();	
	
	
	return 0;
}
