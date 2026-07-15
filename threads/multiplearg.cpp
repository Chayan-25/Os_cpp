#include <iostream>
#include <pthread.h>
using namespace std;

struct Data
{
    int a,b;
};

void* add(void* arg)
{
    Data *d=(Data*)arg;

    cout<<"Sum = "<<(d->a)+(d->b)<<endl;

    return NULL;
}

int main()
{
    pthread_t t;
    Data d;

    cout<<"Enter two numbers: ";
    cin>>d.a>>d.b;

    pthread_create(&t,NULL,add,&d);
    pthread_join(t,NULL);

    return 0;
}