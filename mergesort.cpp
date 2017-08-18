#include <iostream>
#include <string>

using namespace std;

template< class T>
void showarray(T data[], int n) {
	for(int i=0;i<n;i++)
		cout << data[i] << " ";
}

template<class T>
void merge(T data[], T temp_array[], int low, int middle, int high) {
	
	// create a temporary array ... O(N) memory complexity !!!		
	// copy the data to a temporary array 
	for(int i=low;i<=high;i++) {
		temp_array[i] = data[i];
	}
	
	int i = low;
	int j = middle + 1;
	int k = low;
	
	// Copy the smallest values from either the left or the right side back
    // to the original array
	while( (i<=middle) && (j<=high) ) {	
		if( temp_array[i] <= temp_array[j] ) {
			data[k] = temp_array[i];
			i++;
		} else {
			data[k] = temp_array[j];
			j++;
		}
		
		k++;
	}
	
	// Copy the rest of the left side of the array into the target array
    while (i <= middle) {
        data[k] = temp_array[i];
        k++;
        i++;
    }
	
	// Copy the rest of the right side of the array into the target array
    while (j <= high) {
        data[k] = temp_array[j];
        k++;
        j++;
    }
}

template<class T>
void mergesort(T data[], T temp[], int low, int high) {
	
	if( low >= high) {
		return;
	}		
	
	int middle_index = (low+high)/2;
	
	mergesort(data, temp, low, middle_index);
	mergesort(data, temp, middle_index+1, high);
	merge(data, temp, low, middle_index, high);
}

template<class T>
void sort(T data[], T temp[], int n) {
	mergesort(data, temp, 0, n-1);
}

main() {
    
	char data[] = {'b','a','c','z'};
	int n = sizeof(data)/sizeof(data[0]);
	
	char temp[n];
	
	sort(data, temp, n);
	showarray(data, n);
}