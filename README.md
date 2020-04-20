# QML / CPP Template

## Purpose
This project is indented to form the base of a QML project that is loaded via C++.

## Features
* A few useful CMake settings
* QML reloading

## QML reloading
In order to enable the QML reloading, the CMake configuration variable `QML_FROM_SRC_DIR` must be set.
When set, QML files are loaded directly from the filesystem instead of using Qt's resources system
(e.g. the .qrc file).

