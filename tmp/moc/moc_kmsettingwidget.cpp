/****************************************************************************
** Meta object code from reading C++ file 'kmsettingwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../applications/kitmethodwindow/kmsettingwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kmsettingwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KMSettingWidget_t {
    QByteArrayData data[6];
    char stringdata[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KMSettingWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KMSettingWidget_t qt_meta_stringdata_KMSettingWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KMSettingWidget"
QT_MOC_LITERAL(1, 16, 13), // "toTestingPage"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "updateData"
QT_MOC_LITERAL(4, 42, 6), // "record"
QT_MOC_LITERAL(5, 49, 4) // "back"

    },
    "KMSettingWidget\0toTestingPage\0\0"
    "updateData\0record\0back"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KMSettingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void,

       0        // eod
};

void KMSettingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KMSettingWidget *_t = static_cast<KMSettingWidget *>(_o);
        switch (_id) {
        case 0: _t->toTestingPage(); break;
        case 1: _t->updateData((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->back(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KMSettingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMSettingWidget::toTestingPage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject KMSettingWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_KMSettingWidget.data,
      qt_meta_data_KMSettingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KMSettingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KMSettingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KMSettingWidget.stringdata))
        return static_cast<void*>(const_cast< KMSettingWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int KMSettingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void KMSettingWidget::toTestingPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
