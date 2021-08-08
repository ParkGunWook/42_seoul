#include "../../pushswap/includes/utils.h"
#include "../../pushswap/includes/myloc.h"

int main(int argc, char **argv) {
    if (argc == 0)
        return (0);
    t_list *list;
    list = parser(argv + 1);
    printf("List : %p\n", list);
    traverseAll(list);
    return 0;
}
