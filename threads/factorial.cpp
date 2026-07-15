#include <iostream>
#include <pthread.h>
using namespace std;

long long fact=1;

void* factorial(void* arg)
{
    int n=*(int*)arg;

    for(int i=1;i<=n;i++)
        fact*=i;

    return NULL;
}

int main()
{
    pthread_t t;
    int n;

    cout<<"Enter number whose factorial you want : ";
    cin>>n;

    pthread_create(&t,NULL,factorial,&n);
    pthread_join(t,NULL);

    cout<<"Factorial = "<<fact<<endl;

    return 0;
}