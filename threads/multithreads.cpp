#include <iostream>
#include <pthread.h>
using namespace std;

void* print(void* arg)
{
    int id = *(int*)arg;
    cout << "Thread " << id << " is running." << endl;
    return NULL;
}

int main()
{
    pthread_t threads[5];
    int id[5];

    for(int i=0;i<5;i++)
    {
        id[i]=i+1;
        pthread_create(&threads[i], NULL, print, &id[i]);
    }

    for(int i=0;i<5;i++)
        pthread_join(threads[i], NULL);

    return 0;
}