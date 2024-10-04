/* #include <iostream>
#include <algorithm>

using namespace std;
int stack[5];

int main() {
    char exp[5];
    int counter = -1;
    cout << "Enter 5 elements: ";
    for_each(begin(exp), end(exp), [](auto& elem) { cin >> elem; });

    // Optionally, output the entered elements to verify
    cout << "You entered: ";
    for_each(begin(exp), end(exp), [](auto& elem) { cout << elem << " "; });
   
    for (int i = 0; i < 5; i++){
        if(isdigit(exp[i])){
            counter = counter + 1;
            stack[counter] = exp[i];
        }
        else{
            stack[counter] + exp[i];
        }
    }
    


    
    return 0;
} */





















// C++ Code for Expression Parsing Using Stack
#include <iostream>
#include <string>
#include <cctype>
#include <stack>
// char stack
std::stack<char> stack;

void push(char item) {
    stack.push(item);
}
char pop() {
    char top = stack.top();
    stack.pop();
    return top;
}
// returns precedence of operators
int precedence(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
        case '(':
        case ')':
        case '#':
            return 1;
    }
    return 0;
}
// check whether the symbol is an operator
int isOperator(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}
// converts infix expression to postfix
void convert(const std::string& infix, std::string& postfix) {
    int j = 0;
    stack.push('#');
    for (char symbol : infix) { // range-based for loop in C++

       //// if the symbol is a number/////
        if (isOperator(symbol) == 0) {  
            postfix += symbol;         // add it to postfix
            j++;                       // increase the postfix counter
            

         //// if the symbol is an operator + - /...etc ////
        } else {  
            if (symbol == '(') {
                push(symbol);     // push it to the stack
            } else {
                if (symbol == ')') {   // if it is a closing parenthesis pop out the operator-stack into (operand string=> postfix) until the closing tag is found

                    while (stack.top() != '(') {
                        postfix += pop();    // keep poping the stack into the posfix until we find the closing tag
                        j++;     // increase posfix count
                    }

            //// once the condion of the while loop is broken(the closing tag is found) we pop it out the stack ie. discard it
                    stack.pop(); // pop out '(' 


                } else { // if the symbol is not either closing or opening tag

                    if (precedence(symbol) > precedence(stack.top())) {  // if the precedence of the symbol is larger (*/) than that of the top stack
                        push(symbol);  // push it to the stack (above the previous top)

                    } else { // if the symbol is smaller (higher in order */) than the top stack
                        while (precedence(symbol) <= precedence(stack.top())) {
                            postfix += pop(); //pop the (lower-in-order +-) aka. the top-stack operator into the posfix string
                            j++;
                        }
                        push(symbol); // after poping symbols with higher precedence from the stack to posfix push the current symbol to stack
                    }
                }
            }
        }
    }

    while (stack.top() != '#') { // while there is still symbols in the stack
        postfix += pop(); // add them to the posfix 
        j++;
    }

    postfix[j] = '\0'; // null terminate string
}
// evaluates postfix expression
int evaluate(const std::string& postfix) {
    std::stack<int> stack_int;
    int operand1, operand2;
    for (char ch : postfix) {
        if (std::isdigit(ch)) {
            stack_int.push(ch - '0'); // Push the operand
        } else {
            // Operator, pop two operands
            operand2 = stack_int.top();
            stack_int.pop();
            operand1 = stack_int.top();
            stack_int.pop();
            switch (ch) {
                case '+':
                    stack_int.push(operand1 + operand2);
                    break;
                case '-':
                    stack_int.push(operand1 - operand2);
                    break;
                case '*':
                    stack_int.push(operand1 * operand2);
                    break;
                case '/':
                    stack_int.push(operand1 / operand2);
                    break;
            }
        }
    }
    return stack_int.top();
}
int main() {
    std::string infix = "1*(2+3)", postfix;
    convert(infix, postfix);
    std::cout << "Infix expression is: " << infix << std::endl;
    std::cout << "Postfix expression is: " << postfix << std::endl;
    std::cout << "Evaluated expression is: " << evaluate(postfix) << std::endl;
    return 0;
}