This file contains materials for one instance of the attacklab.
该文件包含一个Attacklab实例的资料。

Files:

    ctarget

Linux binary with code-injection vulnerability.  To be used for phases
1-3 of the assignment.
具有代码注入漏洞的Linux二进制文件。 用于作业的1-3阶段。
ps. 用来做代码注入攻击的程序

    rtarget

Linux binary with return-oriented programming vulnerability.  To be
used for phases 4-5 of the assignment.
Linux二进制文件，具有面向返回的编程漏洞。 用于分配的阶段4-5
ps. 用来做 ROP 攻击的程序
     cookie.txt

Text file containing 4-byte signature required for this lab instance.
包含此实验室实例所需的4字节签名的文本文件。
ps. 一个 8 位的 16 进制代码，用来作为攻击的标识符

     farm.c

Source code for gadget farm present in this instance of rtarget.  You
can compile (use flag -Og) and disassemble it to look for gadgets.
此 rtarget 实例中的 gadget 农场的源代码。您可以编译(使用标志 -Og)和反汇编来查找小工具。
ps. 用来找寻 gadget 的源文件

     hex2raw

Utility program to generate byte sequences.  See documentation in lab
handout.
生成字节序列的实用程序。请参阅实验室讲义中的文档。
ps. 用来生成攻击字符串的程序

