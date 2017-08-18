#include <iostream>

using namespace std;

template<class T>
void shellsort(T data[], int n) {
	
	for(int gap=n/2;gap>0;gap=gap/2) {
		
		for(int i=gap;i<n;i++) {
			
			int j = i;
			
			while( (j>=gap) && (data[j-gap] > data[j]) ) {
				swap(data[j],data[j-gap]);
				j = j - gap;
			}
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
void showArray(T data[], int n) {
	for(int i=0;i<n;i++)
		cout << data[i] << " ";
}

main() 
{
    
	int data[] = {1,-2,5,6,3,-3,11,10};
	int n = sizeof(data)/sizeof(data[0]);
	
	shellsort(data, n);
	showArray(data, n);
}