/****************************************************************************
** Meta object code from reading C++ file 'orecordtablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../oleplugins/orecordtablewidget/orecordtablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orecordtablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ORecordTableWidget_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ORecordTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ORecordTableWidget_t qt_meta_stringdata_ORecordTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ORecordTableWidget"
QT_MOC_LITERAL(1, 19, 13), // "doubleClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "showItemDetail"
QT_MOC_LITERAL(4, 49, 8), // "fileName"
QT_MOC_LITERAL(5, 58, 10), // "toMainView"
QT_MOC_LITERAL(6, 69, 12), // "toOptionView"
QT_MOC_LITERAL(7, 82, 19), // "onItemDoubleClicked"
QT_MOC_LITERAL(8, 102, 5) // "index"

    },
    "ORecordTableWidget\0doubleClicked\0\0"
    "showItemDetail\0fileName\0toMainView\0"
    "toOptionView\0onItemDoubleClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ORecordTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void ORecordTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ORecordTableWidget *_t = static_cast<ORecordTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClicked(); break;
        case 1: _t->showItemDetail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->toMainView(); break;
        case 3: _t->toOptionView(); break;
        case 4: _t->onItemDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ORecordTableWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ORecordTableWidget::doubleClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ORecordTableWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ORecordTableWidget::showItemDetail)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ORecordTableWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ORecordTableWidget.data,
      qt_meta_data_ORecordTableWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ORecordTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ORecordTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ORecordTableWidget.stringdata0))
        return static_cast<void*>(const_cast< ORecordTableWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int ORecordTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ORecordTableWidget::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ORecordTableWidget::showItemDetail(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
