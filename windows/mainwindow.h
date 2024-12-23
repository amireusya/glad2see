#pragma once
#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include "../common.h"
#include "joinwindow.h"
#include "../trackplayer.hpp"

class CMainWindow : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    QML_ELEMENT
public:
    explicit CMainWindow(QObject *parent = nullptr);
    ~CMainWindow();
    QString userName();
    void setUserName(const QString &userName);
    bool bSubscriptionCheck();
    QSettings* qs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");
private:
    CJoinWindow *pJoinWindow;
    QString m_userName;
    bool m_bIsMaximized = true;
    CTrackPlayer* pTrackPlayer;
    
signals:
    void userNameChanged();

public slots:


};
#endif // CMAINWINDOW_H