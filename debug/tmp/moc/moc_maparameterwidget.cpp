/****************************************************************************
** Meta object code from reading C++ file 'maparameterwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../applications/microarraywindow/maparameterwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maparameterwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MAParameterWidget_t {
    QByteArrayData data[9];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MAParameterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MAParameterWidget_t qt_meta_stringdata_MAParameterWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MAParameterWidget"
QT_MOC_LITERAL(1, 18, 7), // "restore"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "changeMatter"
QT_MOC_LITERAL(4, 40, 6), // "matter"
QT_MOC_LITERAL(5, 47, 16), // "changeCofficient"
QT_MOC_LITERAL(6, 64, 5), // "index"
QT_MOC_LITERAL(7, 70, 21), // "changeDetectionMothed"
QT_MOC_LITERAL(8, 92, 6) // "method"

    },
    "MAParameterWidget\0restore\0\0changeMatter\0"
    "matter\0changeCofficient\0index\0"
    "changeDetectionMothed\0method"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MAParameterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    1,   38,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void MAParameterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MAParameterWidget *_t = static_cast<MAParameterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->restore(); break;
        case 1: _t->changeMatter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->changeCofficient((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeDetectionMothed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MAParameterWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_MAParameterWidget.data,
      qt_meta_data_MAParameterWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MAParameterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MAParameterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MAParameterWidget.stringdata0))
        return static_cast<void*>(const_cast< MAParameterWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int MAParameterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
