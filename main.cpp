#include "Thread.h"
#include "MyThread.h"
#include "Mutex.h"

class MutexTest : public Thread
{

public:
    MutexTest (Mutex& mutexobj): mutex(mutexobj) {}
    void* run ()
    {

        cout << "Thread" << (unsigned long int)self() << " is waiting for the mutex" << endl;
        mutex.lock ();
        cout << "Thread" << (unsigned long int)self() << " acquired the mutex" << endl;
        sleep (10);
        mutex.unLock();
        cout << "Thread" << (unsigned long int)self() << " unlocked the mutex" << endl;
        return NULL;
    }

private:
    Mutex &mutex;
};


int main (int argc, char **argv)
{


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

    Mutex mutex;
    MutexTest mTest(mutex);
    mTest.start ();

    cout << "Main Thread is waiting for the mutex" << endl;
    mutex.lock ();
    cout << "Main Thread acquired the mutex" << endl;
    sleep (5);
    mutex.unLock ();
    cout << "Main Thread unlocked the mutex" << endl;

    //tells the main thread should wait for the spawned thread completes its execution.
    mTest.join ();

    return 0;
}
