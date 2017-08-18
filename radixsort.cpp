#include <iostream>

using namespace std;

const int BUCKET_SIZE = 10;

int get_max(int data[], int n) {
    int max = data[0];
	
    for (int i = 1; i < n; i++)
        if (data[i] > max)
            max = data[i];
    
	return max;
}
 
void counting_sort(int data[], int n, int exp)
{
    int temp_array[n]; 
	int counter_array[BUCKET_SIZE] = {0};
 
    for (int i = 0; i < n; i++)
        counter_array[ (data[i]/exp)%BUCKET_SIZE ]++;
 
    for (int i = 1; i < BUCKET_SIZE; i++)
        counter_array[i] += counter_array[i - 1];
 
    for (int i = n - 1; i >= 0; i--) {
        temp_array[counter_array[ (data[i]/exp)%BUCKET_SIZE ] - 1] = data[i];
        counter_array[ (data[i]/exp)%BUCKET_SIZE ]--;
    }
 
    for (int i = 0; i < n; i++)
       data[i] = temp_array[i];
	
}
 
void radix_sort(int data[], int n) {
   
    int maximum = get_max(data, n);

    for (int exp = 1; maximum/exp > 0; exp *= 10) {
		counting_sort(data, n, exp);
	}     
}
 
void print_array(int data[], int n) {
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
}
 
int main() {
    int data[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(data)/sizeof(data[0]);
    radix_sort(data, n);
    print_array(data, n);
    return 0;
}