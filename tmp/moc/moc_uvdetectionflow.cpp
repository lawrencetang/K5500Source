/****************************************************************************
** Meta object code from reading C++ file 'uvdetectionflow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../applications/uvviswindow/background/uvdetectionflow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#include <QStringList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uvdetectionflow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UVDetectionFlow_t {
    QByteArrayData data[12];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UVDetectionFlow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UVDetectionFlow_t qt_meta_stringdata_UVDetectionFlow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "UVDetectionFlow"
QT_MOC_LITERAL(1, 16, 11), // "toDrawCurve"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "name"
QT_MOC_LITERAL(4, 34, 15), // "QVector<double>"
QT_MOC_LITERAL(5, 50, 1), // "x"
QT_MOC_LITERAL(6, 52, 1), // "y"
QT_MOC_LITERAL(7, 54, 12), // "toSaveResult"
QT_MOC_LITERAL(8, 67, 8), // "fileName"
QT_MOC_LITERAL(9, 76, 6), // "result"
QT_MOC_LITERAL(10, 83, 12), // "toSaveRecord"
QT_MOC_LITERAL(11, 96, 6) // "record"

    },
    "UVDetectionFlow\0toDrawCurve\0\0name\0"
    "QVector<double>\0x\0y\0toSaveResult\0"
    "fileName\0result\0toSaveRecord\0record"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UVDetectionFlow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       7,    2,   36,    2, 0x06 /* Public */,
      10,    1,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    8,    9,
    QMetaType::Void, QMetaType::QStringList,   11,

       0        // eod
};

void UVDetectionFlow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UVDetectionFlow *_t = static_cast<UVDetectionFlow *>(_o);
        switch (_id) {
        case 0: _t->toDrawCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 1: _t->toSaveResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 2: _t->toSaveRecord((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UVDetectionFlow::*_t)(QString , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UVDetectionFlow::toDrawCurve)) {
                *result = 0;
            }
        }
        {
            typedef void (UVDetectionFlow::*_t)(QString , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UVDetectionFlow::toSaveResult)) {
                *result = 1;
            }
        }
        {
            typedef void (UVDetectionFlow::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UVDetectionFlow::toSaveRecord)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject UVDetectionFlow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UVDetectionFlow.data,
      qt_meta_data_UVDetectionFlow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UVDetectionFlow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UVDetectionFlow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UVDetectionFlow.stringdata))
        return static_cast<void*>(const_cast< UVDetectionFlow*>(this));
    return QObject::qt_metacast(_clname);
}

int UVDetectionFlow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void UVDetectionFlow::toDrawCurve(QString _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UVDetectionFlow::toSaveResult(QString _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UVDetectionFlow::toSaveRecord(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
