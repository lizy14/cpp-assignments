在 Visual Studio 2012 (MSVC 11.0) 下编译调试通过。

第1题："Game24"目录下。
采用暴力穷举。具体来讲，
* 4 个操作数要进行全排列（4!=24种）
* 3个运算符在加减乘除中随意选择（4^3=64种）
* 运算符的优先级，即括号的位置（5种）
一共有7680种可能性，一一检验。


第2题："Game24Extended"目录下。
同样采用暴力穷举。
* 输入数的全排列（n!种）
* 运算符组合（2^n种）
一共 (n! 2^n) 种。
这个数目巨大。当 n=24 时是 10409396852733332453861621760000。
（有同学指出题目要求中可能隐含了“按输入的顺序”，即不需要做全排列。）

编写了一个“24点游戏”类，成员变量包括操作数集合和目标结果。
编写了一个“24点游戏算式”类，成员变量包括操作数序列和运算符序列（编码为一个整数，其每一二进制位表示该位置上的运算符是加号还是乘号）。
有关这两个类的成员函数及相互调用关系，见头文件中的注释。


下面是吐槽。

第1题的样例输出简直。无视加法、乘法的交换律，大量重复结果，大量冗余的括号。
鄙人不才，以为要产生这样的结果，只能从表达式的文字形式上暴力穷举。
一些更加优雅的方法，比如生成一颗表达式树，便无用武之地。

此外第2题根本不能被称为第1题的拓展。
即使我把第1题写成“任意的目标D, n个数, m种运算符”（这本是很简单的，比如写成分治递归，搜到结果就输出），也对第2题没什么帮助。
不允许使用括号，必须从左往右算，所谓“为了简化问题”，实际上把第2题和第1题彻底地割裂开了。
此外，要求在无解时“退而求其次”，也造成第2题和第1题在程序设计思路上的本质不同。

为表示抗议，我决定把第1题彻底写死，不留任何可拓展性。
具体来讲，预先（编写程序穷举）计算出所有可能的表达式形式（共7680种），然后写死到代码里，7680行“if(..)..”。
我相信这种写法在运行时是最省时间的，尽管代码段占用的空间很大。

而第2题则是用另一种思路写的。
2015-7-21
