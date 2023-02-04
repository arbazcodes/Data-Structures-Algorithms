#include<iostream>
using namespace std;

class Hash{
	
	private:
		
		int *hash_array;
		int size;
		
	public: 
	
		Hash(int s){
			
			size = s;
			hash_array = new int[size];
			for(int i = 0; i < size; i++){
					
			hash_array[i] = -1;	
					
			}
		}
		
		int hash_func(int k){
			
			return k % size;
			
		}
		
		void insert(int k){
			
			int hash_index = hash_func(k);
			
			if(hash_array[hash_index] == -1){
			
				hash_array[hash_index] = k;
			
			}else{
				
				int index;
				
				for(int i = 1; i < size; i++){
					
					index = (hash_index + (i*i))  % size;
					
					if(hash_array[index] == -1){
						
						hash_array[index] = k;
						break;
					}
					
				}
				
			}
			
		}
		
		void Display(){
			
			
			for(int i = 0; i < size; i++){
					
				cout<<i<<": "<<hash_array[i]<<endl;	
					
			}
			
		}
	
};

int main(){
	
	Hash h(10);
	
	h.insert(43);
	h.insert(135);
	h.insert(72);
	h.insert(23);
	h.insert(99);
	h.insert(19);
	h.insert(82);
	
	h.Display();
	
	return 0;
}
