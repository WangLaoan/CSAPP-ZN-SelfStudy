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

// 不要包含<stdio.h>标头； 它混淆了dlc *编译器。 尽管您可能会收到编译
// 器警告，但仍可以使用printf进行调试而无需包括* <stdio.h>。 
// 通常，*忽略编译器警告不是一个好习惯，但是在这种情况下*是可以的

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */
 // 第一步：仔细阅读以下说明。

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.
您将通过编辑此源文件中的功能集合为数据实验室提供解决方案

INTEGER CODING RULES:
整数编码规则:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
  用实现该功能的一行或多行C代码替换每个功能中的“return”语句。 您的代码必须符合以下样式：
 
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
  每个“Expr”都是仅使用以下内容的表达式：
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
      整数常数0到255（0xFF）（含）。 不允许使用大常量，例如0xffffffff。

  2. Function arguments and local variables (no global variables).
  函数参数和局部变量（无全局变量）。

  3. Unary integer operations ! ~
  一元整数运算！~

  4. Binary integer operations & ^ | + << >>
  二进制整数运算＆^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.
  有些问题甚至进一步限制了允许的操作符集。每个“Expr”可以由多个运算符组成。每行不限于一个运算符。

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.
     你被明确禁止:

  1. 使用任何控制结构，例如 if，do，while，for，switch 等
  2. 定义或使用任何宏。
  3. 在这个文件中定义任何附加函数。
  4. 调用任何函数。
  5. 使用任何其他操作，例如 &&, ||, -, or ?
  6. 使用任何形式的显式类型转换。
  7. 使用 int 以外的任何数据类型。这意味着不能使用数组、结构或联合。

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  您可以假设您的机器：
  1.使用2s补码（32位整数表示）。
  2.算术右移。
  3.如果移位量小于0或大于31，则在移位时具有不可预测的行为。

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
浮点编码规则

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.
对于要求您实现浮点运算的问题，编码规则不太严格。 
允许您使用循环和条件控制。 允许您同时使用整数和无符号。
您可以使用任意整数和无符号常量。 您可以对int或无符号数据使用任何算术，逻辑或比较运算。

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.
    明确禁止您：
  1.定义或使用任何宏。
  2.在此文件中定义任何其他函数。
  3.调用任何函数。
  4.使用任何形式的显式类型转换。
  5.使用int或unsigned以外的任何其他数据类型。 这意味着您不能使用数组，结构或联合。
  6.使用任何浮点数据类型，操作或常量。


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
  备注:

  1. 使用 dlc (数据实验室检查器)编译器(在讲义中描述)来检查你的解决方案的合法性。
  2. 每个函数都有一个允许用于实现该函数的最大操作数(整数、逻辑或比较)。最大运算符计数由 dlc 检查。
    请注意赋值(’=’)是不计算在内的; 您可以使用任意数量的赋值，而不会受到惩罚。
  3. 使用 btest 测试工具检查函数的正确性。
  4. 使用 BDD 检查器正式验证您的功能
  5.每个函数的最大操作数都在每个函数的头部注释中给出。如果记录中的最大操作数与此文件中的最大操作数不一致，请将此文件视为权威源文件。

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */
// 第二步：根据编码规则修改以下功能。
// *很重要。为避免意外评分：
// * 1. 使用dlc编译器检查您的解决方案是否符合编码规则。
// * 2. 使用BDD检查器正式验证您的解决方案是否产生了正确的答案。

#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return (~(~x&~y)) & (~(x&y));
}
/* 
 * tmin - return minimum two's complement integer //返回最小二进制补码整数
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int x = 1;
  return x << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // Tmax 满足特征: +1 和 自身相反数 刚好相等
  // -1 (1111...1111) 亦满足此特征, 所以特判筛掉

  // 比较 all位 相同 ! (A ^ B)
  // !A -> A有1就是0， 全0是1
  // !!A -> A有1就是1， 全0是0
  return !((x+1)^(~x))&!!((x+1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *    返回1，如果字中所有奇数位都为1  ，其中位从0(最低有效位)到31(最高有效位)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *    0xFFFFFFFD -> 1111 1111 ... 1111 1101
 *    0xAAAAAAAA -> 1010 1010 ... 1010 1010
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */


int allOddBits(int x) {
  //  Warning: 47 operators exceeds max of 12
  // return ((x>>1)&1) & ((x>>3)&1) & ((x>>5)&1) & ((x>>7)&1) \
  //         & ((x>>9)&1) & ((x>>11)&1) & ((x>>13)&1) & ((x>>15)&1) \
  //         & ((x>>17)&1) & ((x>>19)&1) & ((x>>21)&1) & ((x>>23)&1) \
  //         & ((x>>25)&1) & ((x>>27)&1) & ((x>>29)&1) & ((x>>31)&1) \
  //         ;
  // 构造掩码 aa |aa |aa |aa (1010 1010 |1010 1010 ... )
  int m = 0xaa;
  m += m<<8;
  m += m<<16;
  // 想要位 &
  int n = x & m;
  return !(n ^ m); // 和 1010 1010 1010 1010 比较异同

}
/* 
 * negate - return -x 
 *   返回相反数
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 0011 0000 -> 0x30
  // 0011 1001 -> 0x39
  // 思路 0011 1001 特判； 剩下只要00110开头即可
  int a = !(x ^ 0x39);
  int b = !(x ^ 0x38);
  // 00110开头? 构造掩码
  int cmp = 0x30;
  // int base = 0x1 << 3 + 0xff<<4; // 1111 1000
  int mask = (~0) << 3; // ff ff ff (1111 1000)
  int c = !((x&mask) ^ cmp);
  return a | b | c;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask = ~(~!x+1);
  return (y & mask) | (z & ~mask);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // x <= y   ->  x + (-y) <= 0
  // 1. x-1 y+0
  // 2. x+0 y-1
  // 3. x-1 y-1
  // 4. x+0 y+0
  int xh = !!(x >> 31);
  int yh = !!(y >> 31);
  // 相等的情况
  int equal = !(x^y);
  // 不等1：头 等 x + (-y) < 0
  int head = (x + (~y + 1)) >> 31;
  int less1 = !(xh^yh) & !!head;
  // 不等2：头 不等 x-1 y+0
  int less2 = xh & !yh;

  return equal | less1 | less2;

}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *    实现！运算符，使用除!以外的所有合法运算符
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return 2;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  return 0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  return 2;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
