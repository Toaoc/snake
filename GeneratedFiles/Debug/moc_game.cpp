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
    QByteArrayData data[7];
    char stringdata0[58];
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
QT_MOC_LITERAL(4, 29, 9), // "snakeTurn"
QT_MOC_LITERAL(5, 39, 9), // "direction"
QT_MOC_LITERAL(6, 49, 8) // "headMove"

    },
    "SnakeHead\0snakeDied\0\0eatFood\0snakeTurn\0"
    "direction\0headMove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SnakeHead[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,
       6,    0,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
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
        case 2: _t->snakeTurn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->headMove(); break;
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
            typedef void (SnakeHead::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnakeHead::snakeTurn)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SnakeHead::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnakeHead::headMove)) {
                *result = 3;
                return;
            }
        }
    }
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
void SnakeHead::snakeTurn(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SnakeHead::headMove()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
struct qt_meta_stringdata_SnakeBody_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SnakeBody_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SnakeBody_t qt_meta_stringdata_SnakeBody = {
    {
QT_MOC_LITERAL(0, 0, 9) // "SnakeBody"

    },
    "SnakeBody"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SnakeBody[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SnakeBody::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SnakeBody::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SnakeBody.data,
      qt_meta_data_SnakeBody,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SnakeBody::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SnakeBody::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SnakeBody.stringdata0))
        return static_cast<void*>(const_cast< SnakeBody*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< SnakeBody*>(this));
    return QObject::qt_metacast(_clname);
}

int SnakeBody::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_GamePlay_t {
    QByteArrayData data[15];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GamePlay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GamePlay_t qt_meta_stringdata_GamePlay = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GamePlay"
QT_MOC_LITERAL(1, 9, 8), // "keepMove"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "direction"
QT_MOC_LITERAL(4, 29, 8), // "gameOver"
QT_MOC_LITERAL(5, 38, 12), // "scoreChanged"
QT_MOC_LITERAL(6, 51, 7), // "setFood"
QT_MOC_LITERAL(7, 59, 8), // "sendOver"
QT_MOC_LITERAL(8, 68, 7), // "setWall"
QT_MOC_LITERAL(9, 76, 11), // "destroyWall"
QT_MOC_LITERAL(10, 88, 12), // "setDirection"
QT_MOC_LITERAL(11, 101, 11), // "m_direction"
QT_MOC_LITERAL(12, 113, 7), // "addBody"
QT_MOC_LITERAL(13, 121, 8), // "bodyMove"
QT_MOC_LITERAL(14, 130, 13) // "screenControl"

    },
    "GamePlay\0keepMove\0\0direction\0gameOver\0"
    "scoreChanged\0setFood\0sendOver\0setWall\0"
    "destroyWall\0setDirection\0m_direction\0"
    "addBody\0bodyMove\0screenControl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GamePlay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x0a /* Public */,
       7,    0,   75,    2, 0x0a /* Public */,
       8,    0,   76,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void GamePlay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GamePlay *_t = static_cast<GamePlay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keepMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->gameOver(); break;
        case 2: _t->scoreChanged(); break;
        case 3: _t->setFood(); break;
        case 4: _t->sendOver(); break;
        case 5: _t->setWall(); break;
        case 6: _t->destroyWall(); break;
        case 7: _t->setDirection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->addBody(); break;
        case 9: _t->bodyMove(); break;
        case 10: _t->screenControl((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GamePlay::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePlay::keepMove)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GamePlay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePlay::gameOver)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GamePlay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePlay::scoreChanged)) {
                *result = 2;
                return;
            }
        }
    }
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GamePlay::keepMove(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GamePlay::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void GamePlay::scoreChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
struct qt_meta_stringdata_gameWidget_t {
    QByteArrayData data[11];
    char stringdata0[103];
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
QT_MOC_LITERAL(9, 84, 9), // "snakeOver"
QT_MOC_LITERAL(10, 94, 8) // "addScore"

    },
    "gameWidget\0keydiretion\0\0direction\0"
    "sonclose\0sonexit\0senddirection\0sendclose\0"
    "sendexit\0snakeOver\0addScore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x0a /* Public */,
       7,    0,   62,    2, 0x0a /* Public */,
       8,    0,   63,    2, 0x0a /* Public */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
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
        case 6: _t->snakeOver(); break;
        case 7: _t->addScore(); break;
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
