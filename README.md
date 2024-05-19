# cpp05

Exception handling in C++ provides a way to gracefully handle errors and exceptional conditions that occur during the execution of a program. It allows you to separate error-handling code from normal code flow, making your programs more robust and easier to maintain. Here's a step-by-step guide to understanding exception handling in C++:

##**1. Exceptions:**

An exception is an object that represents an error or an exceptional condition. When an error occurs, you can "throw" an exception to signal that something unexpected has happened.

##**2. Try-Catch Blocks:**

Try Block: Code that may potentially throw an exception is placed within a try block.
Catch Block: If an exception is thrown within the try block, it's caught by a corresponding catch block.


##**3. Throw:**

To throw an exception, you use the throw keyword followed by an expression that evaluates to an exception object. This typically occurs within a try block.

##**4. Catch:**

To catch an exception, you use a catch block, specifying the type of exception you want to catch. If an exception of that type (or a derived type) is thrown within the corresponding try block, the catch block is executed.
