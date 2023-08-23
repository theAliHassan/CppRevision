#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;

}

void printArray(int* array, int sizeArray)
{
    if (array == NULL || sizeArray <= 0)
        return;
    for (int i = 0; i < sizeArray; i++) {
        cout << array[i] << " ";
    }
    return;
}

int getCountPrimeNumbers(int lowerLimit, int upperLimit)
{
    int count = 0;
    for (int i = lowerLimit; i < upperLimit; i++)
        if (isPrime(i))
            count++;
    return count;
}

int* savePrimeList(int lowerLimit, int upperLimit)
{
    int countPrime = getCountPrimeNumbers(lowerLimit, upperLimit);
    int* primeNumbers = new int[countPrime];

    for (int i = lowerLimit, j = 0; i < upperLimit; i++)
    {
        if (isPrime(i))
        {
            primeNumbers[j] = i;
            j++;
        }
    }
    return primeNumbers;
}

void getPrimeNumbers(int x, int y)
{
    if (x <= 1 && y <= 1)
        return;
    int* list = NULL;
    if (x > y)
    {
        list = savePrimeList(y, x);
        printArray(list, getCountPrimeNumbers(y, x));
    }
    else
    {
        list = savePrimeList(x, y);
        printArray(list, getCountPrimeNumbers(x, y));
    }
    delete[] list;
    return;
}
int main()
{
    int lowerLimit = 1;
    int UpperLimit = 100;
    getPrimeNumbers(lowerLimit, UpperLimit);
    return 0;
}