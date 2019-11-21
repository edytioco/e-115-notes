// Ethan DyTioco
// E 115 Intro to Programming
// Fall 2019 Midterm 2 Review
//
// Topics:
// Variables
// if-else
// loops
// functions
// classes/objects (will be covered separately)

#include <iostream>
#include <string>
using namespace std;

void module_01_numbers(){
	/* ================ Data Types ================ */
	// here are the numerical data types we've gone over:
	int whole = 2;                          // at least 4 bytes. whole numbers only.
	float sevenDig = 0.1234567;             // at least 4 bytes. 7 decimal digits.
	double fifteenDig = 9.123456789012345;  // at least 8 bytes. 15 decimal digits.

	int roundDown = 7/2;      // this stores 3. int's chop off the decimal values.
	double keepDecimals = 7.0/2;// this stores 3.5, since double's hold decimal places.

	// for int's, you can get the remainder in division maths by using %
	// for example, 7/2 = 3 R1. So, 7%2 will return the value 1.
	cout << "Using / and %, 7/2 = " << 7/2 << "remainder " << 7%2 << endl;
	
	
	
	
	/* ================ Overflow / Underflow ================ */
	// these data types don't have an infinite range. There's a cap to what they hold.
	// for example, the range of int is -2,147,483,648 to 2,147,483,647.
	// So, weird things happen if you exceed the range that the data type can hold.
	
	// if you add 1 to the maximum number, you loop around all the way to the lowest value.
	// this is called overflow.
	
	// if you subract 1 to the lowest number, you loop up all the way to the max value.
	// this is called underflow. that's why Ghandi nukes everyone in Civ.
	// strangely, I tried underflowing in C++ and it didn't work for me. But, overflowing works.
	
	// you generally want to AVOID overflow and underflow
	
	int x = 2147483647;
	cout << "x = " << x << endl;
	x = x + 1;
	cout << "added 1.\n";
	cout << "x = " << x << endl; // this will be -2147483648
	
	
	
	
	/* ================ Typecasting ================ */
	// numerical results will have the same data type as the most precise data type
	// present in the calculation.
	cout << "7 and 2 are int's in 7/2 = " << 7/2 << endl;
	cout << "7.0 will act like a float/double.\n";
	cout << "7.0 and 2 will make a double in 7.0/2 = " << 7.0/2 << endl;
	cout << "in this example, double wins: " << float(7)/5 + double(19)*1.5 << endl;

	// you can force a variable of one data type to another type using typecasting
	// here are two examples that behave the same way: they make 7 behave like a double.
	cout << "typecasting 7 from int to double in 7/2 = " << (double)7/2 << endl;
	cout << "typecasting 7 from int to double in 7/2 = " << double(7)/2 << endl;
	
	
	
	
	/* ================ Numerical Maths ================ */
	cout << "\n\n\n";
	
	
	// you can do math with these variables!
	int x, y;
	double poly;
	cout << "f(x, y) = x^2 + y^2 - 1." << endl;
	cout << "x value: ";
	cin >> x;
	cout << "y value: ";
	cin >> y;
	poly = double(x) * float(x) + double(y) * double(y) - 1.0;
	cout << "f(" << x << ", " << y << ") = " << poly << endl;
	
	
	
	
	/* ================ When to Initialize ================ */
	// sometimes, you have to initialize the variables.
	// this depends on the context of what the program is doing.
	int sum = 0;
	cout << "give me three numbers and I will add them!\n";
	cout << "1st number: ";
	cin >> x;
	sum += x;                 // same as sum = sum + x. you need a starting value for sum.
	cout << "2nd number: ";
	cin >> x;
	sum += x;
	cout << "3rd number: ";
	cin >> x;
	sum += x;
	cout << "the sum of these three numbers is: " << sum << endl;

	// another example of needing to initialize your variable.
	// again, factRes needs to have a starting value, or else factRes *= i can't happen.
	// in this case, we have to initialize with the value 1,
	// because we're doing multiplication!
	cout << "give me a number to factorialize: ";
	cin >> x;
	int factRes = 1;
	for (int i = 1; i <= x; i++)
		factRes *= i;         // same as factRes = factRes * i;

	cout << x << "! = " << factRes << endl << endl;
}




