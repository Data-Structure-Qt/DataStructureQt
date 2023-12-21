/****************************************************************************
** Meta object code from reading C++ file 'CAttributesEditorUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CAttributesEditorUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CAttributesEditorUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAttributesEditorUI_t {
    QByteArrayData data[11];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAttributesEditorUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAttributesEditorUI_t qt_meta_stringdata_CAttributesEditorUI = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CAttributesEditorUI"
QT_MOC_LITERAL(1, 20, 20), // "on_AddButton_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 23), // "on_ChangeButton_clicked"
QT_MOC_LITERAL(4, 66, 23), // "on_RemoveButton_clicked"
QT_MOC_LITERAL(5, 90, 28), // "on_Editor_currentItemChanged"
QT_MOC_LITERAL(6, 119, 14), // "QtBrowserItem*"
QT_MOC_LITERAL(7, 134, 14), // "onValueChanged"
QT_MOC_LITERAL(8, 149, 11), // "QtProperty*"
QT_MOC_LITERAL(9, 161, 8), // "property"
QT_MOC_LITERAL(10, 170, 3) // "val"

    },
    "CAttributesEditorUI\0on_AddButton_clicked\0"
    "\0on_ChangeButton_clicked\0"
    "on_RemoveButton_clicked\0"
    "on_Editor_currentItemChanged\0"
    "QtBrowserItem*\0onValueChanged\0QtProperty*\0"
    "property\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAttributesEditorUI[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    2,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QVariant,    9,   10,

       0        // eod
};

void CAttributesEditorUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CAttributesEditorUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_AddButton_clicked(); break;
        case 1: _t->on_ChangeButton_clicked(); break;
        case 2: _t->on_RemoveButton_clicked(); break;
        case 3: _t->on_Editor_currentItemChanged((*reinterpret_cast< QtBrowserItem*(*)>(_a[1]))); break;
        case 4: _t->onValueChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CAttributesEditorUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CAttributesEditorUI.data,
    qt_meta_data_CAttributesEditorUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAttributesEditorUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAttributesEditorUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAttributesEditorUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CAttributesEditorUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
