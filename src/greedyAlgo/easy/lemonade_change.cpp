// statement- arr represents queue of customer & value of bills they hold, determine if its possible to provide correct change to each customer. Customers can only pay with 5$\10$\20$ bills and we initially do not have any change at hand.
//            return true, if its possible to provide correct change for each customer else false

// (optimal) t.c- O(n)  s.c- O(1)
bool lemonadeChange(vector<int> &bills){
    int five = 0; // Counter for $5 bills
    int ten = 0;  // Counter for $10 bills

    for (int bill : bills){
        if (bill == 5){
            five++; // Customer pays with $5 -> no change needed
        }
        else if (bill == 10){
            if (five > 0){ // Customer pays with $10 -> needs $5 as change
                five--; // Give one $5 as change
                ten++;  // Accept the $10 bill
            }
            else{
                return false; // Cannot provide change
            }
        }
        else{ // bill == 20
            
            // Customer pays with $20 -> needs $15 as change
            if (five > 0 && ten > 0){
                five--; // Use one $5
                ten--;  // Use one $10
            }
            else if (five >= 3){
                five -= 3; // Use three $5 bills
            }
            else{
                return false; // Cannot provide change
            }
        }
    }
    return true; // Successfully gave change to all customers
}