void module_02_strings(){
	// strings are a series of characters. a number will behave like a letter in a string.
	string name = "Ethan DyTioco";

	// the proper way of inputting strings is getline(cin, <string object name>);
	// cin only works for one word, and it hates spaces. getline is still simple enough to use.
	cout << "What's your gamer tag: ";
	getline(cin, name);   // logically similar to cin >> name, if name was a number.




	/* ================ String Input ================ */
	// if you input numbers with cin and strings with getline in the same program,
	// add the line cin.ignore() between your last cin and first getline,
	// so that the first getline does not get skipped over.
	int x;
	cout << "enter your age in years: ";
	cin >> x;
	cout << "what's your first name again? tell me: ";
	cin.ignore(); // <-- right here!
	getline(cin, name);
	cout << "Ah, gotcha, " << name << ". It's good to be " << x << " years old!\n";
	
	
	
	
	/* ================ String Concatenation ================ */
	// string concatenation is the process of combining multiple strings into one large string.
	// it's easiest to do with a + operator.
	// please use + when you're asked to concatenate strings.

	// [GOOD] this is proper string concatenation.
	string first = "ethan";
	string last = "dytioco";
	cout << "hello there, " + first + " " + last + "\n";

	// [BAD] this is not proper string concatenation. it's the same as doing:
	// cout << "hello again, ";
	// cout << first;
	// cout << " ";
	// cout << last;
	// You're not putting the strings together into one. You're just outputting them in order.
	cout << "hello again, " << first << " " << last << endl;
}




void module_03_ifelse(){
	/* ================ Conditionals ================ */
	// now we're going into the realm of conditional statements.
	// conditional statements return the value true or false. the data type is bool.
	int a = 2, b = 3;
	bool sum5 = (a + b) == 5;       // returns true
	bool not2 = (a != 2);           // returns false

	// these are the following boolean operators:
	// a == b     				checks to see if a is equal to b
	// a != b     				checks to see if a is not equal to b
	// a > b      				checks to see if a is greater than b
	// a >= b     				checks to see if a is greater than or equal to b
	// a < b      				checks to see if a is less than to b
	// a <= b     				checks to see if a is less than or equal to b
	// (a == b) && (c == d)		&& is the AND operator
	// (a == b) || (c == d) 	|| is the OR operator
	
	
	// if you want to check if a string is equal to another string, use this form:
	// <string1>.compare(<string2>) == 0
	string name = "ethan";
	string bismarck = "my boi otto";
	
	if (name.compare("ethan") == 0)
		cout << "your name is ethan too? *surprised pikachu face*" << endl;
	
	if (name.compare(bismarck) == 0)
		cout << "wait, you're otto von bismarck too? WHOA" << endl;
	else
		cout << "but, you're not otto von bismarck :P" << endl; // this runs, because "ethan" != "my boi otto"
	
	
	
	
	/* ================ If, Else ================ */
	// if statements let you run certain bits of code if the condition is true.
	// if the condition is false, then the program executes what's next.
	// that can either be an else if statement, an else statement, or whatever comes after.
	// MAKE SURE that if you want to test if a is equal to b, to use TWO equals signs (==)!
	// Using only one equals sign (=) will not make your statements work.
	cout << "enter 5 for a secret message: ";
	cin >> a;
	if (a == 5)
		cout << "You're a wonderful student :)" << endl;
	else
		cout << "boooooooo >:(" << endl;
	
	// if you have an if statement with else if statements afterwards,
	// the program will run the first one that has a true condition.
	a = 2;
	if (a > 3)
		cout << "a is greater than 3" << endl;
	else if (a > 2)
		cout << "a is greater than 2" << endl;
	else if (a > 1)
		cout << "a is greater than 1" << endl; // only this runs!
	else if (a > 0)
		cout << "a is greater than 0" << endl;
	
	// these multiple if statements are independent from each other.
	// so, the last two will.
	a = 2;
	if (a > 3)
		cout << "a is greater than 3" << endl;
	if (a > 2)
		cout << "a is greater than 2" << endl;
	if (a > 1)
		cout << "a is greater than 1" << endl; // this runs
	if (a > 0)
		cout << "a is greater than 0" << endl; // but this runs as well!
}




