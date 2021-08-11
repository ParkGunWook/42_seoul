#include "utils.h"
#include "myloc.h"

int main(int argc, char **argv) {
    if (argc == 0)
        return (0);
    t_list *list;
    list = parser(argv + 1);
    t_stack *aStack = initStack('a');
    while (1)
    {
        t_node *temp = popBack(list);
        if (temp == NULL)
            break;
        addBackNode(aStack->list, temp);
        aStack->size++;
    }
    clearList(&list);
    t_stack *bStack = initStack('b');
    mainSort(aStack, bStack);
    //rtraverseAll(aStack->list);
    clearStack(&aStack);
    clearStack(&bStack);
    return 0;
}
