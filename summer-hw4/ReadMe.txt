环境：
* Visual Studio 2012 (MSVC++ 11.0)
* Qt5 Visual Studio Add-in 1.2.3
//莫怪我不喜欢 Qt Creator，熟悉的 IDE 坠吼了

库：
* Qt 5.3 32-bit for Desktop (MSVC 2012 OpenGL)
//莫怪我不想重新装个 Qt 5.5


华氏度表盘的事件采用 connect 方式将信号连接到相应的槽；
摄氏度表盘的事件采用自动关联。
用了一下 qDebug()。
所以这一个项目完成了两道题←_←

因为采用了布局（Layout），所以改变窗口大小时控件位置和大小可相应改变。


附有 Win32 可执行文件。
