#include <iostream>
using namespace std;

int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(int arr[], int n) {
    return (double)calculateSum(arr, n) / n;
}

int findMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Error: Please enter a positive number." << endl;
        return 1;
    }
    
    int arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(arr, n) << endl;
    cout << "Average: " << calculateAverage(arr, n) << endl;
    cout << "Maximum: " << findMaximum(arr, n) << endl;
    cout << "Minimum: " << findMinimum(arr, n) << endl;
    
    return 0;
}