# cpp05
## Exception Handling in C++
Exception handling in C++ provides a way to gracefully handle errors and exceptional conditions that occur during the execution of a program. It allows you to separate error-handling code from normal code flow, making your programs more robust and easier to maintain. Here's a step-by-step guide to understanding exception handling in C++:

**1. Exceptions:**

An exception is an object that represents an error or an exceptional condition. When an error occurs, you can "throw" an exception to signal that something unexpected has happened.

**2. Try-Catch Blocks:**

Try Block: Code that may potentially throw an exception is placed within a try block.
Catch Block: If an exception is thrown within the try block, it's caught by a corresponding catch block.


**3. Throw:**

To throw an exception, you use the throw keyword followed by an expression that evaluates to an exception object. This typically occurs within a try block.

**4. Catch:**

To catch an exception, you use a catch block, specifying the type of exception you want to catch. If an exception of that type (or a derived type) is thrown within the corresponding try block, the catch block is executed.
### Example:
Here's an example demonstrating exception handling in C++:
```bash
#include <iostream>

// Custom exception class
class MyException : public std::exception 
{
    public:
        const char* what() const noexcept override {
            return "My custom exception occurred";
    }   
};

int main() 
{
    try 
    {
        // Code that may throw an exception
        int x = 10, y = 0;
        if (y == 0) 
        {
            // Throwing an exception
            throw MyException();
        }
        int result = x / y;
        std::cout << "Result: " << result << std::endl;
    } catch (const MyException& e) 
    {
        // Handling the exception
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) 
    {
        // Catching any other exceptions
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

```

In this example:

- We define a custom exception class MyException, which inherits from std::exception.
- Inside the main function, we attempt to divide x by y, which may throw a division by zero exception.
- If y is zero, we throw a MyException.
- We catch MyException and any other exceptions (derived from std::exception) in separate catch blocks.
- The what() function is overridden to provide a custom error message for MyException.

In C++, noexcept is a specifier that indicates whether a function can throw exceptions. When you declare a function as noexcept, you're promising that it won't throw any exceptions during its execution.

The override keyword is used to explicitly declare that a function is overriding a virtual function from a base class.

In this example, noexcept is used to specify that the what() function of MyException won't throw any exceptions during its execution. override is used to explicitly state that what() is overriding the virtual function what() from the base class std::exception. This is helpful for ensuring that you're correctly overriding virtual functions from base classes, and it can also provide compiler optimizations based on the promise that no exceptions will be thrown.

### Summary:
Exception handling in C++ allows you to gracefully handle errors and exceptional conditions. By using try-catch blocks, you can separate error-handling code from normal code flow, making your programs more robust and maintainable.

## ex01
std::ofstream: This is a stream class to write on files. 
It is part of the C++ Standard Library and is included via the <fstream> header.

( ... ).c_str() converts the resulting std::string to a C-style string 
(i.e., a pointer to a null-terminated array of characters), which is required by the open method of std::ofstream.

open() Method: The open method of std::ofstream opens a file whose name is specified by the C-style string. 
If the file does not exist, it will be created.
## ex02

```bash
  ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &overload) 
{
	std::cout << "Shrubbery Creation Form Operator Overload Called" << std::endl;
	if (this != &overload) 
    {
        AForm::operator=(overload); //<------------
    }
	return(*this);
}
```

```bash
  AForm::operator=(overload);
```

This line explicitly calls the assignment operator of the base class AForm. This is necessary because the derived class (ShrubberyCreationForm in this case) may have inherited members from the base class that need to be properly copied or assigned.

## Why Call the Base Class Assignment Operator?
1. ### Inherited Members:
The base class AForm may have private or protected members that are not accessible directly in the derived class. By calling the base class assignment operator, you ensure that all the members of the base class are correctly copied.

2. ### Base Class Initialization:
If the base class AForm has its own internal state or resources (like dynamically allocated memory), the base class assignment operator is responsible for properly managing these resources during assignment.

3. ### Avoid Code Duplication:
The base class AForm might have complex logic for assigning its members. Reusing this logic through the base class assignment operator helps avoid duplicating code in the derived class.

### Example with the ShrubberyCreationForm Class
Suppose AForm has some members like name, signed, gradeToSign, and gradeToExecute. When you assign one ShrubberyCreationForm to another, you need to ensure these base class members are properly copied. Here’s a more complete example to illustrate:

```bash
class AForm {
public:
    AForm &operator=(const AForm &other) {
        if (this != &other) {
            // Copy the base class members
            name = other.name;
            signed = other.signed;
            gradeToSign = other.gradeToSign;
            gradeToExecute = other.gradeToExecute;
        }
        return *this;
    }

protected:
    std::string name;
    bool signed;
    int gradeToSign;
    int gradeToExecute;
};

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &overload) {
        if (this != &overload) {
            AForm::operator=(overload); 
        }
        return *this;
    }
};
```

In this example, the call to AForm::operator=(overload) ensures that the members name, signed, gradeToSign, and gradeToExecute are properly copied from the overload object to this object.



"*The step of calling the base class assignment operator within the derived class assignment operator ensures that all the base class members are properly assigned. This practice helps maintain the integrity of the object’s state, prevents code duplication, and adheres to the principles of inheritance in C++. "*


```bash
void RobotomyRequestForm::formAction() const
{

	std::srand(std::time(0)); // Seed the random number generator with the current time
	int successRate = std::rand() % 2; // Generate a random number (0 or 1)


	std::cout << BLUE << "Making some drilling noises..." << RESET << std::endl;

	if (successRate == 1)
	{
		std::cout << GREEN << getTarget() << " has been robotomized successfully!" << RESET << std::endl;
	}
	else
	{
		std::cout << YELLOW << "Robotomy failed for " << getTarget() << "." << RESET << std::endl;
	}
}
```
This method ensures that every time formAction() is called, there's a 50% chance of success and a 50% chance of failure, simulating the randomness of the robotomy operation as specified.
Random Success or Failure: int successRate = std::rand() % 2 generates either 0 or 1.(The int successRate = std::rand() % 2; line generates a random integer and then takes its modulo 2. This results in either 0 or 1, each with a 50% probability.)

### Seeding the Random Number Generator:

```bash
std::srand(std::time(0));
```
* ` std::srand ` : This function seeds the random number generator used by std::rand(). The seed value initializes the random number generator, influencing the sequence of random numbers that will be produced.
* ` std::time(0) ` : This function returns the current time in seconds since the epoch (typically January 1, 1970). Using the current time as the seed value ensures that the sequence of random numbers is different each time the program runs. This avoids generating the same sequence of random numbers on each execution, which would happen if a fixed seed value were used.
