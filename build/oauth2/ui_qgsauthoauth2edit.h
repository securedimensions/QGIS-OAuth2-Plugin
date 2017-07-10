/********************************************************************************
** Form generated from reading UI file 'qgsauthoauth2edit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSAUTHOAUTH2EDIT_H
#define UI_QGSAUTHOAUTH2EDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qgscollapsiblegroupbox.h"
#include "qgspasswordlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAuthOAuth2Edit
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameNotify;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QTabWidget *tabConfigs;
    QWidget *tabCustom;
    QVBoxLayout *verticalLayout_3;
    QFrame *horizontalFrame_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblGrantFlow;
    QComboBox *cmbbxGrantFlow;
    QToolButton *btnExport;
    QToolButton *btnImport;
    QScrollArea *scrollAreaConfigure;
    QWidget *scrollAreaWidgetContentsCustom;
    QGridLayout *gridLayout;
    QLabel *lblScope;
    QLineEdit *leState;
    QLabel *lblRequestTimeout;
    QLabel *lblRedirectUrl;
    QSpinBox *spnbxRequestTimeout;
    QLabel *lblDescription;
    QLineEdit *leRefreshTokenUrl;
    QLabel *lblApiKey;
    QLineEdit *leRequestUrl;
    QFrame *line;
    QLabel *lblRequestUrl;
    QLineEdit *leScope;
    QLabel *lblAccessMethod;
    QLabel *lblUsername;
    QLineEdit *leApiKey;
    QLabel *label;
    QLabel *lblPassword;
    QComboBox *cmbbxAccessMethod;
    QPlainTextEdit *pteDescription;
    QLineEdit *leTokenUrl;
    QgsPasswordLineEdit *leClientSecret;
    QCheckBox *chkbxTokenPersist;
    QLabel *lblTokenUrl;
    QLabel *lblClientSecret;
    QgsPasswordLineEdit *lePassword;
    QSpacerItem *verticalSpacer;
    QLabel *lblClientId;
    QLineEdit *leClientId;
    QLabel *lblState;
    QLabel *lblTokenPersist;
    QLabel *lblRefreshTokenUrl;
    QLineEdit *leUsername;
    QFrame *frameRedirectUrl;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblRedirectIP;
    QSpinBox *spnbxRedirectPort;
    QLabel *lblRedirectUrlSep;
    QLineEdit *leRedirectUrl;
    QWidget *tabDefined;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QListWidget *lstwdgDefinedConfigs;
    QPlainTextEdit *pteDefinedDesc;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leDefinedDirPath;
    QToolButton *btnGetDefinedDirPath;
    QgsCollapsibleGroupBoxBasic *grpbxAdvanced;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollAreaAdvanced;
    QWidget *scrollAreaWidgetContentsAdvanced;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tblwdgQueryPairs;
    QVBoxLayout *verticalLayout_6;
    QToolButton *btnAddQueryPair;
    QToolButton *btnRemoveQueryPair;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QWidget *QgsAuthOAuth2Edit)
    {
        if (QgsAuthOAuth2Edit->objectName().isEmpty())
            QgsAuthOAuth2Edit->setObjectName(QString::fromUtf8("QgsAuthOAuth2Edit"));
        QgsAuthOAuth2Edit->setEnabled(true);
        QgsAuthOAuth2Edit->resize(431, 676);
        verticalLayout = new QVBoxLayout(QgsAuthOAuth2Edit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        frameNotify = new QFrame(QgsAuthOAuth2Edit);
        frameNotify->setObjectName(QString::fromUtf8("frameNotify"));
        frameNotify->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameNotify->sizePolicy().hasHeightForWidth());
        frameNotify->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(frameNotify);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(frameNotify);

        splitter = new QSplitter(QgsAuthOAuth2Edit);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(4);
        splitter->setChildrenCollapsible(false);
        tabConfigs = new QTabWidget(splitter);
        tabConfigs->setObjectName(QString::fromUtf8("tabConfigs"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(tabConfigs->sizePolicy().hasHeightForWidth());
        tabConfigs->setSizePolicy(sizePolicy1);
        tabCustom = new QWidget();
        tabCustom->setObjectName(QString::fromUtf8("tabCustom"));
        verticalLayout_3 = new QVBoxLayout(tabCustom);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 3, 0, 0);
        horizontalFrame_2 = new QFrame(tabCustom);
        horizontalFrame_2->setObjectName(QString::fromUtf8("horizontalFrame_2"));
        sizePolicy.setHeightForWidth(horizontalFrame_2->sizePolicy().hasHeightForWidth());
        horizontalFrame_2->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(horizontalFrame_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(3, -1, 3, -1);
        lblGrantFlow = new QLabel(horizontalFrame_2);
        lblGrantFlow->setObjectName(QString::fromUtf8("lblGrantFlow"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblGrantFlow->sizePolicy().hasHeightForWidth());
        lblGrantFlow->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(lblGrantFlow);

        cmbbxGrantFlow = new QComboBox(horizontalFrame_2);
        cmbbxGrantFlow->setObjectName(QString::fromUtf8("cmbbxGrantFlow"));

        horizontalLayout_3->addWidget(cmbbxGrantFlow);

        btnExport = new QToolButton(horizontalFrame_2);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/oauth2method/oauth2_resources/export.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnExport->setIcon(icon);
        btnExport->setIconSize(QSize(16, 16));

        horizontalLayout_3->addWidget(btnExport);

        btnImport = new QToolButton(horizontalFrame_2);
        btnImport->setObjectName(QString::fromUtf8("btnImport"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/oauth2method/oauth2_resources/import.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnImport->setIcon(icon1);

        horizontalLayout_3->addWidget(btnImport);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 2, 2, 1);


        verticalLayout_3->addWidget(horizontalFrame_2);

        scrollAreaConfigure = new QScrollArea(tabCustom);
        scrollAreaConfigure->setObjectName(QString::fromUtf8("scrollAreaConfigure"));
        scrollAreaConfigure->setFrameShape(QFrame::NoFrame);
        scrollAreaConfigure->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaConfigure->setWidgetResizable(true);
        scrollAreaWidgetContentsCustom = new QWidget();
        scrollAreaWidgetContentsCustom->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsCustom"));
        scrollAreaWidgetContentsCustom->setGeometry(QRect(0, 0, 398, 469));
        gridLayout = new QGridLayout(scrollAreaWidgetContentsCustom);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        lblScope = new QLabel(scrollAreaWidgetContentsCustom);
        lblScope->setObjectName(QString::fromUtf8("lblScope"));

        gridLayout->addWidget(lblScope, 11, 0, 1, 1);

        leState = new QLineEdit(scrollAreaWidgetContentsCustom);
        leState->setObjectName(QString::fromUtf8("leState"));

        gridLayout->addWidget(leState, 12, 1, 1, 4);

        lblRequestTimeout = new QLabel(scrollAreaWidgetContentsCustom);
        lblRequestTimeout->setObjectName(QString::fromUtf8("lblRequestTimeout"));
        sizePolicy2.setHeightForWidth(lblRequestTimeout->sizePolicy().hasHeightForWidth());
        lblRequestTimeout->setSizePolicy(sizePolicy2);
        lblRequestTimeout->setWordWrap(true);

        gridLayout->addWidget(lblRequestTimeout, 18, 0, 1, 1);

        lblRedirectUrl = new QLabel(scrollAreaWidgetContentsCustom);
        lblRedirectUrl->setObjectName(QString::fromUtf8("lblRedirectUrl"));
        lblRedirectUrl->setWordWrap(true);

        gridLayout->addWidget(lblRedirectUrl, 4, 0, 1, 1);

        spnbxRequestTimeout = new QSpinBox(scrollAreaWidgetContentsCustom);
        spnbxRequestTimeout->setObjectName(QString::fromUtf8("spnbxRequestTimeout"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spnbxRequestTimeout->sizePolicy().hasHeightForWidth());
        spnbxRequestTimeout->setSizePolicy(sizePolicy3);
        spnbxRequestTimeout->setAlignment(Qt::AlignCenter);
        spnbxRequestTimeout->setMinimum(5);
        spnbxRequestTimeout->setMaximum(3600);
        spnbxRequestTimeout->setValue(30);

        gridLayout->addWidget(spnbxRequestTimeout, 18, 1, 1, 1);

        lblDescription = new QLabel(scrollAreaWidgetContentsCustom);
        lblDescription->setObjectName(QString::fromUtf8("lblDescription"));
        lblDescription->setWordWrap(true);

        gridLayout->addWidget(lblDescription, 0, 0, 1, 1);

        leRefreshTokenUrl = new QLineEdit(scrollAreaWidgetContentsCustom);
        leRefreshTokenUrl->setObjectName(QString::fromUtf8("leRefreshTokenUrl"));

        gridLayout->addWidget(leRefreshTokenUrl, 3, 1, 1, 4);

        lblApiKey = new QLabel(scrollAreaWidgetContentsCustom);
        lblApiKey->setObjectName(QString::fromUtf8("lblApiKey"));
        sizePolicy2.setHeightForWidth(lblApiKey->sizePolicy().hasHeightForWidth());
        lblApiKey->setSizePolicy(sizePolicy2);
        lblApiKey->setWordWrap(true);

        gridLayout->addWidget(lblApiKey, 13, 0, 1, 1);

        leRequestUrl = new QLineEdit(scrollAreaWidgetContentsCustom);
        leRequestUrl->setObjectName(QString::fromUtf8("leRequestUrl"));

        gridLayout->addWidget(leRequestUrl, 1, 1, 1, 4);

        line = new QFrame(scrollAreaWidgetContentsCustom);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 14, 0, 1, 5);

        lblRequestUrl = new QLabel(scrollAreaWidgetContentsCustom);
        lblRequestUrl->setObjectName(QString::fromUtf8("lblRequestUrl"));
        lblRequestUrl->setWordWrap(true);

        gridLayout->addWidget(lblRequestUrl, 1, 0, 1, 1);

        leScope = new QLineEdit(scrollAreaWidgetContentsCustom);
        leScope->setObjectName(QString::fromUtf8("leScope"));

        gridLayout->addWidget(leScope, 11, 1, 1, 4);

        lblAccessMethod = new QLabel(scrollAreaWidgetContentsCustom);
        lblAccessMethod->setObjectName(QString::fromUtf8("lblAccessMethod"));
        sizePolicy2.setHeightForWidth(lblAccessMethod->sizePolicy().hasHeightForWidth());
        lblAccessMethod->setSizePolicy(sizePolicy2);
        lblAccessMethod->setWordWrap(true);

        gridLayout->addWidget(lblAccessMethod, 17, 0, 1, 1);

        lblUsername = new QLabel(scrollAreaWidgetContentsCustom);
        lblUsername->setObjectName(QString::fromUtf8("lblUsername"));

        gridLayout->addWidget(lblUsername, 9, 0, 1, 1);

        leApiKey = new QLineEdit(scrollAreaWidgetContentsCustom);
        leApiKey->setObjectName(QString::fromUtf8("leApiKey"));

        gridLayout->addWidget(leApiKey, 13, 1, 1, 4);

        label = new QLabel(scrollAreaWidgetContentsCustom);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setItalic(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 15, 0, 1, 5);

        lblPassword = new QLabel(scrollAreaWidgetContentsCustom);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));

        gridLayout->addWidget(lblPassword, 10, 0, 1, 1);

        cmbbxAccessMethod = new QComboBox(scrollAreaWidgetContentsCustom);
        cmbbxAccessMethod->setObjectName(QString::fromUtf8("cmbbxAccessMethod"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cmbbxAccessMethod->sizePolicy().hasHeightForWidth());
        cmbbxAccessMethod->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(cmbbxAccessMethod, 17, 1, 1, 4);

        pteDescription = new QPlainTextEdit(scrollAreaWidgetContentsCustom);
        pteDescription->setObjectName(QString::fromUtf8("pteDescription"));
        pteDescription->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(pteDescription, 0, 1, 1, 4);

        leTokenUrl = new QLineEdit(scrollAreaWidgetContentsCustom);
        leTokenUrl->setObjectName(QString::fromUtf8("leTokenUrl"));

        gridLayout->addWidget(leTokenUrl, 2, 1, 1, 4);

        leClientSecret = new QgsPasswordLineEdit(scrollAreaWidgetContentsCustom);
        leClientSecret->setObjectName(QString::fromUtf8("leClientSecret"));

        gridLayout->addWidget(leClientSecret, 8, 1, 1, 4);

        chkbxTokenPersist = new QCheckBox(scrollAreaWidgetContentsCustom);
        chkbxTokenPersist->setObjectName(QString::fromUtf8("chkbxTokenPersist"));

        gridLayout->addWidget(chkbxTokenPersist, 16, 1, 1, 3);

        lblTokenUrl = new QLabel(scrollAreaWidgetContentsCustom);
        lblTokenUrl->setObjectName(QString::fromUtf8("lblTokenUrl"));
        lblTokenUrl->setWordWrap(true);

        gridLayout->addWidget(lblTokenUrl, 2, 0, 1, 1);

        lblClientSecret = new QLabel(scrollAreaWidgetContentsCustom);
        lblClientSecret->setObjectName(QString::fromUtf8("lblClientSecret"));
        lblClientSecret->setWordWrap(true);

        gridLayout->addWidget(lblClientSecret, 8, 0, 1, 1);

        lePassword = new QgsPasswordLineEdit(scrollAreaWidgetContentsCustom);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));

        gridLayout->addWidget(lePassword, 10, 1, 1, 4);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 19, 1, 1, 1);

        lblClientId = new QLabel(scrollAreaWidgetContentsCustom);
        lblClientId->setObjectName(QString::fromUtf8("lblClientId"));
        lblClientId->setWordWrap(true);

        gridLayout->addWidget(lblClientId, 7, 0, 1, 1);

        leClientId = new QLineEdit(scrollAreaWidgetContentsCustom);
        leClientId->setObjectName(QString::fromUtf8("leClientId"));

        gridLayout->addWidget(leClientId, 7, 1, 1, 4);

        lblState = new QLabel(scrollAreaWidgetContentsCustom);
        lblState->setObjectName(QString::fromUtf8("lblState"));

        gridLayout->addWidget(lblState, 12, 0, 1, 1);

        lblTokenPersist = new QLabel(scrollAreaWidgetContentsCustom);
        lblTokenPersist->setObjectName(QString::fromUtf8("lblTokenPersist"));
        lblTokenPersist->setWordWrap(true);

        gridLayout->addWidget(lblTokenPersist, 16, 0, 1, 1);

        lblRefreshTokenUrl = new QLabel(scrollAreaWidgetContentsCustom);
        lblRefreshTokenUrl->setObjectName(QString::fromUtf8("lblRefreshTokenUrl"));
        lblRefreshTokenUrl->setWordWrap(true);

        gridLayout->addWidget(lblRefreshTokenUrl, 3, 0, 1, 1);

        leUsername = new QLineEdit(scrollAreaWidgetContentsCustom);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout->addWidget(leUsername, 9, 1, 1, 4);

        frameRedirectUrl = new QFrame(scrollAreaWidgetContentsCustom);
        frameRedirectUrl->setObjectName(QString::fromUtf8("frameRedirectUrl"));
        horizontalLayout_4 = new QHBoxLayout(frameRedirectUrl);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lblRedirectIP = new QLabel(frameRedirectUrl);
        lblRedirectIP->setObjectName(QString::fromUtf8("lblRedirectIP"));

        horizontalLayout_4->addWidget(lblRedirectIP);

        spnbxRedirectPort = new QSpinBox(frameRedirectUrl);
        spnbxRedirectPort->setObjectName(QString::fromUtf8("spnbxRedirectPort"));
        sizePolicy3.setHeightForWidth(spnbxRedirectPort->sizePolicy().hasHeightForWidth());
        spnbxRedirectPort->setSizePolicy(sizePolicy3);
        spnbxRedirectPort->setAlignment(Qt::AlignCenter);
        spnbxRedirectPort->setMinimum(0);
        spnbxRedirectPort->setMaximum(9999);
        spnbxRedirectPort->setValue(0);

        horizontalLayout_4->addWidget(spnbxRedirectPort);

        lblRedirectUrlSep = new QLabel(frameRedirectUrl);
        lblRedirectUrlSep->setObjectName(QString::fromUtf8("lblRedirectUrlSep"));

        horizontalLayout_4->addWidget(lblRedirectUrlSep);

        leRedirectUrl = new QLineEdit(frameRedirectUrl);
        leRedirectUrl->setObjectName(QString::fromUtf8("leRedirectUrl"));
        leRedirectUrl->setMinimumSize(QSize(50, 0));

        horizontalLayout_4->addWidget(leRedirectUrl);


        gridLayout->addWidget(frameRedirectUrl, 4, 1, 1, 4);

        scrollAreaConfigure->setWidget(scrollAreaWidgetContentsCustom);

        verticalLayout_3->addWidget(scrollAreaConfigure);

        tabConfigs->addTab(tabCustom, QString());
        tabDefined = new QWidget();
        tabDefined->setObjectName(QString::fromUtf8("tabDefined"));
        verticalLayout_2 = new QVBoxLayout(tabDefined);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lstwdgDefinedConfigs = new QListWidget(tabDefined);
        lstwdgDefinedConfigs->setObjectName(QString::fromUtf8("lstwdgDefinedConfigs"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(4);
        sizePolicy5.setHeightForWidth(lstwdgDefinedConfigs->sizePolicy().hasHeightForWidth());
        lstwdgDefinedConfigs->setSizePolicy(sizePolicy5);
        QFont font1;
        font1.setPointSize(13);
        lstwdgDefinedConfigs->setFont(font1);
        lstwdgDefinedConfigs->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        lstwdgDefinedConfigs->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lstwdgDefinedConfigs->setProperty("showDropIndicator", QVariant(false));
        lstwdgDefinedConfigs->setAlternatingRowColors(true);
        lstwdgDefinedConfigs->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        lstwdgDefinedConfigs->setSpacing(2);
        lstwdgDefinedConfigs->setUniformItemSizes(true);

        verticalLayout_5->addWidget(lstwdgDefinedConfigs);

        pteDefinedDesc = new QPlainTextEdit(tabDefined);
        pteDefinedDesc->setObjectName(QString::fromUtf8("pteDefinedDesc"));
        QFont font2;
        font2.setPointSize(10);
        pteDefinedDesc->setFont(font2);
        pteDefinedDesc->setUndoRedoEnabled(false);
        pteDefinedDesc->setReadOnly(true);
        pteDefinedDesc->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_5->addWidget(pteDefinedDesc);

        verticalLayout_5->setStretch(0, 3);
        verticalLayout_5->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leDefinedDirPath = new QLineEdit(tabDefined);
        leDefinedDirPath->setObjectName(QString::fromUtf8("leDefinedDirPath"));
        leDefinedDirPath->setReadOnly(true);

        horizontalLayout->addWidget(leDefinedDirPath);

        btnGetDefinedDirPath = new QToolButton(tabDefined);
        btnGetDefinedDirPath->setObjectName(QString::fromUtf8("btnGetDefinedDirPath"));
        btnGetDefinedDirPath->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/oauth2method/oauth2_resources/fileopen.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnGetDefinedDirPath->setIcon(icon2);
        btnGetDefinedDirPath->setIconSize(QSize(20, 14));

        horizontalLayout->addWidget(btnGetDefinedDirPath);


        verticalLayout_2->addLayout(horizontalLayout);

        tabConfigs->addTab(tabDefined, QString());
        splitter->addWidget(tabConfigs);
        grpbxAdvanced = new QgsCollapsibleGroupBoxBasic(splitter);
        grpbxAdvanced->setObjectName(QString::fromUtf8("grpbxAdvanced"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(4);
        sizePolicy6.setHeightForWidth(grpbxAdvanced->sizePolicy().hasHeightForWidth());
        grpbxAdvanced->setSizePolicy(sizePolicy6);
        verticalLayout_4 = new QVBoxLayout(grpbxAdvanced);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollAreaAdvanced = new QScrollArea(grpbxAdvanced);
        scrollAreaAdvanced->setObjectName(QString::fromUtf8("scrollAreaAdvanced"));
        scrollAreaAdvanced->setFrameShape(QFrame::NoFrame);
        scrollAreaAdvanced->setWidgetResizable(true);
        scrollAreaWidgetContentsAdvanced = new QWidget();
        scrollAreaWidgetContentsAdvanced->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsAdvanced"));
        scrollAreaWidgetContentsAdvanced->setGeometry(QRect(0, 0, 413, 298));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContentsAdvanced);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tblwdgQueryPairs = new QTableWidget(scrollAreaWidgetContentsAdvanced);
        if (tblwdgQueryPairs->columnCount() < 2)
            tblwdgQueryPairs->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblwdgQueryPairs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblwdgQueryPairs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tblwdgQueryPairs->setObjectName(QString::fromUtf8("tblwdgQueryPairs"));
        tblwdgQueryPairs->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tblwdgQueryPairs->setDragEnabled(true);
        tblwdgQueryPairs->setDragDropMode(QAbstractItemView::DragOnly);
        tblwdgQueryPairs->setSelectionMode(QAbstractItemView::SingleSelection);
        tblwdgQueryPairs->setSortingEnabled(true);
        tblwdgQueryPairs->setWordWrap(false);
        tblwdgQueryPairs->horizontalHeader()->setDefaultSectionSize(120);
        tblwdgQueryPairs->horizontalHeader()->setMinimumSectionSize(120);
        tblwdgQueryPairs->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tblwdgQueryPairs->horizontalHeader()->setStretchLastSection(true);
        tblwdgQueryPairs->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(tblwdgQueryPairs);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        btnAddQueryPair = new QToolButton(scrollAreaWidgetContentsAdvanced);
        btnAddQueryPair->setObjectName(QString::fromUtf8("btnAddQueryPair"));
        btnAddQueryPair->setMinimumSize(QSize(24, 0));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        btnAddQueryPair->setFont(font3);
        btnAddQueryPair->setText(QString::fromUtf8("+"));

        verticalLayout_6->addWidget(btnAddQueryPair);

        btnRemoveQueryPair = new QToolButton(scrollAreaWidgetContentsAdvanced);
        btnRemoveQueryPair->setObjectName(QString::fromUtf8("btnRemoveQueryPair"));
        btnRemoveQueryPair->setMinimumSize(QSize(24, 0));
        btnRemoveQueryPair->setFont(font3);
        btnRemoveQueryPair->setText(QString::fromUtf8("\342\200\223"));

        verticalLayout_6->addWidget(btnRemoveQueryPair);

        verticalSpacer_7 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_7);


        horizontalLayout_5->addLayout(verticalLayout_6);


        gridLayout_3->addLayout(horizontalLayout_5, 3, 0, 1, 2);

        scrollAreaAdvanced->setWidget(scrollAreaWidgetContentsAdvanced);

        verticalLayout_4->addWidget(scrollAreaAdvanced);

        splitter->addWidget(grpbxAdvanced);

        verticalLayout->addWidget(splitter);

        QWidget::setTabOrder(cmbbxGrantFlow, pteDescription);
        QWidget::setTabOrder(pteDescription, leRequestUrl);
        QWidget::setTabOrder(leRequestUrl, leTokenUrl);
        QWidget::setTabOrder(leTokenUrl, leRefreshTokenUrl);
        QWidget::setTabOrder(leRefreshTokenUrl, spnbxRedirectPort);
        QWidget::setTabOrder(spnbxRedirectPort, leRedirectUrl);
        QWidget::setTabOrder(leRedirectUrl, leClientId);
        QWidget::setTabOrder(leClientId, leClientSecret);
        QWidget::setTabOrder(leClientSecret, leUsername);
        QWidget::setTabOrder(leUsername, lePassword);
        QWidget::setTabOrder(lePassword, leScope);
        QWidget::setTabOrder(leScope, leState);
        QWidget::setTabOrder(leState, leApiKey);
        QWidget::setTabOrder(leApiKey, chkbxTokenPersist);
        QWidget::setTabOrder(chkbxTokenPersist, cmbbxAccessMethod);
        QWidget::setTabOrder(cmbbxAccessMethod, spnbxRequestTimeout);
        QWidget::setTabOrder(spnbxRequestTimeout, scrollAreaAdvanced);
        QWidget::setTabOrder(scrollAreaAdvanced, tblwdgQueryPairs);
        QWidget::setTabOrder(tblwdgQueryPairs, btnAddQueryPair);
        QWidget::setTabOrder(btnAddQueryPair, btnRemoveQueryPair);
        QWidget::setTabOrder(btnRemoveQueryPair, btnExport);
        QWidget::setTabOrder(btnExport, btnImport);
        QWidget::setTabOrder(btnImport, leDefinedDirPath);
        QWidget::setTabOrder(leDefinedDirPath, tabConfigs);
        QWidget::setTabOrder(tabConfigs, scrollAreaConfigure);
        QWidget::setTabOrder(scrollAreaConfigure, btnGetDefinedDirPath);
        QWidget::setTabOrder(btnGetDefinedDirPath, lstwdgDefinedConfigs);
        QWidget::setTabOrder(lstwdgDefinedConfigs, pteDefinedDesc);

        retranslateUi(QgsAuthOAuth2Edit);

        tabConfigs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsAuthOAuth2Edit);
    } // setupUi

    void retranslateUi(QWidget *QgsAuthOAuth2Edit)
    {
        lblGrantFlow->setText(QApplication::translate("QgsAuthOAuth2Edit", "Grant Flow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnExport->setToolTip(QApplication::translate("QgsAuthOAuth2Edit", "Export configuration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnExport->setText(QApplication::translate("QgsAuthOAuth2Edit", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnImport->setToolTip(QApplication::translate("QgsAuthOAuth2Edit", "Import configuration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnImport->setText(QApplication::translate("QgsAuthOAuth2Edit", "...", 0, QApplication::UnicodeUTF8));
        lblScope->setText(QApplication::translate("QgsAuthOAuth2Edit", "Scope", 0, QApplication::UnicodeUTF8));
        leState->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Recommended", 0, QApplication::UnicodeUTF8));
        lblRequestTimeout->setText(QApplication::translate("QgsAuthOAuth2Edit", "Request Timeout", 0, QApplication::UnicodeUTF8));
        lblRedirectUrl->setText(QApplication::translate("QgsAuthOAuth2Edit", "Redirect URL", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spnbxRequestTimeout->setToolTip(QApplication::translate("QgsAuthOAuth2Edit", "Authorization-related timeout", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        spnbxRequestTimeout->setSuffix(QApplication::translate("QgsAuthOAuth2Edit", " seconds", 0, QApplication::UnicodeUTF8));
        lblDescription->setText(QApplication::translate("QgsAuthOAuth2Edit", "Description", 0, QApplication::UnicodeUTF8));
        leRefreshTokenUrl->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Optional", 0, QApplication::UnicodeUTF8));
        lblApiKey->setText(QApplication::translate("QgsAuthOAuth2Edit", "API Key", 0, QApplication::UnicodeUTF8));
        leRequestUrl->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Required", 0, QApplication::UnicodeUTF8));
        lblRequestUrl->setText(QApplication::translate("QgsAuthOAuth2Edit", "Request URL", 0, QApplication::UnicodeUTF8));
        leScope->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Optional (space delimiter)", 0, QApplication::UnicodeUTF8));
        lblAccessMethod->setText(QApplication::translate("QgsAuthOAuth2Edit", "Access Method", 0, QApplication::UnicodeUTF8));
        lblUsername->setText(QApplication::translate("QgsAuthOAuth2Edit", "Username", 0, QApplication::UnicodeUTF8));
        leApiKey->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Optional", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QgsAuthOAuth2Edit", "Advanced", 0, QApplication::UnicodeUTF8));
        lblPassword->setText(QApplication::translate("QgsAuthOAuth2Edit", "Password", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmbbxAccessMethod->setToolTip(QApplication::translate("QgsAuthOAuth2Edit", "Resource access token method", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        leTokenUrl->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Required", 0, QApplication::UnicodeUTF8));
        leClientSecret->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Required", 0, QApplication::UnicodeUTF8));
        chkbxTokenPersist->setText(QApplication::translate("QgsAuthOAuth2Edit", "Persist between launches", 0, QApplication::UnicodeUTF8));
        lblTokenUrl->setText(QApplication::translate("QgsAuthOAuth2Edit", "Token URL", 0, QApplication::UnicodeUTF8));
        lblClientSecret->setText(QApplication::translate("QgsAuthOAuth2Edit", "Client Secret", 0, QApplication::UnicodeUTF8));
        lePassword->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Required", 0, QApplication::UnicodeUTF8));
        lblClientId->setText(QApplication::translate("QgsAuthOAuth2Edit", "Client ID", 0, QApplication::UnicodeUTF8));
        leClientId->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Required", 0, QApplication::UnicodeUTF8));
        lblState->setText(QApplication::translate("QgsAuthOAuth2Edit", "State", 0, QApplication::UnicodeUTF8));
        lblTokenPersist->setText(QApplication::translate("QgsAuthOAuth2Edit", "Token Session", 0, QApplication::UnicodeUTF8));
        lblRefreshTokenUrl->setText(QApplication::translate("QgsAuthOAuth2Edit", "Refresh Token URL", 0, QApplication::UnicodeUTF8));
        leUsername->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Required", 0, QApplication::UnicodeUTF8));
        lblRedirectIP->setText(QApplication::translate("QgsAuthOAuth2Edit", "http://127.0.0.1:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spnbxRedirectPort->setToolTip(QApplication::translate("QgsAuthOAuth2Edit", "Port number", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblRedirectUrlSep->setText(QApplication::translate("QgsAuthOAuth2Edit", "/", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        leRedirectUrl->setToolTip(QApplication::translate("QgsAuthOAuth2Edit", "Subdirectory", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        leRedirectUrl->setPlaceholderText(QApplication::translate("QgsAuthOAuth2Edit", "Optional", 0, QApplication::UnicodeUTF8));
        tabConfigs->setTabText(tabConfigs->indexOf(tabCustom), QApplication::translate("QgsAuthOAuth2Edit", "Configure", 0, QApplication::UnicodeUTF8));
        pteDefinedDesc->setPlainText(QApplication::translate("QgsAuthOAuth2Edit", "Defined configurations are JSON-formatted files, with a single configuration per file. This allows configurations to be swapped out via filesystem tools without affecting user configurations. It is recommended to use the Configure tab\342\200\231s export function, then edit the resulting file. See QGIS documentation for further details.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnGetDefinedDirPath->setToolTip(QApplication::translate("QgsAuthOAuth2Edit", "Add extra config directory to parse", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnGetDefinedDirPath->setText(QApplication::translate("QgsAuthOAuth2Edit", "...", 0, QApplication::UnicodeUTF8));
        tabConfigs->setTabText(tabConfigs->indexOf(tabDefined), QApplication::translate("QgsAuthOAuth2Edit", "Defined", 0, QApplication::UnicodeUTF8));
        grpbxAdvanced->setTitle(QApplication::translate("QgsAuthOAuth2Edit", "Extra initial request parameters", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tblwdgQueryPairs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("QgsAuthOAuth2Edit", "Key", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tblwdgQueryPairs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("QgsAuthOAuth2Edit", "Value (unencoded)", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(QgsAuthOAuth2Edit);
    } // retranslateUi

};

namespace Ui {
    class QgsAuthOAuth2Edit: public Ui_QgsAuthOAuth2Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSAUTHOAUTH2EDIT_H
