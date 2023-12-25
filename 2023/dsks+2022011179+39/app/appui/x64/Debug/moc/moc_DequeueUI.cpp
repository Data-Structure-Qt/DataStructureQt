/****************************************************************************
** Meta object code from reading C++ file 'DequeueUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DequeueUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DequeueUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DequeueUI_t {
    QByteArrayData data[9];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DequeueUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DequeueUI_t qt_meta_stringdata_DequeueUI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DequeueUI"
QT_MOC_LITERAL(1, 10, 18), // "SearchBtn_SendText"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "on_create_btn_clicked"
QT_MOC_LITERAL(4, 52, 20), // "on_clean_btn_clicked"
QT_MOC_LITERAL(5, 73, 25), // "on_headinsert_btn_clicked"
QT_MOC_LITERAL(6, 99, 25), // "on_tailinsert_btn_clicked"
QT_MOC_LITERAL(7, 125, 25), // "on_headdelete_btn_clicked"
QT_MOC_LITERAL(8, 151, 25) // "on_taildelete_btn_clicked"

    },
    "DequeueUI\0SearchBtn_SendText\0\0"
    "on_create_btn_clicked\0on_clean_btn_clicked\0"
    "on_headinsert_btn_clicked\0"
    "on_tailinsert_btn_clicked\0"
    "on_headdelete_btn_clicked\0"
    "on_taildelete_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DequeueUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DequeueUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DequeueUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SearchBtn_SendText(); break;
        case 1: _t->on_create_btn_clicked(); break;
        case 2: _t->on_clean_btn_clicked(); break;
        case 3: _t->on_headinsert_btn_clicked(); break;
        case 4: _t->on_tailinsert_btn_clicked(); break;
        case 5: _t->on_headdelete_btn_clicked(); break;
        case 6: _t->on_taildelete_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DequeueUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DequeueUI::SearchBtn_SendText)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DequeueUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DequeueUI.data,
    qt_meta_data_DequeueUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DequeueUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DequeueUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DequeueUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DequeueUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DequeueUI::SearchBtn_SendText()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
