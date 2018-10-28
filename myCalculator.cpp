/*
*	b01303133_hw5.cpp
*
*	Created on:2016.10.15
*	Author: Yi-Pei Chan (b01303133)
*	Application: myCalculator
*/

/*the calculator considers six arithmetic operators binary + (addition), binary - (subtraction),
* (multiplication), / (division), % (remainder/modulo), and unary - (negation), with
possible parentheses ( and ) to group subexpressions.*/
// it is designed by changing the infix into postfix then calculate the valu by postfix

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <sstream>
#include <stack>
#include <math.h>

using namespace std;

bool isOperator(const string& input);
void performOp(const string& input, stack<double>& calcStack);


bool isOperator(char currentChar)
{
    switch (currentChar) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '%':
        return true;
    default:
        return false;
    }
}

// returns whether a `lOp` b `rOp` c == (a `lOp` b) `rOp` c
bool precedence(char leftOperator, char rightOperator)
{
    if ( leftOperator == '^' ) {
        return true;
    } else if ( rightOperator == '^' ) {
        return false;
    } else if ( leftOperator == '*' || leftOperator == '/' || leftOperator == '%' ) {
        return true;
    } else if ( rightOperator == '*' || rightOperator == '/' || rightOperator == '%' ) {
        return false;
    }

    return true;
}


std::string convertToPostfix(const std::string& infix)
{
    std::stringstream postfix; // Our return string
    std::stack<char> stack;
    stack.push('('); // Push a left parenthesis ‘(‘ onto the stack.

    for(std::size_t i = 0, l = infix.size(); i < l; ++i) {
        const char current = infix[i];

        if (isspace(current)) {
            // ignore
        }
        // If it's a digit or '.' or a letter ("variables"), add it to the output
        else if(isalnum(current) || '.' == current) {
            postfix << current;
        }

        else if('(' == current) {
            stack.push(current);
        }

        else if(isOperator(current)) {
            char rightOperator = current;
            while(!stack.empty() && isOperator(stack.top()) && precedence(stack.top(), rightOperator)) {
                postfix << ' ' << stack.top();
                stack.pop();
            }
            postfix << ' ';
            stack.push(rightOperator);
        }

        // We've hit a right parens
        else if(')' == current) {
            // While top of stack is not a left parens
            while(!stack.empty() && '(' != stack.top()) {
                postfix << ' ' << stack.top();
                stack.pop();
            }
            if (stack.empty()) {
                throw std::runtime_error("missing left paren");
            }
            // Discard the left paren
            stack.pop();
            postfix << ' ';
        } else {
            throw std::runtime_error("invalid input character");
        }
    }


    // Started with a left paren, now close it:
    // While top of stack is not a left paren
    while(!stack.empty() && '(' != stack.top()) {
        postfix << ' ' << stack.top();
        stack.pop();
    }
    if (stack.empty()) {
        throw std::runtime_error("missing left paren");
    }
    // Discard the left paren
    stack.pop();

    // all open parens should be closed now -> empty stack
    if (!stack.empty()) {
        throw std::runtime_error("missing right paren");
    }

    return postfix.str();
}

int main()
{
    stack<double>calcStack;
    string input;
    string infix;

    cout<<"Welcome to Yi-Pei's Calculator! \n\n";
    cout<<"The calculator considers six arithmetic operators + , - ,* , / , % , and unary - (negation), with possible parentheses ( and )."<<endl;
    cout<<"It is designed by changing the infix expression into postfix then calculates the value in postfix method with stack operations."<<endl;
    cout<<"I added one more operator ^ to do the power.\n"<<endl;

    cout<<"The calculator works in following steps:\n "<<endl;
    cout<<"1. Enter a INFIX arithmetic expression. "<<endl;
    cout<<"2. Yi-Pei's Calculator will return you a POSTFIX result. "<<endl;
    cout<<"3. Please enter the POSTFIX result for confirmation check. "<<endl;
    cout<<"4. Yi-Pei's Calculator will return you answers in each step." <<endl;
    //cout<<"5. Enter 'exit' if you want to leave the calculator.\n"<<endl;

   

    std::cout << "\nEnter the Arithmetic Expression: ";
    getline(cin, infix);
        
    input = convertToPostfix(infix);
    cout << "Postfix: '" << input << "'\n"<<endl;


    std::cout << "Please Enter the Postfix Expression: ";
    
    while(true)
    {
        
        //get input
        cin>>input;

        // check for numeric value
        double num;
        if(istringstream(input)>>num)
        {
            calcStack.push(num);
        }

        else if (isOperator(input))
        {
            performOp(input, calcStack);
        }

        else if (input=="q")
            return 0;
        else
            cout<<"Invalid input";


    }
    
}



bool isOperator(const string& input)
{
    string ops[]={"+","-","*","/","%","^"};
    for(int i=0; i<6;i++)
    {
        if(input == ops[i])
            return true;
    }
    return false;
}

void performOp(const string& input, stack<double>& calcStack) //function for the performance of operators
{
    double lval, rval, result;

    rval=calcStack.top();
    calcStack.pop();

    lval=calcStack.top();
    calcStack.pop();

    if(input=="-")
    {
        result=lval-rval;
    }

    else if(input=="+")
    {
        result=lval+rval;
    }

    else if(input=="*")
    {
        result=lval*rval;
    }
    else if(input=="%")
    {
        int lval_1=lval, rval_1=rval;
        result=lval_1 % rval_1;
    }
    else if(input=="^")
    {
        result=pow(lval,rval);
    }

    else 
    {
        result=lval/rval;
    }
    cout<<"Result at each step: "<<result<<endl;
    calcStack.push(result);

}
