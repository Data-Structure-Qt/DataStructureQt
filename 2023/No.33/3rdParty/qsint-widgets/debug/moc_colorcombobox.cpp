/****************************************************************************
** Meta object code from reading C++ file 'colorcombobox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../colorcombobox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorcombobox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSint__ColorComboBox_t {
    QByteArrayData data[10];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSint__ColorComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSint__ColorComboBox_t qt_meta_stringdata_QSint__ColorComboBox = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QSint::ColorComboBox"
QT_MOC_LITERAL(1, 21, 19), // "currentColorChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "color"
QT_MOC_LITERAL(4, 48, 8), // "setColor"
QT_MOC_LITERAL(5, 57, 15), // "setCurrentColor"
QT_MOC_LITERAL(6, 73, 21), // "onCurrentIndexChanged"
QT_MOC_LITERAL(7, 95, 5), // "index"
QT_MOC_LITERAL(8, 101, 8), // "onEdited"
QT_MOC_LITERAL(9, 110, 22) // "onSelectionTextChanged"

    },
    "QSint::ColorComboBox\0currentColorChanged\0"
    "\0color\0setColor\0setCurrentColor\0"
    "onCurrentIndexChanged\0index\0onEdited\0"
    "onSelectionTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSint__ColorComboBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x09 /* Protected */,
       8,    0,   56,    2, 0x09 /* Protected */,
       9,    0,   57,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSint::ColorComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColorComboBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->setCurrentColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->onCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onEdited(); break;
        case 5: _t->onSelectionTextChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ColorComboBox::*)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorComboBox::currentColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSint::ColorComboBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QComboBox::staticMetaObject>(),
    qt_meta_stringdata_QSint__ColorComboBox.data,
    qt_meta_data_QSint__ColorComboBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSint::ColorComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSint::ColorComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSint__ColorComboBox.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int QSint::ColorComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QSint::ColorComboBox::currentColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
