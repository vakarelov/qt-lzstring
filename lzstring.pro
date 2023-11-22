TEMPLATE = app
SUBDIRS += tests

#EDIT to fit you cofiguration
LIBS += -L/usr/lib/x86_64-linux-gnu -lQt5Core -lQt5Widgets
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/
QT += core widgets

include(src/lzstring.pri)

TARGET = lzstring

CONFIG = release console
