/* simil:
- All have members
- All are data types
- All are user-defined

Diff:
            struct                  union                   enum
============================================================================
each member can contain     only one member can     only one member can be
own data                    contain data            defined

each member can be of       members define possible members are possible
varying datatypes           types                   values for the type

members are accessed via    union member accessed   members define the
dot operator                via object name         type
===========================================================================
*/

struct NameOfStruct {
    int a;
    double b;
    char *c;
};

union NameOfUnion {
    int a;
    double b;
    char *c;
};

enum MegaBool { // lol imagine using this
    MAYBE,
    TRUE,
    FALSE,
    TRUEISH,
    FALSEISH,
    SOMETIMES_TRUE,
    SOMETIMES_FALSE,
    IDK_ASK_MO_SI_LORD,
    UNKNOWN,
    UHHH
};
