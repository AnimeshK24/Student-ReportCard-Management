#include <iostream>
#include "SubFunction.h"

int main()
{
    welcome();
    bool screen2 = registerScreen();
    if (!screen2)
    {
        /* if screen2 is false */
        system("cls");
        registerScreen();
    }
    operations();
    return 0;
}