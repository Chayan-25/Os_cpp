#include <iostream>
#include <pthread.h>
using namespace std;

void* square(void* arg)
{
    int *n=(int*)arg;

    int *result=new int;

    *result=(*n)*(*n);

    pthread_exit(result);
}

int main()
{
    pthread_t t;
    int n;

    cout<<"Enter number whose sqare you need : ";
    cin>>n;

    void* ans;

    pthread_create(&t,NULL,square,&n);

    pthread_join(t,&ans);

    cout<<"Square = "<<*(int*)ans<<endl;

    delete (int*)ans;

    return 0;
}