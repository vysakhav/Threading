#include "Thread.h"
#include "MyThread.h"
int main (int argc, char **argv){

    MyThread* thread1 = new MyThread;
    MyThread* thread2 = new MyThread;

    thread1 -> start ();
    thread2 -> start ();

    thread1 -> join ();
    thread2 -> join ();

    thread1 -> detach ();
    thread2 -> detach ();

    delete thread1;
    delete thread2;

    return 0;
}
