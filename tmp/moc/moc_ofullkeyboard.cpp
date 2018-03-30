/****************************************************************************
** Meta object code from reading C++ file 'ofullkeyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../oleplugins/ovirtualkeyboard/ofullkeyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ofullkeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OFullKeyboard_t {
    QByteArrayData data[11];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OFullKeyboard_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OFullKeyboard_t qt_meta_stringdata_OFullKeyboard = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OFullKeyboard"
QT_MOC_LITERAL(1, 14, 14), // "onKeyPressedEn"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "onKeyPressedCh"
QT_MOC_LITERAL(4, 45, 15), // "onCapKeyPressed"
QT_MOC_LITERAL(5, 61, 18), // "onSwitchKeyPressed"
QT_MOC_LITERAL(6, 80, 18), // "onSelectKeyPressed"
QT_MOC_LITERAL(7, 99, 8), // "updateHz"
QT_MOC_LITERAL(8, 108, 4), // "text"
QT_MOC_LITERAL(9, 113, 7), // "prePage"
QT_MOC_LITERAL(10, 121, 8) // "nextPage"

    },
    "OFullKeyboard\0onKeyPressedEn\0\0"
    "onKeyPressedCh\0onCapKeyPressed\0"
    "onSwitchKeyPressed\0onSelectKeyPressed\0"
    "updateHz\0text\0prePage\0nextPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OFullKeyboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OFullKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OFullKeyboard *_t = static_cast<OFullKeyboard *>(_o);
        switch (_id) {
        case 0: _t->onKeyPressedEn(); break;
        case 1: _t->onKeyPressedCh(); break;
        case 2: _t->onCapKeyPressed(); break;
        case 3: _t->onSwitchKeyPressed(); break;
        case 4: _t->onSelectKeyPressed(); break;
        case 5: _t->updateHz((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->prePage(); break;
        case 7: _t->nextPage(); break;
        default: ;
        }
    }
}

const QMetaObject OFullKeyboard::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_OFullKeyboard.data,
      qt_meta_data_OFullKeyboard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OFullKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OFullKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OFullKeyboard.stringdata))
        return static_cast<void*>(const_cast< OFullKeyboard*>(this));
    return QFrame::qt_metacast(_clname);
}

int OFullKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
