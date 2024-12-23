#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "data/database.h"
#include "common.h"

#include "windows/mainwindow.h"
#include "windows/joinwindow.h"

#include <mysql.h>
#include "discordrpc.h"
#include "trackplayer.hpp"


int main(int argc, char* argv[])
{
    QGuiApplication a(argc, argv);
    
    /*
    QIcon trayIcon = QIcon(":/data/img/trayIcon.ico");
    QSystemTrayIcon tray(trayIcon, &a);

    QAction titleAction(trayIcon, "glad2see", nullptr);
    QObject::connect(&titleAction, &QAction::triggered, [&a]() {
        QDesktopServices::openUrl(QUrl("https://t.me/amireusya", QUrl::TolerantMode));
    });

    QAction moreInfoAction("About", nullptr);


    QAction quitAction("Exit", nullptr);
    QObject::connect(&quitAction, &QAction::triggered, [&a]() {
        a.quit();
    });



    QMenu trayMenu("glad2see tray", nullptr);

    trayMenu.addAction(&titleAction);
    trayMenu.addAction(&quitAction);

    tray.setContextMenu(&trayMenu);

    tray.show();
    */
    DiscordRPC discord;
    std::thread ds(&DiscordRPC::Start, &discord);
    ds.detach();
    

    

    CDatabase data;

    QQmlApplicationEngine engine;
    CJoinWindow jWnd;
    CMainWindow mWnd;

   

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return a.exec();
}
