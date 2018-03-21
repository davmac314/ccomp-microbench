#include "strucs.h"

somestruct foo(void);
void bar(somestruct);

int main(int argc, char **arv)
{
    /* int array[10]; */
    for (int i = 0; i < 500000; i++) {
        bar(foo());
    }
}
