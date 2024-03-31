#include "../h/main.h"

int main(int ac, char** av) {
    if(ac > 2) error_out("Too many aeruments\n");
    if(socket_preparation(av[1]) != 0) error_out("Socket preperation fault\n");
    return 0;
}
