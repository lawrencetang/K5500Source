/****************************************************************************
** Meta object code from reading C++ file 'ousb.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../oledrivers/ousb/ousb.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ousb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OUsb_t {
    QByteArrayData data[18];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OUsb_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OUsb_t qt_meta_stringdata_OUsb = {
    {
QT_MOC_LITERAL(0, 0, 4), // "OUsb"
QT_MOC_LITERAL(1, 5, 7), // "openUsb"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 3), // "vId"
QT_MOC_LITERAL(4, 18, 3), // "pId"
QT_MOC_LITERAL(5, 22, 8), // "closeUsb"
QT_MOC_LITERAL(6, 31, 8), // "writeUsb"
QT_MOC_LITERAL(7, 40, 2), // "ep"
QT_MOC_LITERAL(8, 43, 5), // "char*"
QT_MOC_LITERAL(9, 49, 7), // "content"
QT_MOC_LITERAL(10, 57, 3), // "len"
QT_MOC_LITERAL(11, 61, 7), // "readUsb"
QT_MOC_LITERAL(12, 69, 7), // "recvLen"
QT_MOC_LITERAL(13, 77, 12), // "writeReadUsb"
QT_MOC_LITERAL(14, 90, 3), // "wEp"
QT_MOC_LITERAL(15, 94, 5), // "wChar"
QT_MOC_LITERAL(16, 100, 3), // "rEp"
QT_MOC_LITERAL(17, 104, 7) // "listUsb"

    },
    "OUsb\0openUsb\0\0vId\0pId\0closeUsb\0writeUsb\0"
    "ep\0char*\0content\0len\0readUsb\0recvLen\0"
    "writeReadUsb\0wEp\0wChar\0rEp\0listUsb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OUsb[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x0a /* Public */,
       6,    3,   50,    2, 0x0a /* Public */,
      11,    2,   57,    2, 0x0a /* Public */,
      13,    5,   62,    2, 0x0a /* Public */,
      17,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 8, QMetaType::Int,    7,    9,   10,
    QMetaType::QByteArray, QMetaType::Int, QMetaType::Int,    7,   12,
    QMetaType::QByteArray, QMetaType::Int, 0x80000000 | 8, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   10,   16,   12,
    QMetaType::Void,

       0        // eod
};

void OUsb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OUsb *_t = static_cast<OUsb *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->openUsb((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->closeUsb(); break;
        case 2: { bool _r = _t->writeUsb((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { QByteArray _r = _t->readUsb((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 4: { QByteArray _r = _t->writeReadUsb((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 5: _t->listUsb(); break;
        default: ;
        }
    }
}

const QMetaObject OUsb::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OUsb.data,
      qt_meta_data_OUsb,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OUsb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OUsb::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OUsb.stringdata))
        return static_cast<void*>(const_cast< OUsb*>(this));
    return QObject::qt_metacast(_clname);
}

int OUsb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
