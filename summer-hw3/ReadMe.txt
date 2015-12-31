环境： Visual Studio 2012(MSVC++ 11.0)
外部库：无

类：

城堡信息类 class Castle;
成员为各楼层的vector。

城堡楼层信息类 class CastleLevel;
成员为各房间、各路径的vector。
含有指向父Castle对象的指针。

房间信息类 class CastleRoom;
含有指向父CastleLevel对象的指针。

路径信息类 class CastlePath;
含有指向父CastleLevel对象的指针。

虚拟基类 AbstractSAOSolver
仅含纯虚函数 Solve()。

暴力解算器类 BruteForceSAOSolver
暴击穷举、深度优先。写法是回溯递归。
递归终止，开始回溯的条件：
* 已经到达终点
* 已经无路可走
* 到达了一个曾经访问过的房间，且从上一次访问至今，装备值没有增加
* 截止当前的用时已经超过现存最短方案的用时
此外，程序引入了随机性：在读取输入后将 castle 每一层的边集随机打乱顺序。

快速解算器类 FastSAOSolver
贪心算法。写法还是回溯递归。
* 在前几层，每层寻找能获得最多装备值的上楼路线；
* 在最后几层，每层寻找用时最少的上楼路线。
* 用 clock() 函数控制运行时间：如果即将超时，立即输出结果并退出。
* 引入了随机性：在读取输入后将 castle 每一层的边集随机打乱顺序。

输入输出：
默认输入自 castleMap.txt
默认输出至 castleSolution.txt

