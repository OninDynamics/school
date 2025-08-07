#include <iostream>

int main() {

    /* Memory is finite. For e.g. a system with 1KB of RAM, there can only be
     * 1,024 bytes that can exist in memory. So, if an int requires 2 bytes, then
     * there can only be 512 of these ints we can declare.
     *
     * How can we know WHERE in the memory an int is?
     *
     * Memory is addressed from 0 to whatever amount of bytes there are, minus one.
     * For example, a 1MB system has addresses that range from 0 to 1,048,575.
     * This is because 1MB equals to 1,048,576 bytes. Here the first byte has address
     * 0, the second byte has address 1, the third byte has address 2, and so on.
     *
     * However, because of convenience (and using less digits), we typically
     * use hexadecimal when referring to memory addresses. Also, for clarity,
     * ALL hexadecimal values start with the prefix "0x". So:
     *
     * 1,048,575 is 0FFFFF in hex, so the address of the final byte is "0x0FFFFF".
     *
     * When dealing with hex values, we like an even number of digits. That's
     * why we have an extra zero.
     *
     * Anyway, let's illustrate this: */

    int a = 4;  // This variable 'a', when it is declared, is allocated some memory.

    // Let's define a pointer.
    int* ptr = &a;

    /* A type followed by an asterisk '*' means that the value is of a pointer
     * to int, char, whatever. In this example, "int*" means "pointer to int".
     * 
     * In this example, "ptr" contains a value "&a". What is &a???
     *
     * In C/C++, the ampersand '&' is the "Reference" operator. This means '&'
     * means "The address of". So, in this example, the pointer named "ptr"
     * contains whatever the address of the variable 'a' is. */

    // Let's see it in action!
    std::cout << "int a contains the value: " << a << "\n";
    std::cout << "ptr contains the value: " << ptr << "\n";

    /* If you want to access the contents of an address, you use the "Dereference"
     * operator, the asterisk '*'. If you dereference a pointer, you get the value
     * of whatever is present at that address. So, in this example, "*ptr" should
     * return the value of whatever 'a' is, because "ptr" contains "a"'s address. */

    // Let's see it in action!
    std::cout << "\n&a contains the value: " << &a << "\n";
    std::cout << "*ptr contains the value: " << *ptr << "\n";

    return 0;
}
