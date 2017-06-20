/**
 * @File: Thread.h
 *
 * Header file for the thread class.
 *
 * @Description: This thread class mimic Java thread class. Defined start,join,detach public interfaces and implement a static
 * method runThread to run the thread.
 *
 * @Author: Vysakh A V
 * @Date: 2017-06-20
 *
 * Courtesy: https://vichargrave.github.io
 */

#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <iostream>
using namespace std;



/**
 * @class Thread
 * @brief Defines a class to create new thread.
 * It implements methods to start, join, and detach new threads.
 *
*/

class Thread
{
    public:

        /**
         * @brief Default constructor.
         *
        */
        Thread();

        /**
         * @brief Invoked pthread_detach and pthread_cancel if thread is running, so release will go back to the system
         *
        */
        virtual ~Thread();

        /**
         * @brief This function is used to join the thread, so the calling thread will wait for this thread to complete
         * its execution. using pthread_join (tid,NULL). Call pthread_join if thread is running.
         *
         * @Return NULL
         *
        */
        void join ();

        /**
         * @brief This function is used to detach the thread, so the thread will detached from the calling thread
         * and release the resources back to the syste, using pthread_detach (tid). Call pthread_detach if thread is not detached.
         *
         * @Return NULL
         *
        */
        void detach ();

        /**
         * @brief This function is used to start the thread. using pthread_create(&tid,NULL,<fun ptr>,args).
         * It will invoked the runThread() statuic function as it passed as argument in pthread_create ().
         *
         * @Return NULL
         *
        */
        void start ();

        /**
         * @brief This virtual function makes the class as abstract. This function should override in subclass. The action
         * the thread will do define in this overrided run method.
         * @Return NULL
         *
        */
        virtual void* run () = 0;

         /**
         * @brief This function returns the thread ID.
         *
         * @Return Thread ID.
         *
        */
        pthread_t self();

    private:
        //Thread ID.
        pthread_t m_tid;
        //To check whether thread is running, 0 if it is not running 1 otherwise.
        int m_running;
        //To check whether the thread is detached, 0 if it is detached 1 otherwise.
        int m_detached;
};


#endif // THREAD_H
