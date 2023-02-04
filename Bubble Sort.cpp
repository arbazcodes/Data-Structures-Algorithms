#include<iostream>
using namespace std;

void Bubble(int arr[]){
	
	
	for(int i = 0; i <= 9; i++){
		
		for(int j = i + 1; j < 10; j++){
			
			if(arr[j] < arr[i]){
				
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			
			}
			
			
		}
		
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

	Bubble(array);
	
	for(int j = 0; j < 10; j++){
		
		cout<<array[j]<<"  ";
			
	}
	
	return 0;
	
}
