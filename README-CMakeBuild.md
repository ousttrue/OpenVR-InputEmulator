# CMake(+VSCode) でビルドできるようにした

WIP

## vcpkg

VC++をインストールしておく。
vcpkgでboostとQT5を導入する。

```
> git clone https://github.com/microsoft/vcpkg.git
> cd vcpkg
> bootstrap-vcpkg.bat
> vcpkg install boost:x64-windows # 長い
> vcpkg install qt5:x64-windows # 長い
```

環境変数 VCPKG_DIR=`cloneしたフォルダ`

## VSCode でフォルダを開いてビルドする
