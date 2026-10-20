#include <stack>
#include <vector>
#include <string>
using namespace std;

// Algo covers in 5 steps and concept of this question is Stack + Expression Evaluation like Postfix Expression Evaluation
// 1. Create an empty stack to store numbers and intermediate results.
// 2. Traverse each token from left to right.
// 3. If the token is a number, convert it to an integer and push it onto the stack.
// 4. If the token is an operator, pop the second operand first, then the first operand, perform the operation, and push the result.
// 5. Return the top element of the stack after all tokens have been processed.

// HERE IS THE CODE OF THIS QUESTION!

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        // Traverse each token from left to right
        for (string token : tokens) {

            // Check whether the token is an operator
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                // Pop the second operand first
                int b = st.top();
                st.pop();

                // Pop the first operand
                int a = st.top();
                st.pop();

                // Perform the operation and push the result
                if (token == "+") {
                    st.push(a + b);
                }
                else if (token == "-") {
                    st.push(a - b);
                }
                else if (token == "*") {
                    st.push(a * b);
                }
                else {
                    st.push(a / b);
                }
            }
            else {
                // Convert the string into an integer and push it
                st.push(stoi(token));
            }
        }

        // Return the final result
        return st.top();
    }
};

// time complexity O(n) each token is processed exactly once with constant time stack operations 
