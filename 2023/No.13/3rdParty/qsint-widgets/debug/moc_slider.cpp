/****************************************************************************
** Meta object code from reading C++ file 'slider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../slider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'slider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSint__Slider_t {
    QByteArrayData data[7];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSint__Slider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSint__Slider_t qt_meta_stringdata_QSint__Slider = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QSint::Slider"
QT_MOC_LITERAL(1, 14, 18), // "setPreciseMovement"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 2), // "on"
QT_MOC_LITERAL(4, 37, 12), // "setClickJump"
QT_MOC_LITERAL(5, 50, 17), // "onActionTriggered"
QT_MOC_LITERAL(6, 68, 2) // "id"

    },
    "QSint::Slider\0setPreciseMovement\0\0on\0"
    "setClickJump\0onActionTriggered\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSint__Slider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       1,    0,   42,    2, 0x2a /* Public | MethodCloned */,
       4,    1,   43,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x2a /* Public | MethodCloned */,
       5,    1,   47,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void QSint::Slider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Slider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPreciseMovement((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setPreciseMovement(); break;
        case 2: _t->setClickJump((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setClickJump(); break;
        case 4: _t->onActionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSint::Slider::staticMetaObject = { {
    QMetaObject::SuperData::link<QSlider::staticMetaObject>(),
    qt_meta_stringdata_QSint__Slider.data,
    qt_meta_data_QSint__Slider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSint::Slider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSint::Slider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSint__Slider.stringdata0))
        return static_cast<void*>(this);
    return QSlider::qt_metacast(_clname);
}

int QSint::Slider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
