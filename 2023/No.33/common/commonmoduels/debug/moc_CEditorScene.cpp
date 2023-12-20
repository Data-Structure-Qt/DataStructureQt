/****************************************************************************
** Meta object code from reading C++ file 'CEditorScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CEditorScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CEditorScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CEditorScene_t {
    QByteArrayData data[49];
    char stringdata0[554];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CEditorScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CEditorScene_t qt_meta_stringdata_CEditorScene = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CEditorScene"
QT_MOC_LITERAL(1, 13, 13), // "undoAvailable"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "redoAvailable"
QT_MOC_LITERAL(4, 42, 12), // "sceneChanged"
QT_MOC_LITERAL(5, 55, 18), // "sceneDoubleClicked"
QT_MOC_LITERAL(6, 74, 25), // "QGraphicsSceneMouseEvent*"
QT_MOC_LITERAL(7, 100, 10), // "mouseEvent"
QT_MOC_LITERAL(8, 111, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(9, 126, 11), // "clickedItem"
QT_MOC_LITERAL(10, 138, 17), // "infoStatusChanged"
QT_MOC_LITERAL(11, 156, 6), // "status"
QT_MOC_LITERAL(12, 163, 10), // "enableGrid"
QT_MOC_LITERAL(13, 174, 2), // "on"
QT_MOC_LITERAL(14, 177, 14), // "enableGridSnap"
QT_MOC_LITERAL(15, 192, 16), // "enableItemLabels"
QT_MOC_LITERAL(16, 209, 4), // "undo"
QT_MOC_LITERAL(17, 214, 4), // "redo"
QT_MOC_LITERAL(18, 219, 9), // "selectAll"
QT_MOC_LITERAL(19, 229, 11), // "deselectAll"
QT_MOC_LITERAL(20, 241, 10), // "selectItem"
QT_MOC_LITERAL(21, 252, 6), // "CItem*"
QT_MOC_LITERAL(22, 259, 4), // "item"
QT_MOC_LITERAL(23, 264, 9), // "exclusive"
QT_MOC_LITERAL(24, 274, 11), // "selectItems"
QT_MOC_LITERAL(25, 286, 13), // "QList<CItem*>"
QT_MOC_LITERAL(26, 300, 5), // "items"
QT_MOC_LITERAL(27, 306, 3), // "del"
QT_MOC_LITERAL(28, 310, 3), // "cut"
QT_MOC_LITERAL(29, 314, 4), // "copy"
QT_MOC_LITERAL(30, 319, 16), // "setPastePosition"
QT_MOC_LITERAL(31, 336, 6), // "anchor"
QT_MOC_LITERAL(32, 343, 7), // "pasteAt"
QT_MOC_LITERAL(33, 351, 5), // "paste"
QT_MOC_LITERAL(34, 357, 4), // "crop"
QT_MOC_LITERAL(35, 362, 14), // "setSceneCursor"
QT_MOC_LITERAL(36, 377, 1), // "c"
QT_MOC_LITERAL(37, 379, 18), // "onSelectionChanged"
QT_MOC_LITERAL(38, 398, 18), // "onFocusItemChanged"
QT_MOC_LITERAL(39, 417, 12), // "newFocusItem"
QT_MOC_LITERAL(40, 430, 12), // "oldFocusItem"
QT_MOC_LITERAL(41, 443, 15), // "Qt::FocusReason"
QT_MOC_LITERAL(42, 459, 6), // "reason"
QT_MOC_LITERAL(43, 466, 21), // "onItemEditingFinished"
QT_MOC_LITERAL(44, 488, 9), // "cancelled"
QT_MOC_LITERAL(45, 498, 14), // "onActionDelete"
QT_MOC_LITERAL(46, 513, 17), // "onActionSelectAll"
QT_MOC_LITERAL(47, 531, 17), // "onActionEditLabel"
QT_MOC_LITERAL(48, 549, 4) // "data"

    },
    "CEditorScene\0undoAvailable\0\0redoAvailable\0"
    "sceneChanged\0sceneDoubleClicked\0"
    "QGraphicsSceneMouseEvent*\0mouseEvent\0"
    "QGraphicsItem*\0clickedItem\0infoStatusChanged\0"
    "status\0enableGrid\0on\0enableGridSnap\0"
    "enableItemLabels\0undo\0redo\0selectAll\0"
    "deselectAll\0selectItem\0CItem*\0item\0"
    "exclusive\0selectItems\0QList<CItem*>\0"
    "items\0del\0cut\0copy\0setPastePosition\0"
    "anchor\0pasteAt\0paste\0crop\0setSceneCursor\0"
    "c\0onSelectionChanged\0onFocusItemChanged\0"
    "newFocusItem\0oldFocusItem\0Qt::FocusReason\0"
    "reason\0onItemEditingFinished\0cancelled\0"
    "onActionDelete\0onActionSelectAll\0"
    "onActionEditLabel\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CEditorScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  179,    2, 0x06 /* Public */,
       3,    1,  182,    2, 0x06 /* Public */,
       4,    0,  185,    2, 0x06 /* Public */,
       5,    2,  186,    2, 0x06 /* Public */,
      10,    1,  191,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  194,    2, 0x0a /* Public */,
      12,    0,  197,    2, 0x2a /* Public | MethodCloned */,
      14,    1,  198,    2, 0x0a /* Public */,
      14,    0,  201,    2, 0x2a /* Public | MethodCloned */,
      15,    1,  202,    2, 0x0a /* Public */,
      15,    0,  205,    2, 0x2a /* Public | MethodCloned */,
      16,    0,  206,    2, 0x0a /* Public */,
      17,    0,  207,    2, 0x0a /* Public */,
      18,    0,  208,    2, 0x0a /* Public */,
      19,    0,  209,    2, 0x0a /* Public */,
      20,    2,  210,    2, 0x0a /* Public */,
      20,    1,  215,    2, 0x2a /* Public | MethodCloned */,
      24,    2,  218,    2, 0x0a /* Public */,
      24,    1,  223,    2, 0x2a /* Public | MethodCloned */,
      27,    0,  226,    2, 0x0a /* Public */,
      28,    0,  227,    2, 0x0a /* Public */,
      29,    0,  228,    2, 0x0a /* Public */,
      30,    1,  229,    2, 0x0a /* Public */,
      32,    1,  232,    2, 0x0a /* Public */,
      33,    0,  235,    2, 0x0a /* Public */,
      34,    0,  236,    2, 0x0a /* Public */,
      35,    1,  237,    2, 0x0a /* Public */,
      37,    0,  240,    2, 0x09 /* Protected */,
      38,    3,  241,    2, 0x09 /* Protected */,
      43,    2,  248,    2, 0x09 /* Protected */,
      45,    0,  253,    2, 0x09 /* Protected */,
      46,    0,  254,    2, 0x09 /* Protected */,
      47,    2,  255,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21, QMetaType::Bool,   22,   23,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 25, QMetaType::Bool,   26,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF,   31,
    QMetaType::Void, QMetaType::QPointF,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QCursor,   36,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 41,   39,   40,   42,
    QMetaType::Void, 0x80000000 | 21, QMetaType::Bool,   22,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21, QMetaType::Int,   22,   48,

       0        // eod
};

void CEditorScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CEditorScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->undoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->redoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sceneChanged(); break;
        case 3: _t->sceneDoubleClicked((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QGraphicsItem*(*)>(_a[2]))); break;
        case 4: _t->infoStatusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->enableGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->enableGrid(); break;
        case 7: _t->enableGridSnap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->enableGridSnap(); break;
        case 9: _t->enableItemLabels((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->enableItemLabels(); break;
        case 11: _t->undo(); break;
        case 12: _t->redo(); break;
        case 13: _t->selectAll(); break;
        case 14: _t->deselectAll(); break;
        case 15: _t->selectItem((*reinterpret_cast< CItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: _t->selectItem((*reinterpret_cast< CItem*(*)>(_a[1]))); break;
        case 17: _t->selectItems((*reinterpret_cast< const QList<CItem*>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->selectItems((*reinterpret_cast< const QList<CItem*>(*)>(_a[1]))); break;
        case 19: _t->del(); break;
        case 20: _t->cut(); break;
        case 21: _t->copy(); break;
        case 22: _t->setPastePosition((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 23: _t->pasteAt((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 24: _t->paste(); break;
        case 25: _t->crop(); break;
        case 26: _t->setSceneCursor((*reinterpret_cast< const QCursor(*)>(_a[1]))); break;
        case 27: _t->onSelectionChanged(); break;
        case 28: _t->onFocusItemChanged((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< QGraphicsItem*(*)>(_a[2])),(*reinterpret_cast< Qt::FocusReason(*)>(_a[3]))); break;
        case 29: _t->onItemEditingFinished((*reinterpret_cast< CItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->onActionDelete(); break;
        case 31: _t->onActionSelectAll(); break;
        case 32: _t->onActionEditLabel((*reinterpret_cast< CItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CEditorScene::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CEditorScene::undoAvailable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CEditorScene::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CEditorScene::redoAvailable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CEditorScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CEditorScene::sceneChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CEditorScene::*)(QGraphicsSceneMouseEvent * , QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CEditorScene::sceneDoubleClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CEditorScene::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CEditorScene::infoStatusChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CEditorScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_CEditorScene.data,
    qt_meta_data_CEditorScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CEditorScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CEditorScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CEditorScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int CEditorScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void CEditorScene::undoAvailable(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CEditorScene::redoAvailable(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CEditorScene::sceneChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CEditorScene::sceneDoubleClicked(QGraphicsSceneMouseEvent * _t1, QGraphicsItem * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CEditorScene::infoStatusChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
