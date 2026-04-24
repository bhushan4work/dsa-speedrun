// statement- Given infix expression, task is to convert given infix expression to prefix expression
//  Approach:
//  Reverse given infix expression
//  When operand is encountered, add it in ans
//  If op is encountered & stack is empty, push op into stack
//  If scanned op has higher priority than top of stack, push it into stack
//  If scanned op has same priority as top of stack, push it into stack
//  If scanned op is other than '^' , put it in stack
//  If op is '(', put it in stack
//  If scanned char is a ‘)’, pop the stack & add it in ans until a ‘(’ is encountered, thereby discard both parenthesis
//  At end of expression, pop & add all remaining op from stack to ans
//  Finally, reverse the output & print it as prefix expression




//(optimal) t.c- O(n)  s.c- O(n)

