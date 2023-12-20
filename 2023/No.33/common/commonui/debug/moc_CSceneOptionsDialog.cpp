/****************************************************************************
** Meta object code from reading C++ file 'CSceneOptionsDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CSceneOptionsDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSceneOptionsDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSceneOptionsDialog_t {
    QByteArrayData data[12];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSceneOptionsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSceneOptionsDialog_t qt_meta_stringdata_CSceneOptionsDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CSceneOptionsDialog"
QT_MOC_LITERAL(1, 20, 12), // "testGraphviz"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "graphvizPath"
QT_MOC_LITERAL(4, 47, 4), // "exec"
QT_MOC_LITERAL(5, 52, 13), // "CEditorScene&"
QT_MOC_LITERAL(6, 66, 5), // "scene"
QT_MOC_LITERAL(7, 72, 12), // "CEditorView&"
QT_MOC_LITERAL(8, 85, 4), // "view"
QT_MOC_LITERAL(9, 90, 12), // "OptionsData&"
QT_MOC_LITERAL(10, 103, 4), // "data"
QT_MOC_LITERAL(11, 108, 23) // "on_GraphvizTest_clicked"

    },
    "CSceneOptionsDialog\0testGraphviz\0\0"
    "graphvizPath\0exec\0CEditorScene&\0scene\0"
    "CEditorView&\0view\0OptionsData&\0data\0"
    "on_GraphvizTest_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSceneOptionsDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   32,    2, 0x0a /* Public */,
      11,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 9,    6,    8,   10,
    QMetaType::Void,

       0        // eod
};

void CSceneOptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CSceneOptionsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->testGraphviz((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: { int _r = _t->exec((*reinterpret_cast< CEditorScene(*)>(_a[1])),(*reinterpret_cast< CEditorView(*)>(_a[2])),(*reinterpret_cast< OptionsData(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->on_GraphvizTest_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CSceneOptionsDialog::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSceneOptionsDialog::testGraphviz)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CSceneOptionsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CSceneOptionsDialog.data,
    qt_meta_data_CSceneOptionsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CSceneOptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSceneOptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSceneOptionsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CSceneOptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CSceneOptionsDialog::testGraphviz(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