void module_04_loops(){
	// this course covers two types of loops: while, and for.
	
	/* ================ While Loop ================ */
	// a while loop is set up similarly to an if statement.
	// if the condition is true, the code inside will run
	bool isHeYourMans = true;
	string ans = "";
	while (isHeYourMans == true){
		cout << "you got a keeper, my gal! is he still your mans? [Y]es / [N]o: ";
		cin >> ans;
		if (ans.compare("Y") == 0)
			isHeYourMans = true;
		else
			isHeYourMans = false;
	}
	cout << "rip, you exited the while loop. he's no longer your mans, huh? :(" << endl << endl;
	
	int x = 0;
	while (x < 10){
		cout << "x is " << x << endl;
		x++;	// same as x = x+1;
	}
	
	
	
	
	/* ================ For Loop ================ */
	// a for loop is a more specialized loop that is best for counting.
	// if you know how many times you're looping something, or if it can be mathematically solved,
	// then use a for loop.
	
	// this for loop behaves like the while loop that counts from 0 to 9.
	// the only difference is that int x here no longer exists after the for loop.
	for (int x = 0; x < 10; x++)
		cout << "x is " << x << endl;
	
	// if you want the counter to exist after the loop, first declare it outside the for loop,
	// and then assign it a value inside the for loop
	int i;
	for (i = 0; i < 10; i++)
		cout << "i is " << i << endl;
	
	cout << "at the end of the loop, i is " << i << endl;
	
	// the first parameter is the increment. you usually make a variable here and set it to a value.
	// the second parameter is the condition that you test to see if you will loop or not
	// the third parameter is the increment, which happens after the end of the code looping.
}




void module_05_functions(){
	// Functions are bits of code that perform a certain process (ie, the code that you write).
	// It can have inputs or not, and it can have an output or not.
	
	/* ================ Signature ================ */
	// The function signature is: <return type> <function name> (<parameters, if any>)
	
	
	
	
	/* ================ Parameters ================ */
	// Functions with inputs have stuff in their parentheses, like math functions, when we write f(x) = x^2
	// You have to specify what data type each parameter is. You can see this in the example functions below.
	// Functions without inputs have empty parentheses.
	
	
	
	
	
	/* ================ Return type ================ */
	// Functions with an output have the data type of that output as the first word in the signature.
	// They will also return a value of that data type at the end of the function.
	// Functions without an output have the data type of void, and "void" is the first word in the signature
	// Void functions do not need any return statements, since they return... well, nothing.
	
	
	
	
	/* ================ Conclusion; Calling Functions ================ */
	// But no matter what the input or the output, the function will run the code that you write inside.
	// To run the function, you have to call its name and its parameters (empty parentheses if no parameters) inside main,
	// or inside another function that will be executed.

	cout << "This itself is a function! It's called module_05_functions.\n";
	cout << "Most of the things in this module are written as comments :)" << endl;
	cout << "Below this function, are examples where a function returns something, and where it returns nothing.\n\n";
}

// signature: int factorial(int x)
int factorial(int x){
	if (x < 0)
		return -1;		// as a programmer, i'm making a design choice to say that -1 means error.
	if (x == 0)
		return 1;
	else
		return x * factorial(x-1);
}

