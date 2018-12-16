# Algorithms: Design and Analysis
This repository stores code scripts of the homework and learning notes of the course: "Algorithms: Design and Analysis"<br>
Part of the code are midified from lecture notes or text book, “Data Abstraction and Problem Solving with C++: Walls and Mirrors,” written by F.M. Carrano and T. Henry.

## Course Content<br>

1. Asymptotic Analysis <br>

2. Divide & Conquer Algorithms <br>

3. The Master Method<br>

4. QuickSort- Algorithm & Analysis<br>

5. Linear Time Selection<br>

6. Graph Search and Its Applications<br>

7. Dijkstra’s Shortest-Path Algorithm<br>

8. The Heap Data Structure<br>

9. Search Trees<br>

10. Hash Tables and Bloom Filters<br>

<br>

## Supplement works:<br>

1. myCalculator <br>
Task Description<br>
Develop a C++ application (called “myCalculator” perhaps) that, given as input a C/C++ arithmetic expression, (1) converts the input into a postfix expression and prints it out and (2) evaluates the expression and prints out the result. The simplest kind of arithmetic expression that your application must handle is a C/C++ constant integral expression built up from integers and the six arithmetic operators binary + (addition), binary - (subtraction), * (multiplication), / (division), % (remainder/modulo), and unary - (negation), with possible parentheses ( and ) to group subexpressions. Below are two examples:
• 1+2-3*4/5 <br>
• (-1 + 23 - 456) * (78 % 9) <br>
Be careful with illegal inputs. When the input is illegal, your program should be able to report an error and stop (or ask for another input).<br>
You may go beyond these basic requirements for extra credits, but please follow the C/C++ syntax and semantics for integral arithmetic expressions. For instance, you may choose to handle expressions that contain assignments such as:<br>
• (a = 1) + a <br>
• (a = 2) + (bb = a) * bb <br>


2. myDictionary<br>
Task Description<br>
Develop a C++ application, called myDictionary, that reads a text file named knownWords.txt to set up an initial collection of English words (or Chinese phrases, if you prefer) and their definitions. It then waits to accept and process the user’s queries or updates (one by one from the command line).<br>
A word whose definitions are to be given always starts on a new line in the file knownWords.txt. The word is followed by its pronunciation in some phonetic symbols (enclosed in ‘[‘ and ‘]’), a part-of-speech (POS) label, and its meanings under that POS class. A single dash (-) at the beginning of a line indicates continuation of the definitions of a word in the previous line. A double dash (--) indicates an additional POS label for the word. If the word has a different pronunciation under that POS class, it is enclosed in ‘(’ and ‘)’. Below is a small sample knownWords.txt with just three words.<br>
contract [...] n. 1. an agreement between two parties. 2. a document describing the terms of a contract. 3. ...<br>
-- v. ([...]) 1. to establish or undertake by contract. 2. to reduce to smaller size. 3. ...<br>
curiosity [...] n. 1. a desire to know about something. 2. something that is unusual.<br>
curious [...] adj. 1. interested. 2. unusual or difficult to understand.<br>
After setting up the initial collection of words, myDictionary enters a loop waiting for the user to type a command such as the following:<br>
• find curiosity<br>
Look up the definitions of “curiosity”.<br>
• new webpage "[...] n. 1. ... 2. ... 3. ..."<br>
Add a new word “webpage” with the definitions enclosed in the pair of double<br>
quotes to the collection of words.<br>
• count<br>
Count the number of words in the collection.<br>
 • quit<br>
Exit the application<br>
Be careful with illegal inputs. When the input is illegal, your program should be able to report an error and resume the state of waiting for the next input.<br>
