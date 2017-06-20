#include "Thread.h"
Thread::Thread()
{
    //ctor
    m_running = 0;
    m_detached = 0;
    m_tid = 0;
}

Thread::~Thread()
{
    //dtor
    if ( m_running == 1 && m_detached == 0)
        pthread_detach(m_tid);

    if (m_running)
        pthread_cancel (m_tid);
}

/**
 * @brief This static function is passed in pthread create.
 *
 */
static void* runThread(void* args) {
    return ((Thread*)args) -> run ();
}


void Thread::start (){
    int res;
    res = pthread_create (&m_tid, NULL, &runThread, (void*)this);
    if ( 0 == res){
        m_running = 1;
    }
}


void Thread::join (){
    int res;
    if ( m_running == 1){
        res = pthread_join (m_tid, NULL);
        if ( 0 == res ){
            m_detached = 0;
        }
    }
}

void Thread::detach (){
    int res;
    if ( m_detached == 0){
        res = pthread_detach (m_tid);
        if ( 0 == res)
            m_detached = 1;
    }
}

pthread_t Thread::self (){
    return m_tid;
}
