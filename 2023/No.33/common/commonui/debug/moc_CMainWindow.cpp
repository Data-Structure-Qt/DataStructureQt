/****************************************************************************
** Meta object code from reading C++ file 'CMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CMainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMainWindow_t {
    QByteArrayData data[19];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMainWindow_t qt_meta_stringdata_CMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CMainWindow"
QT_MOC_LITERAL(1, 12, 17), // "onDocumentChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "onAboutApplication"
QT_MOC_LITERAL(4, 50, 17), // "createNewDocument"
QT_MOC_LITERAL(5, 68, 7), // "docType"
QT_MOC_LITERAL(6, 76, 21), // "selectAndOpenDocument"
QT_MOC_LITERAL(7, 98, 12), // "openDocument"
QT_MOC_LITERAL(8, 111, 8), // "fileName"
QT_MOC_LITERAL(9, 120, 8), // "QAction*"
QT_MOC_LITERAL(10, 129, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(11, 153, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(12, 177, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(13, 203, 19), // "fillRecentFilesMenu"
QT_MOC_LITERAL(14, 223, 23), // "onRecentFilesMenuAction"
QT_MOC_LITERAL(15, 247, 15), // "fillWindowsMenu"
QT_MOC_LITERAL(16, 263, 19), // "onWindowsMenuAction"
QT_MOC_LITERAL(17, 283, 4), // "exit"
QT_MOC_LITERAL(18, 288, 6) // "onQuit"

    },
    "CMainWindow\0onDocumentChanged\0\0"
    "onAboutApplication\0createNewDocument\0"
    "docType\0selectAndOpenDocument\0"
    "openDocument\0fileName\0QAction*\0"
    "on_actionOpen_triggered\0on_actionSave_triggered\0"
    "on_actionSaveAs_triggered\0fillRecentFilesMenu\0"
    "onRecentFilesMenuAction\0fillWindowsMenu\0"
    "onWindowsMenuAction\0exit\0onQuit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    1,   96,    2, 0x0a /* Public */,
       6,    0,   99,    2, 0x0a /* Public */,
       7,    1,  100,    2, 0x0a /* Public */,
       4,    0,  103,    2, 0x09 /* Protected */,
       4,    1,  104,    2, 0x09 /* Protected */,
      10,    0,  107,    2, 0x09 /* Protected */,
      11,    0,  108,    2, 0x09 /* Protected */,
      12,    0,  109,    2, 0x09 /* Protected */,
      13,    0,  110,    2, 0x09 /* Protected */,
      14,    1,  111,    2, 0x09 /* Protected */,
      15,    0,  114,    2, 0x09 /* Protected */,
      16,    1,  115,    2, 0x09 /* Protected */,
      17,    0,  118,    2, 0x08 /* Private */,
      18,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDocumentChanged(); break;
        case 1: _t->onAboutApplication(); break;
        case 2: _t->createNewDocument((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->selectAndOpenDocument(); break;
        case 4: { bool _r = _t->openDocument((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->createNewDocument(); break;
        case 6: _t->createNewDocument((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->on_actionOpen_triggered(); break;
        case 8: _t->on_actionSave_triggered(); break;
        case 9: _t->on_actionSaveAs_triggered(); break;
        case 10: _t->fillRecentFilesMenu(); break;
        case 11: _t->onRecentFilesMenuAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 12: _t->fillWindowsMenu(); break;
        case 13: _t->onWindowsMenuAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 14: _t->exit(); break;
        case 15: _t->onQuit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CMainWindow.data,
    qt_meta_data_CMainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
