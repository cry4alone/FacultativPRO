QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addnewuserwindow.cpp \
    adminuser.cpp \
    adminwindow.cpp \
    authwindow.cpp \
    checkalluserswindow.cpp \
    main.cpp \
    mainwindow.cpp \
    regwindow.cpp \
    studentfacultativeswindow.cpp \
    studentpersonalwindow.cpp \
    studentuser.cpp \
    studentwindow.cpp \
    teacheruser.cpp \
    teacherwindow.cpp \
    user.cpp \
    userdb.cpp \
    windownavigator.cpp

HEADERS += \
    addnewuserwindow.h \
    adminuser.h \
    adminwindow.h \
    authwindow.h \
    checkalluserswindow.h \
    mainwindow.h \
    regwindow.h \
    studentfacultativeswindow.h \
    studentpersonalwindow.h \
    studentuser.h \
    studentwindow.h \
    teacheruser.h \
    teacherwindow.h \
    user.h \
    userdb.h \
    windownavigator.h

FORMS += \
    addnewuserwindow.ui \
    adminwindow.ui \
    authwindow.ui \
    checkalluserswindow.ui \
    mainwindow.ui \
    regwindow.ui \
    studentfacultativeswindow.ui \
    studentpersonalwindow.ui \
    studentwindow.ui \
    teacherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
