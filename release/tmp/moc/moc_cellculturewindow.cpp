/****************************************************************************
** Meta object code from reading C++ file 'cellculturewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../applications/cellculturewindow/cellculturewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cellculturewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CellCultureWindow_t {
    QByteArrayData data[8];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CellCultureWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CellCultureWindow_t qt_meta_stringdata_CellCultureWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CellCultureWindow"
QT_MOC_LITERAL(1, 18, 14), // "backToMainPage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "back"
QT_MOC_LITERAL(4, 39, 15), // "showTestingPage"
QT_MOC_LITERAL(5, 55, 15), // "showSettingPage"
QT_MOC_LITERAL(6, 71, 10), // "startBlank"
QT_MOC_LITERAL(7, 82, 12) // "startMeasure"

    },
    "CellCultureWindow\0backToMainPage\0\0"
    "back\0showTestingPage\0showSettingPage\0"
    "startBlank\0startMeasure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CellCultureWindow[] = {

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

void CellCultureWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CellCultureWindow *_t = static_cast<CellCultureWindow *>(_o);
        Q_UNUSED(_t)
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
            typedef void (CellCultureWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CellCultureWindow::backToMainPage)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CellCultureWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_CellCultureWindow.data,
      qt_meta_data_CellCultureWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CellCultureWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CellCultureWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CellCultureWindow.stringdata0))
        return static_cast<void*>(const_cast< CellCultureWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int CellCultureWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CellCultureWindow::backToMainPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
