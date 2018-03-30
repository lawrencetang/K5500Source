/****************************************************************************
** Meta object code from reading C++ file 'ultramicrospectrophotometer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ultramicrospectrophotometer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ultramicrospectrophotometer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UltramicroSpectrophotometer_t {
    QByteArrayData data[8];
    char stringdata[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UltramicroSpectrophotometer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UltramicroSpectrophotometer_t qt_meta_stringdata_UltramicroSpectrophotometer = {
    {
QT_MOC_LITERAL(0, 0, 27), // "UltramicroSpectrophotometer"
QT_MOC_LITERAL(1, 28, 17), // "receiveAppMessage"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 8), // "messages"
QT_MOC_LITERAL(4, 56, 10), // "changePage"
QT_MOC_LITERAL(5, 67, 10), // "toMainPage"
QT_MOC_LITERAL(6, 78, 12), // "selfChecking"
QT_MOC_LITERAL(7, 91, 12) // "reconnecting"

    },
    "UltramicroSpectrophotometer\0"
    "receiveAppMessage\0\0messages\0changePage\0"
    "toMainPage\0selfChecking\0reconnecting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UltramicroSpectrophotometer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UltramicroSpectrophotometer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UltramicroSpectrophotometer *_t = static_cast<UltramicroSpectrophotometer *>(_o);
        switch (_id) {
        case 0: _t->receiveAppMessage((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->changePage(); break;
        case 2: _t->toMainPage(); break;
        case 3: _t->selfChecking(); break;
        case 4: _t->reconnecting(); break;
        default: ;
        }
    }
}

const QMetaObject UltramicroSpectrophotometer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UltramicroSpectrophotometer.data,
      qt_meta_data_UltramicroSpectrophotometer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UltramicroSpectrophotometer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UltramicroSpectrophotometer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UltramicroSpectrophotometer.stringdata))
        return static_cast<void*>(const_cast< UltramicroSpectrophotometer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UltramicroSpectrophotometer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
