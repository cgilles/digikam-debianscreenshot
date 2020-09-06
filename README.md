# Debian Screenshots

This experimental and legacy digiKam tool allows you to upload desktop captures to Debian documentation website.

# Dependencies

- Cmake 3.x.                        <https://cmake.org/>
- Qt5                               <https://www.qt.io/>
- ECM                               <https://invent.kde.org/frameworks/extra-cmake-modules>
- KF5::KIO                          <https://invent.kde.org/frameworks/kio>
- digiKam >= 7.2 plugin interface   <https://www.digikam.org>

# Compiling and Installing

- mdkir build
- cd build
- cmake . -DCMAKE_INSTALL_PREFIX=/usr
- make
- make install/fast

![](dsplugin.png)
