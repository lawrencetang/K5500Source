/****************************************************************************
** Meta object code from reading C++ file 'uvviswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../applications/uvviswindow/uvviswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uvviswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UvVisWindow_t {
    QByteArrayData data[8];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UvVisWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UvVisWindow_t qt_meta_stringdata_UvVisWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UvVisWindow"
QT_MOC_LITERAL(1, 12, 14), // "backToMainPage"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "back"
QT_MOC_LITERAL(4, 33, 15), // "showTestingPage"
QT_MOC_LITERAL(5, 49, 15), // "showSettingPage"
QT_MOC_LITERAL(6, 65, 10), // "startBlank"
QT_MOC_LITERAL(7, 76, 12) // "startMeasure"

    },
    "UvVisWindow\0backToMainPage\0\0back\0"
    "showTestingPage\0showSettingPage\0"
    "startBlank\0startMeasure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UvVisWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UvVisWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UvVisWindow *_t = static_cast<UvVisWindow *>(_o);
        switch (_id) {
        case 0: _t->backToMainPage(); break;
        case 1: _t->back(); break;
        case 2: _t->showTestingPage(); break;
        case 3: _t->showSettingPage(); break;
        case 4: _t->startBlank(); break;
        case 5: _t->startMeasure(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UvVisWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UvVisWindow::backToMainPage)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UvVisWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_UvVisWindow.data,
      qt_meta_data_UvVisWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UvVisWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UvVisWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UvVisWindow.stringdata))
        return static_cast<void*>(const_cast< UvVisWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int UvVisWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UvVisWindow::backToMainPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
