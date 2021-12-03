# TUGUI
a tiny uefi graphical user interfaces libaray......

## 1.最近动态

> 1.添加 数学相关基础库
>
> - 齐次坐标
> - ....
>
> 2.图形学 变换
>
> - 2D/3D
> - ....



## 2. 编译运行

### 2.1 开发环境

- 编译工具链: g++-mingw-w64-x86-64
- 编译工具: make
- 编辑工具: vs code
- 测试机器: VirtualBox 虚拟机
- 存储器: U盘/vhd虚拟磁盘
- other:
  - git
  - mount/umount
  - fdisk
  - mkfs.vfat

**交叉工具链**

```
sudo apt-get install g++-mingw-w64-x86-64 -y
```



### 2.2 编译源码

#### 2.2.1 获取源码

```shell
git clone -b dev git@github.com:UnknownBugs/TUGUI.git
```

#### 2.2.2 编译源码(目前仅支持测试Demo代码编译)

模块编译

```
make modules               #获取可选择的模块名
make modules=[moduleName]  #编译moduleName模块
```
编译所有模块

```
make
```

生成的文件目录说明

```
bin # 对应平台的可执行文件
obj # 编译中间产物
```

#### 2.2.3 对应平台运行

**VirtualBox:**

- VirtualBox新建虚拟机

  > name:xxx
  >
  > type: other
  >
  > Version: Unknown(64-bit)
  >
  > diskFileType: VHD
  >
  > 磁盘固定大小模式

- 配置虚拟机

  > setting -> system -> Enable EFI

- 格式化虚拟磁盘

  ```
  $ sudo fdisk [topath]/xxx.vhd
  Welcome to fdisk (util-linux 2.25.2).
  Changes will remain in memory only, until you decide to write them.
  Be careful before using the write command.
  
  Command (m for help): o             # 创建新的DOS分区表
  Created a new DOS disklabel with disk identifier 0xde746309.
  
  Command (m for help): n             # 建立新的分区
  Partition type
     p   primary (0 primary, 0 extended, 4 free)
     e   extended (container for logical partitions)
  Select (default p): p
  Partition number (1-4, default 1): 1
  First sector (2048-15228927, default 2048):
  Last sector, +sectors or +size{K,M,G,T,P} (2048-15228927, default 15228927):
  Created a new partition 1 of type 'Linux' and of size 7.3 GiB.
  
  Command (m for help): t             # 改变分区类型
  Selected partition 1
  Hex code (type L to list all codes): b
  If you have created or modified any DOS 6.x partitions, please see the fdisk \\
  documentation for additional information.
  Changed type of partition 'Linux' to 'W95 FAT32'.
  
  Command (m for help): w             # 保存分区表
  The partition table has been altered.
  Calling ioctl() to re-read partition table.
  Syncing disks.
  
  $ sudo mkfs.vfat -F 32 [topath]/xxx.vhd    # 格式化分区
  ```

- 把目标程序放入磁盘

  ```
  ./tools/install_to_disk.sh bin/[moduleName] [topath]/xxx.vhd
  ```

-  运行虚拟机



## 3.功能

>**基本图形**
>
>- 像素
>- 直线
>- 矩形
>- 三角形
>- 圆
>
>**图形变换**
>
>- 仿射变换
>  - Scale/缩放
>  - Translation/平移
>  - Rotation/旋转
>
>**事件机制**
>
>- 定时器
>- 键盘检测



### [Domo 展示](doc/funcDome.md)



## 4. 开发简述

### 4.1 编码规范

> 下列为提到及其他相关编码风格 以 google c++ style guide 为准
>
> - [English Version](https://google.github.io/styleguide/cppguide.html)
> - [中文版](https://zh-google-styleguide.readthedocs.io/en/latest/)

```c++
#include <c.h>     // *.h c头文件
#include <cpp.hpp> // *.hpp c++ 头文件

/* 当前文件 直接使用的头文件 */

namespace NAMESPACE { // 命名空间 全大写

class MyClass { // 类名大驼峰
    
public:
    // 函数名小驼峰
    void myFunc(long long paramLong) { // 函数形参 小驼峰
        paramLong = 2 + paramLong; // 运算符 之前 加空格
    }
    
    int mIntVar; // 共有成员变量 m*, 小驼峰
    
protected:
    double _mDoubleVar; // 在成员变量基础 上 一个字母为 下划线
private:
    char __mCharVar;  // 双下划线，小驼峰
    
}; // MyClass
}; // NAMESPACE 类与命名空间 结尾 注释

short gShortVar; // 全局变量 g*

int tuguiMain() { // 左大括号总在最后一个参数同一行的末尾处
    NAMESPACE::MyClass *myClassPtr { nullptr }; // 指针变量 *Ptr
    return 0;
}
```

### 4.2 Pull Request

- 1.尽量以一个事件为一个Pull Request， 多个事件 尽量分开多次Pull Request
- 2.每个Pull Request 需要 除自己外 的 一次 review (其他人)
- 3.reviews 的时候 看过的 文件 尽量 把 reviewed 打上对号
- 4.commit 记得用 -s 如: `git commit -s`

### 4.3 Issue

- 遇到 问题/bug等各种问题 都可以提个 Issue 用于记录

- other

### 4.4 开发者日志 [devDaily](doc/devDaily)

> 用于记录 开发过程，可以添加 任何内容。

**例如:**

#### 2021.11.23/24

`@speak`

>1.添加 齐次坐标 基础 结构
>
>2.齐次坐标测试case
>
>3.更新 README




## 5.QuickLinks
[UEFI DOC](https://kagurazakakotori.github.io/ubmp-cn/)