TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QT -= gui
SOURCES += \
        main.cpp \
    ReadArg.cpp \
    ProcessingArray.cpp

HEADERS += \
    ReadArg.h \
    ProcessingArray.h

DISTFILES += \
    Test.txt \
    README.md \
    LICENSE
