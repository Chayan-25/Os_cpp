#include <iostream>
#include <pthread.h>
using namespace std;

int sum=0;

void* add(void* arg)
{
    int n = *(int*)arg;

    for(int i=1;i<=n;i++)
        sum+=i;

    return NULL;
}

int main()
{
    pthread_t t;
    int n;

    cout<<"Enter numbers of element : ";
    cin>>n;

    pthread_create(&t,NULL,add,&n);
    pthread_join(t,NULL);

    cout<<"Sum = "<<sum<<endl;

    return 0;
}