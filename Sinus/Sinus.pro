# http://doc.qt.io/qt-5/qmake-variable-reference.html

QT += core opengl widgets gui

DEFINES += QT_OPENGL_LIB QT_WIDGETS_LIB
INCLUDEPATH += .
LIBS += -lopengl32 -lglu32
    
HEADERS += sinus.h \
           canvas.h
SOURCES += canvas.cpp \
           sinus.cpp \
           main.cpp
