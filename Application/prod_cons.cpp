#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int item=0;

pthread_mutex_t mutex;

void* producer(void*)
{
    pthread_mutex_lock(&mutex);

    item=100;
    cout<<"Produced "<<item<<endl;

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* consumer(void*)
{
    sleep(1);

    pthread_mutex_lock(&mutex);

    cout<<"Consumed "<<item<<endl;

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_t p,c;

    pthread_mutex_init(&mutex,NULL);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}