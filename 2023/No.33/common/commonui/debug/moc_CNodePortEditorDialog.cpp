/****************************************************************************
** Meta object code from reading C++ file 'CNodePortEditorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CNodePortEditorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CNodePortEditorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CNodePortEditorDialog_t {
    QByteArrayData data[9];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CNodePortEditorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CNodePortEditorDialog_t qt_meta_stringdata_CNodePortEditorDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CNodePortEditorDialog"
QT_MOC_LITERAL(1, 22, 29), // "on_Anchor_currentIndexChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 5), // "index"
QT_MOC_LITERAL(4, 59, 23), // "on_OffsetX_valueChanged"
QT_MOC_LITERAL(5, 83, 1), // "v"
QT_MOC_LITERAL(6, 85, 23), // "on_OffsetY_valueChanged"
QT_MOC_LITERAL(7, 109, 18), // "on_Color_activated"
QT_MOC_LITERAL(8, 128, 5) // "color"

    },
    "CNodePortEditorDialog\0"
    "on_Anchor_currentIndexChanged\0\0index\0"
    "on_OffsetX_valueChanged\0v\0"
    "on_OffsetY_valueChanged\0on_Color_activated\0"
    "color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CNodePortEditorDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QColor,    8,

       0        // eod
};

void CNodePortEditorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CNodePortEditorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Anchor_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_OffsetX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_OffsetY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_Color_activated((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CNodePortEditorDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CNodePortEditorDialog.data,
    qt_meta_data_CNodePortEditorDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CNodePortEditorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CNodePortEditorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CNodePortEditorDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CNodePortEditorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
