QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    avl.cpp \
    avlt.cpp \
    main.cpp \
    mainwindow.cpp \
    rbt.cpp \
    splayt.cpp \
    treap.cpp

HEADERS += \
    avl.h \
    avlt.h \
    mainwindow.h \
    rbt.h \
    splayt.h \
    treap.h

FORMS += \
    avlt.ui \
    mainwindow.ui \
    rbt.ui \
    splayt.ui \
    treap.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
