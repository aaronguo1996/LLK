/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      23,   11,   11,   11, 0x05,
      32,   11,   11,   11, 0x05,
      39,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      80,   11,   11,   11, 0x08,
      89,   11,   11,   11, 0x08,
      97,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     121,   11,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     168,   11,   11,   11, 0x08,
     182,   11,   11,   11, 0x08,
     193,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0callHome()\0finish()\0save()\0"
    "loading()\0settings()\0m_easy()\0m_medium()\0"
    "m_hard()\0about()\0newGame()\0newNextGame()\0"
    "showHome()\0showWinWindow(int)\0"
    "showLoseWindow()\0setContinue()\0"
    "saveMode()\0showRank()\0loadScores()\0"
    "checkReasonable()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->callHome(); break;
        case 1: _t->finish(); break;
        case 2: _t->save(); break;
        case 3: _t->loading(); break;
        case 4: _t->settings(); break;
        case 5: _t->m_easy(); break;
        case 6: _t->m_medium(); break;
        case 7: _t->m_hard(); break;
        case 8: _t->about(); break;
        case 9: _t->newGame(); break;
        case 10: _t->newNextGame(); break;
        case 11: _t->showHome(); break;
        case 12: _t->showWinWindow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->showLoseWindow(); break;
        case 14: _t->setContinue(); break;
        case 15: _t->saveMode(); break;
        case 16: _t->showRank(); break;
        case 17: _t->loadScores(); break;
        case 18: _t->checkReasonable(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::callHome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::save()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::loading()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
