QT       += core gui sql svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addnewuserwindow.cpp \
    adminwindow.cpp \
    authwindow.cpp \
    changeuserfromadmin.cpp \
    checkalluserswindow.cpp \
    facultativ.cpp \
    facultativesmodel.cpp \
    facultativschedulewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    regwindow.cpp \
    signforfacultativwindow.cpp \
    studentfacultativeswindow.cpp \
    studentpersonalwindow.cpp \
    studentwindow.cpp \
    teachercreatefacultative.cpp \
    teacherwindow.cpp \
    user.cpp \
    userdb.cpp \
    usersmodel.cpp \
    windownavigator.cpp

HEADERS += \
    addnewuserwindow.h \
    adminwindow.h \
    authwindow.h \
    changeuserfromadmin.h \
    checkalluserswindow.h \
    facultativ.h \
    facultativesmodel.h \
    facultativschedulewindow.h \
    mainwindow.h \
    regwindow.h \
    signforfacultativwindow.h \
    studentfacultativeswindow.h \
    studentpersonalwindow.h \
    studentwindow.h \
    teachercreatefacultative.h \
    teacherwindow.h \
    user.h \
    userdb.h \
    usersmodel.h \
    windownavigator.h

FORMS += \
    addnewuserwindow.ui \
    adminwindow.ui \
    authwindow.ui \
    changeuserfromadmin.ui \
    checkalluserswindow.ui \
    facultativschedulewindow.ui \
    mainwindow.ui \
    regwindow.ui \
    signforfacultativwindow.ui \
    studentfacultativeswindow.ui \
    studentpersonalwindow.ui \
    studentwindow.ui \
    teachercreatefacultative.ui \
    teacherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
