#include "../h/main.h"

int main(int ac, char** av) {
    if (ac > 2)  error("Too many artuments\n");
    if (preparation(av[1]) != 0)  error("Socket preperation fault\n");
    return 0;
}
