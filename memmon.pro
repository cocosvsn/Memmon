!win32{
 error("Memmon can only be run on windows !")
}
INCLUDEPATH = .
DEPENDPATH = .

include(./src/3dparty/qtsingleapplication/qtsingleapplication.pri)
include(./src/3dparty/sigar/sigar.pri)
include(./src/src.pri)
include(./src/xprocesstable/xprocesstable.pri)
include(./version.pri)
include(./src/ctrl/ctrl.pri)

TEMPLATE = app

# config build exe
CONFIG(debug,debug|release){
  TARGET = memmond
}

CONFIG(release,debug|release){
  TARGET = memmon
}

RESOURCES += ./res.qrc

# config build dirs
CONFIG(debug,debug|release){
  OBJECTS_DIR = build/debug/.obj
  RCC_DIR = build/debug/.rcc
  MOC_DIR = build/debug/.moc
}

CONFIG(release,debug|release){
  OBJECTS_DIR = build/release/.obj
  RCC_DIR = build/release/.rcc
  MOC_DIR = build/release/.moc
}
