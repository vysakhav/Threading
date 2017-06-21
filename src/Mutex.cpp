#include "Mutex.h"

Mutex::Mutex ()
{
    pthread_mutex_init (&m_mutex, NULL);
}

Mutex::~Mutex ()
{
    pthread_mutex_unlock (&m_mutex);
    pthread_mutex_destroy (&m_mutex);
}

int Mutex::lock ()
{
    return pthread_mutex_lock (&m_mutex);
}

int Mutex::tryLock ()
{
    return pthread_mutex_trylock (&m_mutex);
}

int Mutex::unLock()
{
    return pthread_mutex_unlock (&m_mutex);
}

int Mutex::destroy()
{
    return pthread_mutex_destroy (&m_mutex);
}
