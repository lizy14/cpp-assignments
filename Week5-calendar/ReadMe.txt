目标：
编写日期类，求给定天数前或后的日期。

原理及如何编程：
1.1.编写了一个日期类，有移动指定天数的方法。
1.1.1.编写了前移1天、后移1天的方法，需平移任意天数时重复调用上述方法。
1.2.获取系统日期采用 time.h 中的库函数，保证可跨平台编译运行。
1.3.复用了从控制台获取一个整数的代码。

如何运行：
1.首先获取系统时间，若失败则请求用户输入时间；
2.请用户输入移动的天数；
3.计算并输出移动后的日期。

结果：
白盒测试显示程序可靠，在公元历法规则修改之前，当年份处于公元元年之后、小于MAX_INT，且移动的天数小于MAX_INT。
