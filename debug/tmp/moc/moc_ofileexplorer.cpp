/****************************************************************************
** Meta object code from reading C++ file 'ofileexplorer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../oleplugins/ofileexplorer/ofileexplorer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ofileexplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OFileExplorer_t {
    QByteArrayData data[9];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OFileExplorer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OFileExplorer_t qt_meta_stringdata_OFileExplorer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OFileExplorer"
QT_MOC_LITERAL(1, 14, 13), // "doubleClicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "fileName"
QT_MOC_LITERAL(4, 38, 10), // "toMainView"
QT_MOC_LITERAL(5, 49, 10), // "toListView"
QT_MOC_LITERAL(6, 60, 10), // "toEditView"
QT_MOC_LITERAL(7, 71, 15), // "onDoubleClicked"
QT_MOC_LITERAL(8, 87, 5) // "index"

    },
    "OFileExplorer\0doubleClicked\0\0fileName\0"
    "toMainView\0toListView\0toEditView\0"
    "onDoubleClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OFileExplorer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void OFileExplorer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OFileExplorer *_t = static_cast<OFileExplorer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->toMainView(); break;
        case 2: _t->toListView(); break;
        case 3: _t->toEditView(); break;
        case 4: _t->onDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OFileExplorer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OFileExplorer::doubleClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject OFileExplorer::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_OFileExplorer.data,
      qt_meta_data_OFileExplorer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OFileExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OFileExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OFileExplorer.stringdata0))
        return static_cast<void*>(const_cast< OFileExplorer*>(this));
    return QFrame::qt_metacast(_clname);
}

int OFileExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void OFileExplorer::doubleClicked(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
