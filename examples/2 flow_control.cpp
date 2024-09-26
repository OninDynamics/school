int main () {

    /*                  !!! README !!! 
     * Before anything else, know how booleans work: */
    bool p = true;      // p is "true"
    bool q = 1 == 1;    // 1 is equal to 1, therefore q is "true"
    bool r = 4 < 0;     // 4 is NOT less than 0, therefore r is "false"

    /* They can be negated using the '!' operator: */
    bool s = !p; // p is "true", !p is "false". Therefore s is false.

    /* Conditions are booleans. The following examples will use conditions
     * named p,q,r,s. They are placeholders. Just know that they are present
     * where true/false conditions are required. */
    
    /* ### IF STATEMENTS (BRANCHING) ### */

    if (p) {
        /* The code here will run if p is true. */
    }
    
    // Otherwise, the code is skipped.

    if (p) {
        /* This code will run if p is true. */
    } else {
        /* This code is run if no other condition is met. In this example, it
         * will run if p is false. */
    }

    if (p) {
        /* This code will run if p is true. */
    } else if (q) {
        /* This code will run if q is true. */
    } else {
        /* This code will run if both p and q is false. */
    }



    /* ### SWITCH STATEMENTS (SELECTION) ### */
    int num;

    switch (num) {
        case 0:
            /* Run this code if num is 0. */
        break;  // Break out of the switch statement, e.g. cancelling it.

        case 1:
            /* Run this code if num is 1. */
        break;

        // etc.

        /* If breaks aren't specified, multiple blocks of code may execute.
         * This isn't a good idea unless you ABSOLUTELY are a coding wizard. */

        default:
            /* Run this code if none of the previous cases matched. */
        break;
    }

    /* ### LOOPS ### */

    while (p) {
        /* Code runs continuously while p is true. */
        if (r) {break;} // Breaks end a while-loop early. Helpful for
                        // non-infinite loops.
    }

    for (int i = 0; i < 20; i++) {   // Counter, Condition (True/False), Post-Operation
        /* Code runs as long as the Condition remains True.
         * After each iteration, the Post-Operation runs.
         * The Counter may be declared in the for-loop body, or outside.
         * The Counter must also NOT be a NULL, i.e. it must have a value. */
    }

    do {
        /* Code here runs at least once. */
    } while (p);    // If p is true, then the code in do{} runs again.

    return 0;
}
