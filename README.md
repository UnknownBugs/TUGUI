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

>5.画矩形
>
>4.画圆
>
>3.任意角度直线
>
>2.坐标线
>
>1.像素控制

### [Domo 展示](doc/funcDome.md)




## 4.QuickLinks
[UEFI DOC](https://kagurazakakotori.github.io/ubmp-cn/)