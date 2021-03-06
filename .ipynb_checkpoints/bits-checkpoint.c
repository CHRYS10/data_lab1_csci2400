/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
         
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) 
{
  return (~x & ~y); //DeMorgan's Law 
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) //DONE!!!
{
    //x is 0x80000000 = -2147483648 
    //x is 0x7fffffff = 2147483647
    //x is 0
    //case 1: x = 0x7fffffff, a = 0x0, return must be 0
    //case 2: x = 0x80000000, a = -0x1, return must be 0
    //case 3: x = 0x0, a = 0x0, return must be 1
    
    int a = (x >> 31); //0 or -1 after shifting
    // -0x10000 or 0xffff (e.g. 1111...0000 | 0000....1111) 
    int b = (x >> 15); 
    
    //case 1 return: b^a = 0xffff, !(0xffff) = 0 
    //case 2 return: b^a = 0xffff, !(0xffff) = 0
    //case 3 return b^a = 0x0, !(0x0) = 1 
    
    return !( (b)^(a) );
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) //DONE!!!
{
    //Output should be:
    //0x49249249	0100_1001_0010_0100_1001_0010_0100_1001	1227133513
    //Need to create a mask? every third bit is 1, all else 0
    //Created a long int to match size of output
    //Shifted and added max allowable hex values to reach correct output 
    
    long x = 0x49;   //0000_0000_0000_0000_0000_0000_0100_1001
    x = (x << 8);    //0000_0000_0000_0000_0100_1001_0000_0000
    x = x + 0x24;    //0000_0000_0000_0000_0100_1001_0010_0100
    x = (x << 8);    //0000_0000_0100_1001_0010_0100_0000_0000
    x = x + 0x92;    //0000_0000_0100_1001_0010_0100_1001_0010
    x = (x << 8);    //0100_1001_0010_0100_1001_0010_0000_0000
    x = (x + 0x49);  //0100_1001_0010_0100_1001_0010_0100_1001 (Yayy)
    
  return x;
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) //DONE!!!
{
    //Create a mask: 0x55555555 to check if any even bit is 1
    //Use & operator with var. x to see if the value is returned as 0 or 1
    
    long mask = 0x55;
    mask = (mask << 8);     //1
    mask = (mask + 0x55);   //2
    mask = (mask << 8);     //3
    mask = (mask + 0x55);   //4
    mask = (mask << 8);     //5
    mask = (mask + 0x55);   //6
    
    // (x&mask) returns 0x55555555 (mask)
    // in order to return correct value, double logical negation used:
    // !(x&mask) returns 1, !!(x&mask) returns 0 correctly
    
    return !!(x & mask); //+3 operations = 9 operations total
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) //DONE!!!
{
    //a = AND of x and 1, giving either 0 or 1
    //x = flip the bits of a (so all 0's become 1's or vice versa)
    //add one to x to make answer correct
    //     int a = x&1;
    //     x = ~a;
    //     return x+1;
    
    return ( ~(x & 1) ) + 1;
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) //DONE!!!
{
    //x is assigned the logical inverse of x using (!)
    //if x = 1, !x = 0 (and vice versa)
    //the return is using OR to return 0 or 1 depending on
    //the values of x and y input into function
    
    x = !x;
    return (x | y);
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) //DONE!!!
{
    //create a mask: ~ 0 = -1 = (1111...1111)
    //ex: (high = 5, low = 3):
    //a = ~0 << 3 = -0x8
    //b = ~0 << 5 = -0x20
    //b = b << 1 = -0x40
    //b = ~b = 0x3f (negate b) (0000...0011_1111)
    //b&a = 0x3f & -0x8 = 0x38 (0000...0011_1000)
    
    int mask = ~0;
    int a = (mask << lowbit);  //shifts all 1's left by lowbit input
    int b = (mask << highbit); //shifts all 1's left by highbit input
    b = ~(b << 1);             //shift b by 1 bit, then negate: 
    //returns mask of 1's
    //only where a and b both have 1's line up
    return (a & b);              
    
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) //DONE!!!
{
    int a;
    int b;
    int c;
    int d;
    int m;
   
    a = ( (x << 1) + x);  //same as adding (x + x + x) = num to divide
    m = (1 << 2) + ~0;    //0x4 + -0x1 = 0x3 -> mask
    b = (a >> 31);        //0x0 or -0x1 (ex: -9, output = -6)-> gen. sign
    c = (m & b);            //0x3 & 0x0 = 0x0   --> handles bias 
    d = ( (a + c) >> 2);  //(num + bias) >> 2 = output
    
    return d;
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) //RAN OUT OF TIME....
{
    //int Tmax;
    //int Tmin;
    x = (x << 1) + x;
    
    
    //Tmax = (~0) ^ (0x1 << 31);
    //Tmin = 0x1 << 31;
    
    return x;         //returns correct value = (x * 3), not correct...
    
    //return 2;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) //DONE!!!
{
    //depending on size of x input, parity shaves down x
    //by shifting input, then using XOR to compare 
    //value in parity and the shifted value of parity 
    //and store value of XOR operation in parity
    //Shifts by a total of 31 bits
    //Any large values (ex: 0x80000000 / 0x7FFFFFFF) work
    //Will eventually lead to either (0 | 1) in the LSB position
    //parity & 1 will set parity to either 0 or 1 after shifts have occurred.
    
    int parity;
    parity = x ^ (x >> 16);                    
    parity = parity ^ (parity >> 8);
    parity = parity ^ (parity >> 4);
    parity = parity ^ (parity >> 2);  //8 bit inputs ->parity is updated
    parity = parity ^ (parity >> 1);  
    parity = parity & 1;              //will set parity to (0 or 1)
    
    return parity;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) //RAN OUT OF TIME...
{
  return 2;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x) //RAN OUT OF TIME
{
    return 2;
}
//----------------------------------------------------------------------------
//RAN OUT OF TIME...
/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) 
{
 return 2;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) 
{
  return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) 
{
  return 2;
}

