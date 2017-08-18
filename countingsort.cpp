#include <iostream>

using namespace std;

const int BUCKET_SIZE = 10;

void print_array(int *data, int n) {
    for ( int i = 0; i < n; i++ ) {
		cout << data[i] << " ";
	}
}

void counting_sort(int* data, int n) {
    
	int count_array[BUCKET_SIZE] = { 0 };
	int output_array[n];

    for (int i=0;i<n;i++) {
        count_array[data[i]]++; 
    }

    for(int i=1;i<BUCKET_SIZE;i++) {
		count_array[i] += count_array[i-1];
	}
	
	for(int i=0;i<n;i++) {
		output_array[ count_array[data[i]]-1] = data[i];
		count_array[data[i]]--;
	}
	
	for(int i=0;i<n;i++) {
		data[i] = output_array[i];
	}
}

int main()
{
    int data[] = {5,4,7,6,1,2,9,8,0};
	int n = sizeof(data)/sizeof(data[0]);	
	
    counting_sort(data, n);
    print_array(data, n);
    
	return 0;
}