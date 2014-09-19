QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

TARGET   = QtUserTest


SOURCES += \
	src/main.cpp \
	src/TestDialog.cpp

HEADERS  += \
	src/TestDialog.h

FORMS    += \
	ui/TestDialog.ui

RESOURCES += \
	Resource.qrc
