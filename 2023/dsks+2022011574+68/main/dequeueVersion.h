#pragma once
#ifndef QVGEVERSION_H 
#define QVGEVERSION_H 
#include <QVersionNumber> 
#include <QString> 
static QString dequeueVersionString("0.6.2");
static QVersionNumber dequeueVersion = QVersionNumber::fromString(dequeueVersionString);

#endif // QVGEVERSION_H 