/****************************************************************************
** Meta object code from reading C++ file 'madyewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../applications/microarraywindow/madyewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'madyewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MADyeWidget_t {
    QByteArrayData data[8];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MADyeWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MADyeWidget_t qt_meta_stringdata_MADyeWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MADyeWidget"
QT_MOC_LITERAL(1, 12, 14), // "headerDisabled"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "ok"
QT_MOC_LITERAL(4, 31, 11), // "showAddPage"
QT_MOC_LITERAL(5, 43, 12), // "showListPage"
QT_MOC_LITERAL(6, 56, 14), // "showRemovePage"
QT_MOC_LITERAL(7, 71, 8) // "checkAll"

    },
    "MADyeWidget\0headerDisabled\0\0ok\0"
    "showAddPage\0showListPage\0showRemovePage\0"
    "checkAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MADyeWidget[] = {

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
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void MADyeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MADyeWidget *_t = static_cast<MADyeWidget *>(_o);
        switch (_id) {
        case 0: _t->headerDisabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->showAddPage(); break;
        case 2: _t->showListPage(); break;
        case 3: _t->showRemovePage(); break;
        case 4: _t->checkAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MADyeWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MADyeWidget::headerDisabled)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MADyeWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_MADyeWidget.data,
      qt_meta_data_MADyeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MADyeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MADyeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MADyeWidget.stringdata))
        return static_cast<void*>(const_cast< MADyeWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int MADyeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MADyeWidget::headerDisabled(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
