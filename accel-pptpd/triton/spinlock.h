#ifndef __TRITON_SPINLOCK_H
#define __TRITON_SPINLOCK_H

#ifdef USE_SPINLOCK
typedef unsigned char spinlock_t;
#define spin_lock(l) {while(__sync_lock_test_and_set(l,1));}
#define spin_unlock(l) __sync_lock_release(l)
#define SPINLOCK_INITIALIZER 0
#define spinlock_init(l) {*(l)=0;}
#else
#include <pthread.h>
typedef pthread_mutex_t spinlock_t;
#define spin_lock(l) pthread_mutex_lock(l)
#define spin_unlock(l) pthread_mutex_unlock(l)
#define SPINLOCK_INITIALIZER PTHREAD_MUTEX_INITIALIZER
#define spinlock_init(l) pthread_mutex_init(l,NULL)
#endif

#endif

