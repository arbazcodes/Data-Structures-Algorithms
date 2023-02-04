#include<iostream>
using namespace std;

void Insertion(int arr[]){
	
	
	for(int i = 1; i < 10; i++){
		
		int curr = arr[i];
		int j = i-1;
			
			while(arr[j] > curr && j>=0){
				
				arr[j+1] = arr[j];
				j--;
			}
			
			arr[j+1] = curr;
		}
		
	}
	




int main(){
	
	int array[10];
	array[0] = 9;
	array[1] = 4;
	array[2] = 2;
	array[3] = 5;
	array[4] = 3;
	array[5] = 7;
	array[6] = 1;
	array[7] = 8;
	array[8] = 10;
	array[9] = 6;

	Insertion(array);
	
	for(int j = 0; j < 10; j++){
		
		cout<<array[j]<<"  ";
			
	}
	
	return 0;
	
}
