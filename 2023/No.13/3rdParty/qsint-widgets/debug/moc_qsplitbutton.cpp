/****************************************************************************
** Meta object code from reading C++ file 'qsplitbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../qsplitbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsplitbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSint__QSplitButton_t {
    QByteArrayData data[10];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSint__QSplitButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSint__QSplitButton_t qt_meta_stringdata_QSint__QSplitButton = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QSint::QSplitButton"
QT_MOC_LITERAL(1, 20, 9), // "activated"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "data"
QT_MOC_LITERAL(4, 36, 12), // "selectAction"
QT_MOC_LITERAL(5, 49, 8), // "QAction*"
QT_MOC_LITERAL(6, 58, 19), // "selectActionByIndex"
QT_MOC_LITERAL(7, 78, 5), // "index"
QT_MOC_LITERAL(8, 84, 8), // "onAction"
QT_MOC_LITERAL(9, 93, 3) // "act"

    },
    "QSint::QSplitButton\0activated\0\0data\0"
    "selectAction\0QAction*\0selectActionByIndex\0"
    "index\0onAction\0act"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSint__QSplitButton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,

 // slots: parameters
    0x80000000 | 5, QMetaType::QVariant,    3,
    0x80000000 | 5, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 5,    9,

       0        // eod
};

void QSint::QSplitButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSplitButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: { QAction* _r = _t->selectAction((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 2: { QAction* _r = _t->selectActionByIndex((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 3: _t->onAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QSplitButton::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSplitButton::activated)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSint::QSplitButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QToolButton::staticMetaObject>(),
    qt_meta_stringdata_QSint__QSplitButton.data,
    qt_meta_data_QSint__QSplitButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSint::QSplitButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSint::QSplitButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSint__QSplitButton.stringdata0))
        return static_cast<void*>(this);
    return QToolButton::qt_metacast(_clname);
}

int QSint::QSplitButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QSint::QSplitButton::activated(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
