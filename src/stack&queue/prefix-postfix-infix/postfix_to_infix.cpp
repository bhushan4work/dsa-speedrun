// statement- Given infix expression, task is to convert given infix expression to prefix expression
// Approach:
// Use stack to store operands
// For each op, pop 2 operands from stack, wrap them in parentheses, push resulting expression back
// final item in stack will be infix expression


//(optimal) t.c- O(n)  s.c- O(n)