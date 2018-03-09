/****************************************************************************
** Meta object code from reading C++ file 'myclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MovieQt_t {
    QByteArrayData data[19];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MovieQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MovieQt_t qt_meta_stringdata_MovieQt = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MovieQt"
QT_MOC_LITERAL(1, 8, 15), // "listItemChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "listItemChanged2"
QT_MOC_LITERAL(4, 42, 11), // "addNewMovie"
QT_MOC_LITERAL(5, 54, 11), // "deleteMovie"
QT_MOC_LITERAL(6, 66, 11), // "updateMovie"
QT_MOC_LITERAL(7, 78, 10), // "clearMovie"
QT_MOC_LITERAL(8, 89, 24), // "deleteMovieFromWatchlist"
QT_MOC_LITERAL(9, 114, 10), // "SortVector"
QT_MOC_LITERAL(10, 125, 6), // "Normal"
QT_MOC_LITERAL(11, 132, 4), // "Undo"
QT_MOC_LITERAL(12, 137, 15), // "filterRepoMovie"
QT_MOC_LITERAL(13, 153, 4), // "Play"
QT_MOC_LITERAL(14, 158, 4), // "Next"
QT_MOC_LITERAL(15, 163, 8), // "htmlfile"
QT_MOC_LITERAL(16, 172, 8), // "openFile"
QT_MOC_LITERAL(17, 181, 21), // "moveMoviesToWatchlist"
QT_MOC_LITERAL(18, 203, 13) // "moveAllMovies"

    },
    "MovieQt\0listItemChanged\0\0listItemChanged2\0"
    "addNewMovie\0deleteMovie\0updateMovie\0"
    "clearMovie\0deleteMovieFromWatchlist\0"
    "SortVector\0Normal\0Undo\0filterRepoMovie\0"
    "Play\0Next\0htmlfile\0openFile\0"
    "moveMoviesToWatchlist\0moveAllMovies"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MovieQt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MovieQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MovieQt *_t = static_cast<MovieQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listItemChanged(); break;
        case 1: _t->listItemChanged2(); break;
        case 2: _t->addNewMovie(); break;
        case 3: _t->deleteMovie(); break;
        case 4: _t->updateMovie(); break;
        case 5: _t->clearMovie(); break;
        case 6: _t->deleteMovieFromWatchlist(); break;
        case 7: _t->SortVector(); break;
        case 8: _t->Normal(); break;
        case 9: _t->Undo(); break;
        case 10: _t->filterRepoMovie(); break;
        case 11: _t->Play(); break;
        case 12: _t->Next(); break;
        case 13: _t->htmlfile(); break;
        case 14: _t->openFile(); break;
        case 15: _t->moveMoviesToWatchlist(); break;
        case 16: _t->moveAllMovies(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MovieQt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MovieQt.data,
      qt_meta_data_MovieQt,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MovieQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MovieQt::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MovieQt.stringdata0))
        return static_cast<void*>(const_cast< MovieQt*>(this));
    return QWidget::qt_metacast(_clname);
}

int MovieQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
