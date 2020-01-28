# CMake(+VSCode) でビルドできるようにした

## VC++

* VisualStudioをインストール
    * C++
    * MFCを有効にする

## vcpkg

vcpkgでboostとQT5を導入する。

```
> git clone https://github.com/microsoft/vcpkg.git
> cd vcpkg
> bootstrap-vcpkg.bat
> vcpkg install boost:x64-windows # 長い
> vcpkg install qt5:x64-windows # 長い (MFCが必用)
```

環境変数 VCPKG_DIR=`cloneしたフォルダ`

## VSCode でフォルダを開いてビルドする

`vrinputemulator/bin/win64` にビルド物が集まる。

    * driver_inputemulator.dll
    * client_commandline.exe
    * client_overlay.exe
