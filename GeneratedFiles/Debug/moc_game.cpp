/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SnakeHead_t {
    QByteArrayData data[5];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SnakeHead_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SnakeHead_t qt_meta_stringdata_SnakeHead = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SnakeHead"
QT_MOC_LITERAL(1, 10, 9), // "snakeDied"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "eatFood"
QT_MOC_LITERAL(4, 29, 9) // "snakeTurn"

    },
    "SnakeHead\0snakeDied\0\0eatFood\0snakeTurn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SnakeHead[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SnakeHead::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SnakeHead *_t = static_cast<SnakeHead *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->snakeDied(); break;
        case 1: _t->eatFood(); break;
        case 2: _t->snakeTurn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SnakeHead::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnakeHead::snakeDied)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SnakeHead::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnakeHead::eatFood)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SnakeHead::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnakeHead::snakeTurn)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SnakeHead::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SnakeHead.data,
      qt_meta_data_SnakeHead,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SnakeHead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SnakeHead::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SnakeHead.stringdata0))
        return static_cast<void*>(const_cast< SnakeHead*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< SnakeHead*>(this));
    return QObject::qt_metacast(_clname);
}

int SnakeHead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void SnakeHead::snakeDied()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SnakeHead::eatFood()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SnakeHead::snakeTurn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
struct qt_meta_stringdata_GamePlay_t {
    QByteArrayData data[7];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GamePlay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GamePlay_t qt_meta_stringdata_GamePlay = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GamePlay"
QT_MOC_LITERAL(1, 9, 8), // "gameOver"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "setFood"
QT_MOC_LITERAL(4, 27, 8), // "sendOver"
QT_MOC_LITERAL(5, 36, 7), // "setWall"
QT_MOC_LITERAL(6, 44, 11) // "destroyWall"

    },
    "GamePlay\0gameOver\0\0setFood\0sendOver\0"
    "setWall\0destroyWall"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GamePlay[] = {

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
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GamePlay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GamePlay *_t = static_cast<GamePlay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameOver(); break;
        case 1: _t->setFood(); break;
        case 2: _t->sendOver(); break;
        case 3: _t->setWall(); break;
        case 4: _t->destroyWall(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GamePlay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePlay::gameOver)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GamePlay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GamePlay.data,
      qt_meta_data_GamePlay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GamePlay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GamePlay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GamePlay.stringdata0))
        return static_cast<void*>(const_cast< GamePlay*>(this));
    return QWidget::qt_metacast(_clname);
}

int GamePlay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void GamePlay::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_gameWidget_t {
    QByteArrayData data[10];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameWidget_t qt_meta_stringdata_gameWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "gameWidget"
QT_MOC_LITERAL(1, 11, 11), // "keydiretion"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "direction"
QT_MOC_LITERAL(4, 34, 8), // "sonclose"
QT_MOC_LITERAL(5, 43, 7), // "sonexit"
QT_MOC_LITERAL(6, 51, 13), // "senddirection"
QT_MOC_LITERAL(7, 65, 9), // "sendclose"
QT_MOC_LITERAL(8, 75, 8), // "sendexit"
QT_MOC_LITERAL(9, 84, 11) // "gameOverBox"

    },
    "gameWidget\0keydiretion\0\0direction\0"
    "sonclose\0sonexit\0senddirection\0sendclose\0"
    "sendexit\0gameOverBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   54,    2, 0x0a /* Public */,
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameWidget *_t = static_cast<gameWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keydiretion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sonclose(); break;
        case 2: _t->sonexit(); break;
        case 3: _t->senddirection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sendclose(); break;
        case 5: _t->sendexit(); break;
        case 6: _t->gameOverBox(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gameWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gameWidget::keydiretion)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (gameWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gameWidget::sonclose)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (gameWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gameWidget::sonexit)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject gameWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameWidget.data,
      qt_meta_data_gameWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gameWidget.stringdata0))
        return static_cast<void*>(const_cast< gameWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int gameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void gameWidget::keydiretion(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gameWidget::sonclose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void gameWidget::sonexit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
