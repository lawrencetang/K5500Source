/****************************************************************************
** Meta object code from reading C++ file 'devicecheckwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../applications/devicecheckwindow/devicecheckwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicecheckwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DeviceCheckWindow_t {
    QByteArrayData data[14];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceCheckWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceCheckWindow_t qt_meta_stringdata_DeviceCheckWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DeviceCheckWindow"
QT_MOC_LITERAL(1, 18, 14), // "backToMainPage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "toDrawCurve"
QT_MOC_LITERAL(4, 46, 5), // "title"
QT_MOC_LITERAL(5, 52, 15), // "QVector<double>"
QT_MOC_LITERAL(6, 68, 1), // "x"
QT_MOC_LITERAL(7, 70, 1), // "y"
QT_MOC_LITERAL(8, 72, 11), // "clearCurves"
QT_MOC_LITERAL(9, 84, 11), // "excuteCheck"
QT_MOC_LITERAL(10, 96, 12), // "changeMethod"
QT_MOC_LITERAL(11, 109, 6), // "method"
QT_MOC_LITERAL(12, 116, 13), // "changeOptical"
QT_MOC_LITERAL(13, 130, 7) // "optical"

    },
    "DeviceCheckWindow\0backToMainPage\0\0"
    "toDrawCurve\0title\0QVector<double>\0x\0"
    "y\0clearCurves\0excuteCheck\0changeMethod\0"
    "method\0changeOptical\0optical"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceCheckWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    3,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,
      10,    1,   54,    2, 0x08 /* Private */,
      12,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void DeviceCheckWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeviceCheckWindow *_t = static_cast<DeviceCheckWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backToMainPage(); break;
        case 1: _t->toDrawCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 2: _t->clearCurves(); break;
        case 3: _t->excuteCheck(); break;
        case 4: _t->changeMethod((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->changeOptical((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (DeviceCheckWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DeviceCheckWindow::backToMainPage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DeviceCheckWindow::*_t)(QString , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DeviceCheckWindow::toDrawCurve)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DeviceCheckWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_DeviceCheckWindow.data,
      qt_meta_data_DeviceCheckWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DeviceCheckWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceCheckWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceCheckWindow.stringdata0))
        return static_cast<void*>(const_cast< DeviceCheckWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int DeviceCheckWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void DeviceCheckWindow::backToMainPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DeviceCheckWindow::toDrawCurve(QString _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
