/****************************************************************************
** Meta object code from reading C++ file 'gameboard.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gameboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameBoard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      19,   10,   10,   10, 0x05,
      28,   10,   10,   10, 0x05,
      41,   10,   10,   10, 0x05,
      52,   10,   10,   10, 0x05,
      63,   10,   10,   10, 0x05,
      76,   10,   10,   10, 0x05,
      93,   10,   10,   10, 0x05,
     106,   10,   10,   10, 0x05,
     113,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,   10,   10,   10, 0x08,
     135,   10,   10,   10, 0x08,
     146,  144,   10,   10, 0x08,
     171,   10,  166,   10, 0x08,
     189,   10,   10,   10, 0x08,
     201,   10,   10,   10, 0x08,
     213,   10,   10,   10, 0x08,
     222,   10,   10,   10, 0x08,
     230,   10,   10,   10, 0x08,
     242,   10,   10,   10, 0x08,
     253,   10,   10,   10, 0x08,
     262,   10,   10,   10, 0x08,
     275,   10,   10,   10, 0x08,
     301,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameBoard[] = {
    "GameBoard\0\0check()\0redraw()\0winGame(int)\0"
    "loseGame()\0linkLine()\0hideButton()\0"
    "enableContinue()\0enableStop()\0exit()\0"
    "updateStatus()\0stop()\0onGame()\0,\0"
    "addButtons(int,int)\0bool\0updateGameBoard()\0"
    "rearrange()\0giveHints()\0saveAs()\0"
    "files()\0randAward()\0increase()\0record()\0"
    "playRecord()\0changeBackground(QString)\0"
    "changeMusic(int)\0"
};

void GameBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameBoard *_t = static_cast<GameBoard *>(_o);
        switch (_id) {
        case 0: _t->check(); break;
        case 1: _t->redraw(); break;
        case 2: _t->winGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->loseGame(); break;
        case 4: _t->linkLine(); break;
        case 5: _t->hideButton(); break;
        case 6: _t->enableContinue(); break;
        case 7: _t->enableStop(); break;
        case 8: _t->exit(); break;
        case 9: _t->updateStatus(); break;
        case 10: _t->stop(); break;
        case 11: _t->onGame(); break;
        case 12: _t->addButtons((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: { bool _r = _t->updateGameBoard();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: _t->rearrange(); break;
        case 15: _t->giveHints(); break;
        case 16: _t->saveAs(); break;
        case 17: _t->files(); break;
        case 18: _t->randAward(); break;
        case 19: _t->increase(); break;
        case 20: _t->record(); break;
        case 21: _t->playRecord(); break;
        case 22: _t->changeBackground((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->changeMusic((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameBoard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameBoard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameBoard,
      qt_meta_data_GameBoard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameBoard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameBoard))
        return static_cast<void*>(const_cast< GameBoard*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void GameBoard::check()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameBoard::redraw()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GameBoard::winGame(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameBoard::loseGame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GameBoard::linkLine()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void GameBoard::hideButton()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void GameBoard::enableContinue()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void GameBoard::enableStop()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void GameBoard::exit()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void GameBoard::updateStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
