/********************************************************************************************************
 * @File : pthread_mutex.h
 *
 * @brief This is a wrapper class to lock/unlock mutex.
 * Mutex is used to when multiple threads wants the synchronize access to the shared resources. Mutex
 * enables thread to block the other threads to access the shared resource.
 * Pthread Mutex functions:
 * ***pthread_mutex_init (pthread_mutex_t&, pthread_attr)
 * ***pthread_mutex_lock()
 * ***pthread_mutex_trylock ()
 * ***pthread_mutex_unlock ()
 * ***pthread_mutex_destroy ()
 * ******************************************************************************************************/
#ifndef __H_MUTEX_H__
#define __H_MUTEX_H__

/**
 * class Mutex
 *
 * @brief This class defined the interface to create,lock and unlock the mutex.
 * Defined wrapper functions for pthread mutex functions.
 *
 * @author: Vysakh
 * @Date  : 2007/06/21
 */

#include <iostream>
#include <pthread.h>
using namespace std;

class Mutex
{

public:

    /**
     * Mutex () constructor.
     */
    Mutex ();

    /**
     * Destructor. Make it as virtual for the proper relase of resouces in child classes too.
     */
    virtual ~Mutex ();

    /**
     * lock ()
     *
     * @brief This function used to lock the mutex.
     *
     * This function used the pthread_mutex_lock () and returned its return value.
     *
     * @arg NULL
     * @return Return value of pthread_mutex_lock.
     */
    int lock ();

    /**
     * tryLock ()
     *
     * @brief This function used to lock the mutex.
     *
     * This function used the pthread_mutex_trylock () and returned its return value. It check whether the mutex
     * is free, if so locked it otherwise returned not waiting till the lock is acquired.
     *
     * @arg NULL
     * @return Return value of pthread_mutex_trylock.
     */
    int tryLock ();

    /**
     * unLock ()
     *
     * @brief This function used to unlock the mutex.
     *
     * This function used the pthread_mutex_unlock () and returned its return value.
     *
     * @arg NULL
     * @return Return value of pthread_mutex_unlock.
     */
    int unLock ();

    /**
     * destroy ()
     *
     * @brief This function used to destroy the mutex.
     *
     * This function used the pthread_mutex_destroy () and returned its return value.
     *
     * @arg NULL
     * @return Return value of pthread_mutex_destroy.
     */
    int destroy ();

private:
    pthread_mutex_t m_mutex;
};

#endif


