/****************************************************************************
** Meta object code from reading C++ file 'setup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../setup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_setupWidget_t {
    QByteArrayData data[8];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setupWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setupWidget_t qt_meta_stringdata_setupWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "setupWidget"
QT_MOC_LITERAL(1, 12, 8), // "sonclose"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "stopMusic"
QT_MOC_LITERAL(4, 32, 16), // "changeDifficulty"
QT_MOC_LITERAL(5, 49, 9), // "sendclose"
QT_MOC_LITERAL(6, 59, 8), // "sendstop"
QT_MOC_LITERAL(7, 68, 20) // "sendDifficultyChange"

    },
    "setupWidget\0sonclose\0\0stopMusic\0"
    "changeDifficulty\0sendclose\0sendstop\0"
    "sendDifficultyChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setupWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       4,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   51,    2, 0x0a /* Public */,
       6,    1,   52,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void setupWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        setupWidget *_t = static_cast<setupWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sonclose(); break;
        case 1: _t->stopMusic((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->changeDifficulty((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendclose(); break;
        case 4: _t->sendstop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->sendDifficultyChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (setupWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setupWidget::sonclose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (setupWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setupWidget::stopMusic)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (setupWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setupWidget::changeDifficulty)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject setupWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_setupWidget.data,
      qt_meta_data_setupWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *setupWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setupWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_setupWidget.stringdata0))
        return static_cast<void*>(const_cast< setupWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int setupWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void setupWidget::sonclose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void setupWidget::stopMusic(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void setupWidget::changeDifficulty(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
