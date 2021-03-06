# 抽象：进程


## 提出问题
操作系统如何提供有许多cpu的假象？


### 基本技术
1. 时分共享
  允许资源油一个实体使用一小段时间，然后由另一个实体使用一小段时间。
  如：cpu或网络链接资源

2. 空分共享
  资源在空间上被划分给希望使用它的人。例
  如：硬盘空间


时分共享和空分共享相对应

### 调度策略(scheduling policy)
操作系统可能利用
1. 历史信息 如：哪个程序在最后一分钟运行得更多？
2. 工作负载知识 如：运行什么样类型的程序？
3. 性能指标 如：系统是否针对交互式性能或吞吐量进行优化？
进行决定

## 进程是什么？
进程只是一个在运行的程序，任何时刻都可以清点它在执行过程中访问或影响系统中的不同部分。

### 进程机器状态(machine state)
程序在运行时可以读取或更新的内容：
1. 内存：指令存在内存中。正在运行的程序读写数据也在内存中
  所以进程可以访问的内存（称为地址空间，address space）属于进程的一部分
2. 寄存器：指令可以读写寄存器
  - 指令指针
  - 栈指针
  - 帧指针
3. 持久储存设备的io信息


## 进程api
1. create
2. destroy
3. wait
4. miscellaneous control
5. status

## 进程创建

### 程序如何转化为进程
1. 尽早加载，程序运行之前将代码加载完成。
2. 惰性加载：分页和交换机制，需要的时候加载代码片段

代码从硬盘 =》 内存 =》cpu执行


## 进程状态
1. running 运行
2. ready 就绪
3. blocked 阻塞

其中i/o操作会引起阻塞，如果将io的操作插入系统运行中不同的顺序会造成不同的结果。这也证明了策略的重要性。