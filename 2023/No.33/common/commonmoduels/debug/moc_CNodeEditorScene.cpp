/****************************************************************************
** Meta object code from reading C++ file 'CNodeEditorScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CNodeEditorScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CNodeEditorScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CNodeEditorScene_t {
    QByteArrayData data[7];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CNodeEditorScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CNodeEditorScene_t qt_meta_stringdata_CNodeEditorScene = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CNodeEditorScene"
QT_MOC_LITERAL(1, 17, 15), // "editModeChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "mode"
QT_MOC_LITERAL(4, 39, 11), // "setEditMode"
QT_MOC_LITERAL(5, 51, 8), // "EditMode"
QT_MOC_LITERAL(6, 60, 18) // "onSelectionChanged"

    },
    "CNodeEditorScene\0editModeChanged\0\0"
    "mode\0setEditMode\0EditMode\0onSelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CNodeEditorScene[] = {

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
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void,

       0        // eod
};

void CNodeEditorScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CNodeEditorScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setEditMode((*reinterpret_cast< EditMode(*)>(_a[1]))); break;
        case 2: _t->onSelectionChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CNodeEditorScene::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CNodeEditorScene::editModeChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CNodeEditorScene::staticMetaObject = { {
    QMetaObject::SuperData::link<CEditorScene::staticMetaObject>(),
    qt_meta_stringdata_CNodeEditorScene.data,
    qt_meta_data_CNodeEditorScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CNodeEditorScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CNodeEditorScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CNodeEditorScene.stringdata0))
        return static_cast<void*>(this);
    return CEditorScene::qt_metacast(_clname);
}

int CNodeEditorScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CEditorScene::qt_metacall(_c, _id, _a);
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
void CNodeEditorScene::editModeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
