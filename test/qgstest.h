/***************************************************************************
  qgstest - %{Cpp:License:ClassName}

 ---------------------
 begin                : 5.12.2016
 copyright            : (C) 2016 by Matthias Kuhn
 email                : matthias@opengis.ch
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef QGSTEST_H
#define QGSTEST_H

#include <QtTest/QtTest>
#include "qgsapplication.h"

#if QT_VERSION >= QT_VERSION_CHECK( 5, 0, 0 )
#define QGSTEST_MAIN(TestObject) \
  QT_BEGIN_NAMESPACE \
  QTEST_ADD_GPU_BLACKLIST_SUPPORT_DEFS \
  QT_END_NAMESPACE \
  int main(int argc, char *argv[]) \
  { \
    QgsApplication app(argc, argv, false); \
    app.setAttribute(Qt::AA_Use96Dpi, true); \
    QTEST_DISABLE_KEYPAD_NAVIGATION \
    QTEST_ADD_GPU_BLACKLIST_SUPPORT \
    TestObject tc; \
    QTEST_SET_MAIN_SOURCE_PATH \
    return QTest::qExec(&tc, argc, argv); \
  }
#else
#define QGSTEST_MAIN(TestObject) \
  int main(int argc, char *argv[]) \
  { \
    QgsApplication app(argc, argv, false); \
    QTEST_DISABLE_KEYPAD_NAVIGATION \
    TestObject tc; \
    return QTest::qExec(&tc, argc, argv); \
  }
#endif

#endif // QGSTEST_H
