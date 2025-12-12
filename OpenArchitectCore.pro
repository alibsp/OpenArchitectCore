
QT += qml quick widgets
TEMPLATE = app
SOURCES += main.cpp
HEADERS += TacticalPluginInterface.hpp \
    UIEngine.hpp
RESOURCES += coreui.qrc
DESTDIR = $$PWD/../bin
