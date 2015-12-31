环境：
* Visual Studio 2012 (MSVC++ 11.0)
* Qt5 Visual Studio Add-in 1.2.3
//莫怪我不喜欢 Qt Creator，熟悉的 IDE 坠吼了

库：
* Qt 5.3 32-bit for Desktop (MSVC 2012 OpenGL)
//莫怪我不想重新装个 Qt 5.5


表盘、数字显示之间的同步采用传统 connect 方式。
操作表盘时下方状态文字变化采用 QSignalMap。
操作时用 qDebug() 产生调试信息。

因为采用了布局（Layout），所以改变窗口大小时控件位置和大小可相应改变。


