# Debian Screenshots

This experimental and legacy digiKam tool allows you to upload desktop captures to Debian documentation website.

# Dependencies

## Common components

- Cmake 3.x.                        <https://cmake.org/>
- Qt5                               <https://www.qt.io/>

## From KDE framework

- ECM                               <https://invent.kde.org/frameworks/extra-cmake-modules>
- KF5::KIO                          <https://invent.kde.org/frameworks/kio>

## From digiKam

- digiKam >= 7.2 plugin interface   <https://www.digikam.org>

# Compiling and Installing

- mdkir build
- cd build
- cmake . -DCMAKE_INSTALL_PREFIX=/usr
- make
- make install/fast

![](dsplugin.png)
