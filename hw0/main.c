#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    
    // get maximum stack size
    if (getrlimit(RLIMIT_STACK, &lim) != 0) {
        printf("The stack limit cannot be obtained\n");
    } else {
        printf("maximum stack size: %ld\n", (long)lim.rlim_cur);
    }
    
    
    // get maximum number of processes
    if (getrlimit(RLIMIT_NPROC, &lim) != 0) {
        printf("The number of processes cannot be obtained\n");
    } else {
        printf("maximum number of processes: %ld\n", (long)lim.rlim_cur);
    }
    
    // get maximum number of file descriptor
    if (getrlimit(RLIMIT_NOFILE, &lim) != 0) {
        printf("The number of file descriptor cannot be obtained\n");
    } else {
        printf("max file descriptors: %ld\n", (long)lim.rlim_cur);
    }
    
    return 0;
}
