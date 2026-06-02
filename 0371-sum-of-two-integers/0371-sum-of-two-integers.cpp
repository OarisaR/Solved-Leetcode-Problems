// XOR gives the sum bits without carries.
// carry occurs if both bit is 1. this is AND operation. 1&1 = 1!
// this carry is to be taken to the left bit each time :  (a XOR b) + (carry)

// a+b = (a XOR b) + (carry)
// a+b = (a XOR b) [no carry]

//  sum_without_carry = a ^ b
//  carry = (a & b) << 1
class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0) {
            int temp = a;
            a = a ^ b;           // sum
            b = (temp & b) << 1; // propagating carry to next bit
        }
        return a;
    }
};