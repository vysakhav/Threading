#include "MyThread.h"



void* MyThread :: run (){
            int i;
            printf ( "Thread %u started\n",(unsigned int)self ());
            for ( i = 0 ; i < 5 ; ++i ){
                printf ( "Thread %u running %d\n", (unsigned int)self (), i+1);
                sleep (2);
            }

            printf ("Thread %u done\n" , (unsigned int)self());
            return NULL;
}
