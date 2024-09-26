#include <iostream>
#include <cmath>

/* Functions define a way to write code once, then use
 * that code many times, without copy-pasting. */

/* Functions must be declared before it is used. Here is a function declaration
 * and a definition. This function outputs a "bool" value, which is why the keyword
 * "bool" is at the start of the function. */
bool isBiggerThanFive(int a) {  /* Whatever value was passed, assign it to a new
                                 * variable "a" local to this function. */
    if (a > 5)
        return true;    // If a is bigger than 5, make this function output "true".
    else
        return false;   // Output "false" otherwise.
}

/* We can declare a function now, then define it later after main().
 * This one returns nothing, so we use the "void" type. Because this returns nothing,
 * this function can NOT be used in expressions. */

/* Let's now declare a function without defining it.
 * This is called a "Function Prototype". */
void thisIsAFunction(); // Function prototypes are considered complete statements,
                        // so we need to put a semicolon to its end.

int main() {    // This is the "main function". Every program starts here.

    /* This function is defined in <cmath>. Because <cmath> is inside the "std"
     * namespace, we must access it via the namespace access operator: "::". */

    int num = std::sqrt(4);    // Assigns the result of sqrt(4) to variable "num".

    /* ^This is equivalent to :
     * int num = 2; */

    /* In line 5, we defined the function "isBiggerThanFive()".
     * We'll call it here: */
    isBiggerThanFive(num);

    /* The above will evaluate to "true". You can use this as a condition: */
    if (isBiggerThanFive(num)) {
        std::cout << num << " is bigger than five!\n";
    }

    /* Functions can also be used in expressions: */
    std::cout << "The square root of 16 is: " << sqrt(16) << "!\n";

    return 0;
}

