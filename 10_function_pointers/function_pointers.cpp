#include <iostream>
using namespace std; 

int Sum(int array[], int length);
int Average(int array[], int length);

void Output(int array[], int length, int (*Function)(int array[], int length));

int main(){
    int array[] = {2,3,4,5,6};
    Output(array,5,Sum);
    Output(array,5,Average);
    return 0;
}


int Sum(int array[], int length){
    int sum = 0;

    for (int r = 0; r < length; r++)
    {
        sum+=array[r];
    }
    return sum;
}

int Average(int array[], int lenght){
    return Sum(array,lenght) / lenght;
}

void Output(int array[], int length, int (*Function)(int array[], int length)){
    cout << "Result is: " << Function(array,length) << endl;
}