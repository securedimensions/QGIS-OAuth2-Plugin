/****************************************************************************
** Meta object code from reading C++ file 'qgsauthoauth2method.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../oauth2/qgsauthoauth2method.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgsauthoauth2method.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QgsAuthOAuth2Method[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      39,   20,   20,   20, 0x0a,
      57,   20,   20,   20, 0x0a,
      82,   78,   20,   20, 0x0a,
     102,   20,   20,   20, 0x0a,
     119,   20,   20,   20, 0x0a,
     141,  137,   20,   20, 0x0a,
     185,  137,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QgsAuthOAuth2Method[] = {
    "QgsAuthOAuth2Method\0\0onLinkedChanged()\0"
    "onLinkingFailed()\0onLinkingSucceeded()\0"
    "url\0onOpenBrowser(QUrl)\0onCloseBrowser()\0"
    "onReplyFinished()\0err\0"
    "onNetworkError(QNetworkReply::NetworkError)\0"
    "onRefreshFinished(QNetworkReply::NetworkError)\0"
};

void QgsAuthOAuth2Method::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QgsAuthOAuth2Method *_t = static_cast<QgsAuthOAuth2Method *>(_o);
        switch (_id) {
        case 0: _t->onLinkedChanged(); break;
        case 1: _t->onLinkingFailed(); break;
        case 2: _t->onLinkingSucceeded(); break;
        case 3: _t->onOpenBrowser((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 4: _t->onCloseBrowser(); break;
        case 5: _t->onReplyFinished(); break;
        case 6: _t->onNetworkError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 7: _t->onRefreshFinished((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QgsAuthOAuth2Method::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QgsAuthOAuth2Method::staticMetaObject = {
    { &QgsAuthMethod::staticMetaObject, qt_meta_stringdata_QgsAuthOAuth2Method,
      qt_meta_data_QgsAuthOAuth2Method, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QgsAuthOAuth2Method::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QgsAuthOAuth2Method::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QgsAuthOAuth2Method::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QgsAuthOAuth2Method))
        return static_cast<void*>(const_cast< QgsAuthOAuth2Method*>(this));
    return QgsAuthMethod::qt_metacast(_clname);
}

int QgsAuthOAuth2Method::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QgsAuthMethod::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
