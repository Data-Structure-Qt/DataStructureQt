/****************************************************************************
** Meta object code from reading C++ file 'colorgrid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../colorgrid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorgrid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSint__ColorGrid_t {
    QByteArrayData data[13];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSint__ColorGrid_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSint__ColorGrid_t qt_meta_stringdata_QSint__ColorGrid = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QSint::ColorGrid"
QT_MOC_LITERAL(1, 17, 11), // "highlighted"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "color"
QT_MOC_LITERAL(4, 36, 6), // "picked"
QT_MOC_LITERAL(5, 43, 8), // "accepted"
QT_MOC_LITERAL(6, 52, 8), // "rejected"
QT_MOC_LITERAL(7, 61, 8), // "cellSize"
QT_MOC_LITERAL(8, 70, 12), // "widthInCells"
QT_MOC_LITERAL(9, 83, 8), // "autoSize"
QT_MOC_LITERAL(10, 92, 10), // "pickByDrag"
QT_MOC_LITERAL(11, 103, 9), // "clickMode"
QT_MOC_LITERAL(12, 113, 9) // "ClickMode"

    },
    "QSint::ColorGrid\0highlighted\0\0color\0"
    "picked\0accepted\0rejected\0cellSize\0"
    "widthInCells\0autoSize\0pickByDrag\0"
    "clickMode\0ClickMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSint__ColorGrid[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       5,   42, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    0,   40,    2, 0x06 /* Public */,
       6,    0,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00095103,
       8, QMetaType::Int, 0x00095103,
       9, QMetaType::Bool, 0x00095103,
      10, QMetaType::Bool, 0x00095103,
      11, 0x80000000 | 12, 0x0009510b,

       0        // eod
};

void QSint::ColorGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColorGrid *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->highlighted((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->picked((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->accepted(); break;
        case 3: _t->rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ColorGrid::*)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorGrid::highlighted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ColorGrid::*)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorGrid::picked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ColorGrid::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorGrid::accepted)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ColorGrid::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorGrid::rejected)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ColorGrid *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->cellSize(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->widthInCells(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->autoSize(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->pickByDrag(); break;
        case 4: *reinterpret_cast< ClickMode*>(_v) = _t->clickMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ColorGrid *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCellSize(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setWidthInCells(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setAutoSize(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setPickByDrag(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setClickMode(*reinterpret_cast< ClickMode*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QSint::ColorGrid::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QSint__ColorGrid.data,
    qt_meta_data_QSint__ColorGrid,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSint::ColorGrid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSint::ColorGrid::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSint__ColorGrid.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QSint::ColorGrid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QSint::ColorGrid::highlighted(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSint::ColorGrid::picked(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSint::ColorGrid::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QSint::ColorGrid::rejected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
