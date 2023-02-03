#include <iostream>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <stdio.h>
#include <cstdlib> 
using namespace std;

void arrFill(int* arr, int N)
{
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 65536;
}

void bubbleSort(int* arr, int N)
{
    int temp = 0;
    bool exit = false;

    while (!exit)
    {
        exit = true;
        for (int i = 0; i < (N - 1); i++)
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                exit = false;
            }
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void RadixSortLSD(int* arr, int arraySize)
{

    int N = 10000;
    int* bucket = new int[N];
    int i, maxVal = 0, digitPosition = 1;
    for (i = 0; i < arraySize; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    int pass = 1;
    while (maxVal / digitPosition > 0) {
        int* digitCount = new int[N];
        int digitCount = { 0 };

        for (i = 0; i < arraySize; i++)
            digitCount[arr[i] / digitPosition % N]++;


        for (i = 1; i < N; i++)
            digitCount[i] += digitCount[i - 1];


        for (i = arraySize - 1; i >= 0; i--)
            bucket[--digitCount[arr[i] / digitPosition % N]] = arr[i];

        for (i = 0; i < arraySize; i++)
            arr[i] = bucket[i];

        digitPosition *= N;
    }

}


int main()
{
       setlocale(LC_ALL, "Russian");
       unsigned long int t;
    clock_t start, stop; 
    int N;
    cout << "Введите количество элементов: ";
    cin >> N;

    int* arr = new int[N];
 

    arrFill(arr, N);
    

    char K, B, Q, R;
    cout << "Введите вид сортировки(B or Q or R): ";
    cin >> K;

    if (K == 'B') {
    start = clock();
    bubbleSort(arr, N);
    stop = clock();
    for (int i = 0; i < N; i++)
    {
        cout << "Sorted array: \n";
        cout << setw(1) << arr[i] << "  ";
    }}
    else if (K == 'Q') {
        start = clock();
        quickSort(arr, 0, N - 1);
        stop = clock();
        cout << "Sorted array: \n";
        printArray(arr, N);

    }
    else if (K == 'R') {
       
        start = clock();
        RadixSortLSD(arr, N - 1);
        stop = clock(); 
        cout << "Sorted array: \n";
        printArray(arr, N);
    }
    delete[] arr;

    cout << '\t';
    cout << "\n\n";
    cout << "Такты процессора: " << (stop - start) << ";\n Сделано за " << ((float)(stop - start)) / CLOCKS_PER_SEC << " секунд." << endl;

    system("pause");
    return 0;
}