// signature: void encouragement(int n)
void encouragement(int n){
	if (n == 0 || n == 1)
		cout << "you'll do well in this midterm!\n";
	else if (n > 1)
		cout << "no seriously, you got this :)" << endl;
	else
		cout << "no matter what, you'll be alright! i believe in you :)" << endl;
	
	cout << "okay, let's do a little exercise. ready? say this with me:\n";
	for (int i = 0; i < n; i++)
		cout << "i'm a good student, and i'm loved and cared for by a lot of people :)" << endl;
}

void goodbye(){
	cout << "\n\n================ END OF REVIEW ================\n";
	cout << "you'll do great! go get 'em, and see you in a few weeks :)" << endl;
}

int main(){
	module_01_numbers();
	module_02_strings();
	module_03_ifelse();
	module_04_loops();
	module_05_functions();
	
	// as part of module_05:
	int x;
	cout << "i'm calling a factorial function that returns an int value.\n";
	cout << "enter a number to factorialize: ";
	cin >> x;
	cout << x << "! = " << factorial(x) << endl;
	
	// the numerical (int) value is returned in the spot where factorial(x) is typed out
	// if x is 5, then it would logically look like:
	// cout << 5 << "! = " << factorial(5) << endl;
	// and then,
	// cout << 5 << "! = " << 120 << endl;
	
	cout << "enter how many times would you like to see an encouraging message: ";
	cin >> x;
	encouragement(x);
	
	goodbye();
	return 0;
}



