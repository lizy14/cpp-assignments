目标：
按给定规则给出基因遗传结果。

原理：
1.采用位运算。

如何编程和运行：
1.复用了 getInteger() 代码。
2.编写了 geneticInheritance() 函数，接受亲代基因，返回子代基因。
3.采用结构化程序设计方法。

结果：
1.人工验证：
对特定的输入进行了人工验证，即人脑先算一遍，与输出进行比较。
人工验证了(0,0)，(1,1)，(-1,-1),(0,233)四组。
通过率 100%。
2.自动验证：
采用代数运算（主要是乘法、除法、乘方，而不是位运算）重写了 geneticInheritance() 函数，将两个版本该函数的返回值进行比较。
采用了 144 组测试用例，详见 testReport.log。
通过率 100%。

结论：
本程序可靠。