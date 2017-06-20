#ifndef _H_MYTHREAD_H_
#define _H_MYTHREAD_H_

#include "Thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @class MyThread
 * @brief Defines a class to create new thread.
 * It extends the Thread class and override the virtual function run.
 *
*/
class MyThread : public Thread {

    public:

        /*
         * #@brief Override the virtual function and define the task the thread needs to do.
         *
         */

        void* run ();
};
#endif
