#include <iostream>

/*
 *	Classes serve as definitions for "objects".
 *	Objects can contain any data defined in a class, and can also contain
 *	functions that operate on itself, so called "member functions", but are
 *	better known as "methods".
 */

// Let's create a class:
class Square {
	float side_length = 1.0f;

	/* Everything that comes before the "public:" label is considered PRIVATE
	 * to the class. This means it's impossible to directly access them from
	 * outside the class. */
public:
	Square() {}	/* This is a function without a return type, called the
				 * "constructor". Constructors are called every time an object
				 * of this class is instantiated (created). Constructors must
				 * also have the exact same name as their class. Right now,
				 * Square() doesn't really do anything, but create an object
				 * and return a pointer to said object.
				 * (All this is done implicitly, so you don't need to worry
				 * about manually writing constructors for the most part.) */
	
	/* This function can access the private variable, because it's in the same
	 * class. However, because this function is public, this can still be called
	 * from anywhere, provided an object of this class is in scope.
	 * You'll understand later when we call methods. */
	float perimeter() {
		return side_length * 4;
	}
}

/* Alright, now, in order to use the class, one must "instantiate" it.
 * "Instantiation" is a fancy term for "create", really. The syntax is
 * equivalent to any other variable. Just know that the class name is the type! */
int main_a() {
	Square s1;

	/* Now we have an object "s1" of type/class "Square". Note that by simply
	 * creating a new "Square" object, the "Square()" constructor is also run.
	 * Right now, because "Square()" is an empty function,
	 * it doesn't really do anything obvious. */

	/* Anyway, it's time to call the side_length() method!
	 * To access every member of a class (i.e. public variables & methods),
	 * you use the "member access" operator, "." */
	std::cout << s1.perimeter();

	//... Just like a struct! (This'll output, for example, 4.0.)
	
	/* Note how we called "s1" instead of the class directly. This is because
	 * the "s1" object *contains* the perimeter() method.

	 * Also note how "s1", like other variables, have a scope: If main_a() ends,
	 * the data of s1 is dropped. */
}
