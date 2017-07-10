/****************************************************************************
** Meta object code from reading C++ file 'qgsauthoauth2edit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../oauth2/qgsauthoauth2edit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgsauthoauth2edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QgsAuthOAuth2Edit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   19,   18,   18, 0x0a,
      54,   18,   18,   18, 0x0a,
      68,   18,   18,   18, 0x0a,
      82,   18,   18,   18, 0x08,
     101,   18,   18,   18, 0x08,
     125,   18,   18,   18, 0x08,
     148,   18,   18,   18, 0x08,
     174,  169,   18,   18, 0x08,
     195,   18,   18,   18, 0x08,
     215,   18,   18,   18, 0x08,
     235,   18,   18,   18, 0x08,
     256,   18,   18,   18, 0x08,
     280,  169,   18,   18, 0x08,
     310,   18,   18,   18, 0x08,
     325,   18,   18,   18, 0x08,
     343,   18,   18,   18, 0x08,
     379,  361,   18,   18, 0x08,
     427,  416,   18,   18, 0x28,
     459,   18,   18,   18, 0x08,
     488,   18,   18,   18, 0x08,
     513,   18,   18,   18, 0x08,
     541,   18,   18,   18, 0x08,
     565,  562,   18,   18, 0x08,
     607,  598,   18,   18, 0x08,
     668,   18,   18,   18, 0x08,
     704,  697,   18,   18, 0x08,
     752,   18,   18,   18, 0x28,
     785,  774,   18,   18, 0x08,
     812,  169,   18,   18, 0x08,
     838,  833,   18,   18, 0x08,
     871,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QgsAuthOAuth2Edit[] = {
    "QgsAuthOAuth2Edit\0\0configmap\0"
    "loadConfig(QgsStringMap)\0resetConfig()\0"
    "clearConfig()\0setupConnections()\0"
    "configValidityChanged()\0removeTokenCacheFile()\0"
    "populateGrantFlows()\0indx\0"
    "updateGrantFlow(int)\0exportOAuthConfig()\0"
    "importOAuthConfig()\0descriptionChanged()\0"
    "populateAccessMethods()\0"
    "updateConfigAccessMethod(int)\0"
    "addQueryPair()\0removeQueryPair()\0"
    "clearQueryPairs()\0querypairs,append\0"
    "populateQueryPairs(QVariantMap,bool)\0"
    "querypairs\0populateQueryPairs(QVariantMap)\0"
    "queryTableSelectionChanged()\0"
    "updateConfigQueryPairs()\0"
    "updateDefinedConfigsCache()\0"
    "loadDefinedConfigs()\0id\0"
    "setCurrentDefinedConfig(QString)\0"
    "cur,prev\0"
    "currentDefinedItemChanged(QListWidgetItem*,QListWidgetItem*)\0"
    "selectCurrentDefinedConfig()\0config\0"
    "loadFromOAuthConfig(const QgsAuthOAuth2Config*)\0"
    "loadFromOAuthConfig()\0curpersist\0"
    "updateTokenCacheFile(bool)\0"
    "tabIndexChanged(int)\0path\0"
    "definedCustomDirChanged(QString)\0"
    "getDefinedCustomDir()\0"
};

void QgsAuthOAuth2Edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QgsAuthOAuth2Edit *_t = static_cast<QgsAuthOAuth2Edit *>(_o);
        switch (_id) {
        case 0: _t->loadConfig((*reinterpret_cast< const QgsStringMap(*)>(_a[1]))); break;
        case 1: _t->resetConfig(); break;
        case 2: _t->clearConfig(); break;
        case 3: _t->setupConnections(); break;
        case 4: _t->configValidityChanged(); break;
        case 5: _t->removeTokenCacheFile(); break;
        case 6: _t->populateGrantFlows(); break;
        case 7: _t->updateGrantFlow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->exportOAuthConfig(); break;
        case 9: _t->importOAuthConfig(); break;
        case 10: _t->descriptionChanged(); break;
        case 11: _t->populateAccessMethods(); break;
        case 12: _t->updateConfigAccessMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->addQueryPair(); break;
        case 14: _t->removeQueryPair(); break;
        case 15: _t->clearQueryPairs(); break;
        case 16: _t->populateQueryPairs((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 17: _t->populateQueryPairs((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 18: _t->queryTableSelectionChanged(); break;
        case 19: _t->updateConfigQueryPairs(); break;
        case 20: _t->updateDefinedConfigsCache(); break;
        case 21: _t->loadDefinedConfigs(); break;
        case 22: _t->setCurrentDefinedConfig((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->currentDefinedItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 24: _t->selectCurrentDefinedConfig(); break;
        case 25: _t->loadFromOAuthConfig((*reinterpret_cast< const QgsAuthOAuth2Config*(*)>(_a[1]))); break;
        case 26: _t->loadFromOAuthConfig(); break;
        case 27: _t->updateTokenCacheFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->tabIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->definedCustomDirChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->getDefinedCustomDir(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QgsAuthOAuth2Edit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QgsAuthOAuth2Edit::staticMetaObject = {
    { &QgsAuthMethodEdit::staticMetaObject, qt_meta_stringdata_QgsAuthOAuth2Edit,
      qt_meta_data_QgsAuthOAuth2Edit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QgsAuthOAuth2Edit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QgsAuthOAuth2Edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QgsAuthOAuth2Edit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QgsAuthOAuth2Edit))
        return static_cast<void*>(const_cast< QgsAuthOAuth2Edit*>(this));
    return QgsAuthMethodEdit::qt_metacast(_clname);
}

int QgsAuthOAuth2Edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QgsAuthMethodEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
