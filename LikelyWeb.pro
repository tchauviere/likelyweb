# -------------------------------------------------
# Project created by QtCreator 2010-02-12T23:44:48
# -------------------------------------------------
QT += network \
    opengl \
    webkit
TARGET = LikelyWeb
TEMPLATE = app
SOURCES += main.cpp \
    lwindow.cpp \
    ltabwidget.cpp \
    lwebpage.cpp \
    lproxy.cpp \
    tabwidgetdrag.cpp \
    llineedit.cpp \
    lwindowtitlebar.cpp \
    itemdl.cpp \
    ldlmanage.cpp
HEADERS += lwindow.h \
    ltabwidget.h \
    lwebpage.h \
    lproxy.h \
    tabwidgetdrag.h \
    llineedit.h \
    lwindowtitlebar.h \
    itemdl.h \
    ldlmanage.h
RESOURCES += webPageIcon.qrc
OTHER_FILES += iconDatabase.txt
FORMS += itemdl.ui \
    ldlmanage.ui
