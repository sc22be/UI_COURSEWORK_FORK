QT       += core gui widgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/application.cpp \
    core/core.cpp \
    core/countdown.cpp \
    core/settings.cpp \
    core/user.cpp \
    core/video/post.cpp \
    core/video/video.cpp \
    core/videodb.cpp \
    homepage.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    page.cpp \
    profilepage.cpp \
    registerpage.cpp \
    settingspage.cpp

HEADERS += \
    core/application.h \
    core/core.h \
    core/countdown.h \
    core/settings.h \
    core/user.h \
    core/video/post.h \
    core/video/video.h \
    core/videodb.h \
    homepage.h \
    loginpage.h \
    mainwindow.h \
    page.h \
    profilepage.h \
    registerpage.h \
    settingspage.h

FORMS += \
    core/video/post.ui \
    homepage.ui \
    loginpage.ui \
    mainwindow.ui \
    profilepage.ui \
    registerpage.ui \
    settingspage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    VideoPlayer.qss \
    assets/button_images/leftArrow.jpg

RESOURCES += \
    VideoPlayer.qrc

TRANSLATIONS = assets/translations/staysimple_en_US.ts \
    assets/translations/staysimple_tr.ts \
    assets/translations/staysimple_en_GB.ts
