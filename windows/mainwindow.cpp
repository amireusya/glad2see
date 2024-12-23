#include "../data/database.h"
#include "mainwindow.h"
#include "../g2s.h"

void CMainWindow::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    spdlog::info("userName changed");
    emit userNameChanged();
    spdlog::info("emitted userNameChanged()");
}

QString CMainWindow::userName()
{
    spdlog::info("return m_userName");
    return m_userName;
}

bool CMainWindow::bSubscriptionCheck()
{
    time_t currentTime = time(0);
    
    CDatabase db;
    time_t reg = db.makeQuery<time_t>("SELECT UNIX_TIMESTAMP(subscripted) FROM users WHERE name = 'asd'", 0); // login
    
    
    spdlog::info(reg);

    time_t expreg = db.makeQuery<time_t>("SELECT UNIX_TIMESTAMP(subtime) FROM users WHERE name = 'asd'", 0);
    bool bExpired = (currentTime > reg+expreg ? true : false);
    spdlog::info("Is ok");
    return bExpired;
}

CMainWindow::CMainWindow(QObject *parent) : QObject(parent)
{
    qmlRegisterType<CMainWindow>("com.window.main", 1, 0, "CMainWindow");
    
}

CMainWindow::~CMainWindow()
{
    QGuiApplication::quit();
}
