#include <iostream>
#include <string>

using namespace std;

template<class T>
void showarray(T data[], int n) {
	for(int i=0;i<n;i++)
		cout << data[i] << " ";
}

template<class T>
void swp(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template<class T>
bool sorted(T data[], int n) {
	
	for(int i=0;i<n-1;i++) {
		if( data[i+1] < data[i] ) {
			return false;
		}
	}
	
	return true;
}

//  Fisher-Yates algorithm in order to shuffle an array 
//	 	The algorithm produces an unbiased permutation: every permutation is equally likely 
//	  		O(N) running time ~ proportional to the number of items we want to shuffle
//				 + in-place algorithm !!!  
template<class T>
void shuffle(T data[], int n) {
	
	for(int i=n-1;i>=0;i--) {
		int j = (int) (((double) rand() / (RAND_MAX)) * i);
		swp(data[i], data[j]);
	}
}

template<class T>
void sort(T data[], int n) {
	
	int loop_counter = 0;
	
	while( !sorted(data, n) ) {
		loop_counter++;
		shuffle(data, n);
	}
	
	cout << "Steps required to sort array: " << loop_counter << endl;
}

main() {
	
	int data[] = {1,100,56,-3,1,2,5,4,-2,10,20,4,1,-5,12,45};
	int n = sizeof(data)/sizeof(data[0]);
	
	sort(data, n);
	showarray(data, n);
}