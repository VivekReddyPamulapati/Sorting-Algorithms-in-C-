#include <iostream>

using namespace std;

template<class T>
void selectionsort(T nums[], int n) {
	
	for(int i=0;i<n-1;i++){
		
		int index = i;
		
		for(int j=i+1;j<n;j++){
			if( nums[j] < nums[index] )
				index = j;
		}
		
		// we do not want to swap the item with itself !!!
		if( index != i ) {
			swap(nums[i], nums[index]);
		}	
	}		
}

template<class T>
void swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template< class T>
void showarray(T data[], int n) {
	for(int i=0;i<n;i++)
		cout << data[i] << " ";
}

main() 
{
    
	int nums[] = {5,4,3,2,1,0};
	
	cout << n << endl;
	
	selectionsort(nums, n);
	showarray(nums, n);
}