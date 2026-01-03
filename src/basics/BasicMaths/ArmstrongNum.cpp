//statement- Given an integer N, return true it is an Armstrong number otherwise return false
//ArmstrongNum- An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

int main(){
    int n ;
    cin >> n ;
    int dup = n; 
    
    //counts num of digits
    int k = 0; //counter for num of digits
    int temp = n; //taken as variable as when we check 'n' below in while loop we need original num & not edited one
    while (temp > 0) {
        k++;
        temp /= 10; //removes lastdigit & returns rest of the num
    }
    
    int sum = 0;
    temp = n;
    while (temp > 0) {
        int lastdigit = temp % 10;
        sum += pow(lastdigit, k);
        temp /= 10; //removes lastdigit & returns rest of the num
    }

    return sum == dup; //returns true if ArmstrongNum ,else false
}