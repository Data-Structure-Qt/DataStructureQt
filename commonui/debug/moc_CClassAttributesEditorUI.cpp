/****************************************************************************
** Meta object code from reading C++ file 'CClassAttributesEditorUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CClassAttributesEditorUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CClassAttributesEditorUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CClassAttributesEditorUI_t {
    QByteArrayData data[13];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CClassAttributesEditorUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CClassAttributesEditorUI_t qt_meta_stringdata_CClassAttributesEditorUI = {
    {
QT_MOC_LITERAL(0, 0, 24), // "CClassAttributesEditorUI"
QT_MOC_LITERAL(1, 25, 14), // "onSceneChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 28), // "on_Editor_currentItemChanged"
QT_MOC_LITERAL(4, 70, 14), // "QtBrowserItem*"
QT_MOC_LITERAL(5, 85, 7), // "rebuild"
QT_MOC_LITERAL(6, 93, 20), // "on_AddButton_clicked"
QT_MOC_LITERAL(7, 114, 23), // "on_ChangeButton_clicked"
QT_MOC_LITERAL(8, 138, 23), // "on_RemoveButton_clicked"
QT_MOC_LITERAL(9, 162, 14), // "onValueChanged"
QT_MOC_LITERAL(10, 177, 11), // "QtProperty*"
QT_MOC_LITERAL(11, 189, 8), // "property"
QT_MOC_LITERAL(12, 198, 3) // "val"

    },
    "CClassAttributesEditorUI\0onSceneChanged\0"
    "\0on_Editor_currentItemChanged\0"
    "QtBrowserItem*\0rebuild\0on_AddButton_clicked\0"
    "on_ChangeButton_clicked\0on_RemoveButton_clicked\0"
    "onValueChanged\0QtProperty*\0property\0"
    "val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CClassAttributesEditorUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x09 /* Protected */,
       3,    1,   50,    2, 0x09 /* Protected */,
       5,    0,   53,    2, 0x09 /* Protected */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    2,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QVariant,   11,   12,

       0        // eod
};

void CClassAttributesEditorUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CClassAttributesEditorUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSceneChanged(); break;
        case 1: _t->on_Editor_currentItemChanged((*reinterpret_cast< QtBrowserItem*(*)>(_a[1]))); break;
        case 2: _t->rebuild(); break;
        case 3: _t->on_AddButton_clicked(); break;
        case 4: _t->on_ChangeButton_clicked(); break;
        case 5: _t->on_RemoveButton_clicked(); break;
        case 6: _t->onValueChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CClassAttributesEditorUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CClassAttributesEditorUI.data,
    qt_meta_data_CClassAttributesEditorUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CClassAttributesEditorUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CClassAttributesEditorUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CClassAttributesEditorUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CClassAttributesEditorUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
