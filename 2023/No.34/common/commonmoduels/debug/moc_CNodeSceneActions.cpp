/****************************************************************************
** Meta object code from reading C++ file 'CNodeSceneActions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CNodeSceneActions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CNodeSceneActions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CNodeSceneActions_t {
    QByteArrayData data[18];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CNodeSceneActions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CNodeSceneActions_t qt_meta_stringdata_CNodeSceneActions = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CNodeSceneActions"
QT_MOC_LITERAL(1, 18, 10), // "editNodeId"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "CNode*"
QT_MOC_LITERAL(4, 37, 4), // "node"
QT_MOC_LITERAL(5, 42, 10), // "editEdgeId"
QT_MOC_LITERAL(6, 53, 6), // "CEdge*"
QT_MOC_LITERAL(7, 60, 4), // "edge"
QT_MOC_LITERAL(8, 65, 17), // "onActionNodeColor"
QT_MOC_LITERAL(9, 83, 12), // "onActionLink"
QT_MOC_LITERAL(10, 96, 14), // "onActionUnlink"
QT_MOC_LITERAL(11, 111, 11), // "onActionDFS"
QT_MOC_LITERAL(12, 123, 11), // "onActionBFS"
QT_MOC_LITERAL(13, 135, 17), // "onActionEdgeColor"
QT_MOC_LITERAL(14, 153, 19), // "onActionEdgeReverse"
QT_MOC_LITERAL(15, 173, 20), // "onActionEdgeDirected"
QT_MOC_LITERAL(16, 194, 18), // "onActionEdgeMutual"
QT_MOC_LITERAL(17, 213, 22) // "onActionEdgeUndirected"

    },
    "CNodeSceneActions\0editNodeId\0\0CNode*\0"
    "node\0editEdgeId\0CEdge*\0edge\0"
    "onActionNodeColor\0onActionLink\0"
    "onActionUnlink\0onActionDFS\0onActionBFS\0"
    "onActionEdgeColor\0onActionEdgeReverse\0"
    "onActionEdgeDirected\0onActionEdgeMutual\0"
    "onActionEdgeUndirected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CNodeSceneActions[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       5,    1,   77,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,
      14,    0,   86,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x0a /* Public */,
      16,    0,   88,    2, 0x0a /* Public */,
      17,    0,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Bool, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CNodeSceneActions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CNodeSceneActions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->editNodeId((*reinterpret_cast< CNode*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->editEdgeId((*reinterpret_cast< CEdge*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->onActionNodeColor(); break;
        case 3: _t->onActionLink(); break;
        case 4: _t->onActionUnlink(); break;
        case 5: _t->onActionDFS(); break;
        case 6: _t->onActionBFS(); break;
        case 7: _t->onActionEdgeColor(); break;
        case 8: _t->onActionEdgeReverse(); break;
        case 9: _t->onActionEdgeDirected(); break;
        case 10: _t->onActionEdgeMutual(); break;
        case 11: _t->onActionEdgeUndirected(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CNodeSceneActions::staticMetaObject = { {
    QMetaObject::SuperData::link<CEditorSceneActions::staticMetaObject>(),
    qt_meta_stringdata_CNodeSceneActions.data,
    qt_meta_data_CNodeSceneActions,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CNodeSceneActions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CNodeSceneActions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CNodeSceneActions.stringdata0))
        return static_cast<void*>(this);
    return CEditorSceneActions::qt_metacast(_clname);
}

int CNodeSceneActions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CEditorSceneActions::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
