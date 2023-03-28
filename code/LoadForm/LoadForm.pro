QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    regform.cpp \
    regsucceeform.cpp \
    tcpclient.cpp \
    verifyform.cpp

HEADERS += \
    mainwindow.h \
    regform.h \
    regsucceeform.h \
    tcpclient.h \
    verifyform.h

FORMS += \
    mainwindow.ui \
    regform.ui \
    regsucceeform.ui \
    tcpclient.ui \
    verifyform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    qss/psblack/add_bottom.png \
    qss/psblack/add_left.png \
    qss/psblack/add_right.png \
    qss/psblack/add_top.png \
    qss/psblack/branch_close.png \
    qss/psblack/branch_open.png \
    qss/psblack/calendar_nextmonth.png \
    qss/psblack/calendar_prevmonth.png \
    qss/psblack/checkbox_checked.png \
    qss/psblack/checkbox_checked_disable.png \
    qss/psblack/checkbox_parcial.png \
    qss/psblack/checkbox_parcial_disable.png \
    qss/psblack/checkbox_unchecked.png \
    qss/psblack/checkbox_unchecked_disable.png \
    qss/psblack/radiobutton_checked.png \
    qss/psblack/radiobutton_checked_disable.png \
    qss/psblack/radiobutton_unchecked.png \
    qss/psblack/radiobutton_unchecked_disable.png

RESOURCES += \
    image.qrc
