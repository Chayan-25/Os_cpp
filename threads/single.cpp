#include <iostream>
#include <pthread.h>
using namespace std;

void* display(void* arg)
{
    cout << "Hello from 2nd Thread!" << endl;
    return NULL;
}

int main()
{
    pthread_t t;

    pthread_create(&t, NULL, display, NULL);
    pthread_join(t, NULL);

    cout << "Hello from Main Thread!" << endl;

    return 0;
}