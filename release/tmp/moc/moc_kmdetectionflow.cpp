/****************************************************************************
** Meta object code from reading C++ file 'kmdetectionflow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../applications/kitmethodwindow/background/kmdetectionflow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kmdetectionflow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KMDetectionFlow_t {
    QByteArrayData data[9];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KMDetectionFlow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KMDetectionFlow_t qt_meta_stringdata_KMDetectionFlow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KMDetectionFlow"
QT_MOC_LITERAL(1, 16, 11), // "toDrawCurve"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "name"
QT_MOC_LITERAL(4, 34, 15), // "QVector<double>"
QT_MOC_LITERAL(5, 50, 1), // "x"
QT_MOC_LITERAL(6, 52, 1), // "y"
QT_MOC_LITERAL(7, 54, 12), // "toShowResult"
QT_MOC_LITERAL(8, 67, 1) // "c"

    },
    "KMDetectionFlow\0toDrawCurve\0\0name\0"
    "QVector<double>\0x\0y\0toShowResult\0c"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KMDetectionFlow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,
       7,    1,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Void, QMetaType::Double,    8,

       0        // eod
};

void KMDetectionFlow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KMDetectionFlow *_t = static_cast<KMDetectionFlow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toDrawCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 1: _t->toShowResult((*reinterpret_cast< double(*)>(_a[1]))); break;
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
            typedef void (KMDetectionFlow::*_t)(QString , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMDetectionFlow::toDrawCurve)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KMDetectionFlow::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMDetectionFlow::toShowResult)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject KMDetectionFlow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KMDetectionFlow.data,
      qt_meta_data_KMDetectionFlow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KMDetectionFlow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KMDetectionFlow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KMDetectionFlow.stringdata0))
        return static_cast<void*>(const_cast< KMDetectionFlow*>(this));
    return QObject::qt_metacast(_clname);
}

int KMDetectionFlow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void KMDetectionFlow::toDrawCurve(QString _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KMDetectionFlow::toShowResult(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
