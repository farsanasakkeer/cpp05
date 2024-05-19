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


