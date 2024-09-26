#include <iostream>

int num;    // This is a GLOBAL variable. It can be seen and changed from anywhere.
const double pi = 3.1415926;   // This constant can be used anywhere.

int main() {

    num = 3;    // Because "num" is global, main() can access and change it.

    while (num-- > 0) {
        /* Every time this loop runs, the num variable is decremented.
         * Because the "--" is after the num, the expression "num > 0" is
         * first evaluated, then after evaluation, num is decremented. */
    }

    for (int i = 0; i < 20; i++) {
        /* Note that 'i' is LOCAL to this for-loop. 'i' can NOT be
        * accessed outside of this for-loop. */

        num++;  // num is still accessible, because it's GLOBAL.
    }

    i = 2;  // COMPILE ERROR: 'i' is undefined here, because now we're outside of i's scope.

    /* As a rule of thumb, anything declared in between curly braces "{}" are
     * only accessible by other things also inside those curly braces.
     * An exception includes the for-loop, where variable 'i' is declared
     * in the for-loop's body. */

    for (int num = 0; num < 20; num++) {
        /* Wait, isn't "num" already defined globally?
         * YES! But here, we're creating a NEW variable, separate
         * from the global "num" variable. The global "num" variable
         * is unchanged. Only in this for-loop will the "num" variable
         * refer to the for-loop's counter. When this for-loop ends,
         * this "num" is removed from the program, and "num" will
         * refer to the global "num" again.
         * This is called "Shadowing"!!!
         * In this example, the local "num" is "shadowing" the global
         * "num". */

    }
    

    /* ### NAMESPACES ### */
    cout << num;    // COMPILE ERROR: We haven't told the compiler what "cout" is.
                    // This means that this is undefined in this scope.

    /* This is because "cout" is in the "std" namespace. In order to access
     * the "std" namespace, use the "::" operator: */
    std::cout << num;   // Will output whatever the value of num is

    /* You can also use the "using" keyword: */
    if (true) {
        using namespace std;
        cout << "Now I can use cout without typing std!\n";
    }

    /* Note, that because the "using" statement was used inside that if
     * statement, its scope is only in that if statement. If we were to
     * use "cout" outside of the if(), it's invalid now: */
    cout << "Can I use cout without std outside of that if()?\n";
    // COMPILE ERROR: "cout" is undefined in this scope.

    /* Usually, "using namespace std;" is declared at the first bit of the
     * program, outside of any function. This meant that globally, the namespace
     * "std" was pulled into scope.
     * Remember, to pull something in a namespace into a program's scope, it must
     * be accessed either via "::", or have the whole namespace become available
     * using the "using ..." statement. */

    /* Scoping is useful in classes and the OOP parts of C++. I'll yap about it soon. */

    return 0;
}