/*

================ E 115 Fall 2019 Midterm Review ================

A series of "code snippets" are shown below, and some questions related to them with answers. Each such code-snippet will compile perfectly with a "blank" main() function.
----------------------------------
int x = 3;
if(x = 5) {
    cout << "Value of x is 5" << endl;
}
else {
    cout << "X is not 5" << endl;
}


Q1: When you run the above, what gets printed on the screen? 
A1: "Value of x is 5"


Q2: Why? 
A2: x = 5 assigns the value of 5 to x, instead of checking if the statement "x is equal to 5" is true.


Q3: If the code instead read "if (x == 5) { ..}", what gets printed? 
A3: "X is not 5"
 
----------------------------------------


int var = 0;
cout << "Enter a number: " << endl;
cin >> var;


if(var%2 == 0){ 
        cout << "Number is even" << endl;
}
else{ 
        cout << "Number is odd" << endl;
}


Q1: What does this program do? 
A1: Asks the user for an integer, and tells the user if it's even or odd


Q2: Why does it work? 
A2: using the % operator with 2, which returns the remainder of a division by two. it makes a test case to see if it's zero (even), and then uses that for the proper output.


--------------------------------------------


int x = 100;
int y = 4;
if(x == 3) {
        if(y == 4) {
                cout << "The first print statement" << endl;
        }
        else { 
                cout << "The second print statement" << endl;
        }
} else { 
        cout << "The third print statement" << endl;
}


Q1: When this code is executed with x = 3 and y = 4, what prints on screen? 
A1: "The first print statement"


Q2: If instead this code was run with x = 3 and y = 5, what gets printed? 
A2: "The second print statement"


Q3: If x = 10, and y = 4, what gets printed? 
A3: "The third print statement"


Q4: How about x = 100 and y = 4
A4: "The third print statement"


-------------------------------------------------


int var = 0;

if(var < 0) {
        cout << "The first print statement" << endl;
} else if (var == 0) {
        cout << "The second print statement" << endl; 
} else { 
        cout << "The third print statement" << endl;
}


Q1: If we run the program with var = 1, what gets printed? 
A1: "The third print statement"


Q2: If we set var = -5, what gets printed? 
A2: "The first print statement"


Q3: What value should be assigned to "var" if we wanted "The second print statement" to print? 
A3: var = 0;


----------------------------------------------- 


int count = 0;

while(count < 10) { 
    cout << "Executing the while loop" << endl;
	count++;
}


Q1: How many times will this snippet print "Executing the while loop"? 
A1: an infinite number of times


Q2: Why does the loop never end?
A2: count is always zero, so count < 10 will always be true, and nothing is changing that.


Q3: What do we need to change (and where) to remedy this? 
A3: count++;


-------------------------------------------------


Consider the following while loop that is purposed to print numbers from 10 through 1. Identify what is wrong, and fix it. 


int count = 10;
while (count > 0) { 
    cout << "Count is: " << count << endl;
}


Answer:
int count = 10;
while (count > 0) { 
    cout << "Count is: " << count-- << endl;
}

--------------------------------------------------


int var = 2;


switch(var) { 
        case 1: cout << "In case 1" << endl;
                break;
		
        case 3: cout << "In case 3" << endl;
                break; 


        default: cout << "Could not find a suitable case" << endl;
                break;
} 


Q1: If we run this program with var = 2, what gets printed? 
A1: "Could not find a suitable case"


Q2: How do we change the above code to print "In case 2"? 
A2: case 2: cout << "In case 2" << endl;
            break;



-------------------------------------------------




for (int i = 0; i < 10; i = i + 2) { 
        cout << "Inside the for loop" << endl;
} 


Q1: How many times does "Inside the for loop" print on screen? 
A1: print 5 times.


Q2: Why? 
A2: because this prints for i = 0, 2, 4, 6, 8


Q3: What do we change to make it print the statement 10 times? 
A3: for (int i = 0; i < 10; i++)
	for (int i = 0; i < 20; i = i + 2)



------------------------------------------------------

Q: What stements gets you out of the program, like stop the whole thing: "break" or "exit(1)"?

A: exit(1) gets you out of the program.
	break gets you out of the current loop / layer of code.


-------------------------------------------------------


Q: Convert the following while loop to a for loop .. 


int count = 0;
while (count < 10) { 
        cout << "Hello World" << endl;
        count++;
}



A: 

for (int i = 0; i < 10; i++)
	cout << "Hello World\n";


-------------------------------------------------------


Q: Convert the following if-else block to a switch statement .. 


int var = 3; 
if(var == 1) {
        cout << "Its one" << endl;
}
else if(var == 2) {
        cout << "Its two" << endl;
}
else { 
        cout << "Its neither one nor two" << endl;
} 

A:
int var = 3;

switch(var){
	case 1:
		cout << "It's one" << endl;
		break;
	case 2:
		cout << "It's two" << endl;
		break;
	default:
		cout << "It's neither one nor two" << endl;
		break;
}










----------------------------------------------------------
Assume a block of code such as 

int var = 10;
if(var == 5) {
        cout << "Var is 5" << endl;
        cout << "And this is the second line .. " << endl;
}


and another block (without the "{"): 


int var = 10;
if(var == 5)
    cout << "Var is 5" << endl;
    cout << "And this is the second line .. " << endl;


Q1: What is different about block-1 and block-2 
A1: squiggly brackets :)
	the outputs will be different



Q2: What will block-1 and block-2 print? 
A2: 
block 1:
block 2: "And this is the second line .. "


----------------------------------------------------------------------
 
Consider the following void function that adds 2 to a given number, and doubles it: 


void processThis(int x) { 
	x = x + 2; 
    x = x*2; 
    cout << “Result: “ << x << endl; 
} 


Modify this function to return the new processed result.

int processThis(int x){
	x += 2;
	x *= 2;
	return x;
}





------------------------------------------------------
================ Ethan's Loop Drills! (cite: Dov Kruger) ================
Kruger: Identify the output of the following loops. If the output is long, show the first three values followed by "..." followed by the last number printed. If the output is infinite, terminate with "...".
The range of short int is -32,768 to 32,767, and
the range of int is -2,147,483,648 to 2,147,483,647

for (int i = 2; i < 15; i += 2)
	cout << i;
A: 2468101214




for (int i = 0; i != 0; i++)
	cout << i;
A: 




for (short int = 5; i < 8; i--)
	cout << i;
A: 54321...-32768




for (int i = 1; i < 100; i *= 2)
	cout << i;
A: 1248163264




for (int i = 100; i > 0;  i = i / 3 + 1)
	cout << i;
A: 10034125211...

*/