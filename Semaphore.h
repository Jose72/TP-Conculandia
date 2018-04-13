#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

#define SEMAPHORE_OK 0
#define ERROR_FTOK -1
#define ERROR_SEMGET -2

#define DEFAULT_NUM 25

typedef struct {
    int id;
    int init_val;
} Semaphore;


union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};


int Semaphore_init(Semaphore *S, const char *filename, int init_val);

int Semaphore_v(Semaphore *S); //incrementar (signal, unlock, leave or release)

int Semaphore_p(Semaphore *S); //decrementar (wait, lock, enter, or get)

int Semaphore_eliminar(Semaphore *S);

#endif //SEMAPHORE_H
