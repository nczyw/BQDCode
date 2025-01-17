# BQDCode

## 使用的函数名，已经完全导出，后续会出Qt使用的方法

* [许可](https://www.apache.org/licenses/LICENSE-2.0.txt)
* 集成了[GNU Barcode](https://ftp.gnu.org/gnu/barcode/) 库
* 集成了[Dmtx](https://github.com/dmtx/libdmtx) 库
* 集成了[QRCode](https://github.com/fukuchi/libqrencode) 库，由于该库使用的开源协议为LGPLV2.1,我使用了静态编译的方式，生成了BDQRCode库,开放源码，对该库有任何修改，也必须开源
* 可以选择生成动态或者静态库，导出常用函数，用于创建 条码、二维码、Data Matrix
* 生成的数据只是一些点阵数据，需要配合UI库来显示，[Qt例子](https://github.com/nczyw/BQDLayout)
