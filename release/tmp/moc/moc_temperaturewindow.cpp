/****************************************************************************
** Meta object code from reading C++ file 'temperaturewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../applications/temperaturewindow/temperaturewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'temperaturewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TemperatureWindow_t {
    QByteArrayData data[6];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TemperatureWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TemperatureWindow_t qt_meta_stringdata_TemperatureWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TemperatureWindow"
QT_MOC_LITERAL(1, 18, 14), // "backToMainPage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "onRunBtnClicked"
QT_MOC_LITERAL(4, 50, 16), // "onBackBtnClicked"
QT_MOC_LITERAL(5, 67, 15) // "showTemperature"

    },
    "TemperatureWindow\0backToMainPage\0\0"
    "onRunBtnClicked\0onBackBtnClicked\0"
    "showTemperature"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TemperatureWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TemperatureWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TemperatureWindow *_t = static_cast<TemperatureWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backToMainPage(); break;
        case 1: _t->onRunBtnClicked(); break;
        case 2: _t->onBackBtnClicked(); break;
        case 3: _t->showTemperature(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TemperatureWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TemperatureWindow::backToMainPage)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TemperatureWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_TemperatureWindow.data,
      qt_meta_data_TemperatureWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TemperatureWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TemperatureWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TemperatureWindow.stringdata0))
        return static_cast<void*>(const_cast< TemperatureWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int TemperatureWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void TemperatureWindow::backToMainPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
