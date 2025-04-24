#ifndef SKULLKINGSERVER_H
#define SKULLKINGSERVER_H

#include "MyClasses/deck.h"
#include "MyClasses/king.h"
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <fstream>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui
{
	class SkullKingServer;
}
QT_END_NAMESPACE

class SkullKingServer : public QDialog
{
	Q_OBJECT

public:
	SkullKingServer(QWidget* parent = nullptr);
	~SkullKingServer();

private slots:
	void on_Ok_clicked();

	void newConnection();
	void appendToSocketList(QTcpSocket* socket);
	void readSocket();
	void discardSocket();
	void displayError(QAbstractSocket::SocketError socketError);

	bool sendSignal(QTcpSocket* socket, QString signal);
	bool sendFile(QTcpSocket* socket, QString filePath, QString signal);

	void start_game();
	void start_round();
	void play_card(QTcpSocket* qts);

private:
	Ui::SkullKingServer* ui;
	QTcpServer* server;
	QTcpSocket* socket;
	int client_number, round;
	unordered_map<QTcpSocket*, King> clients;
	Deck deck;
};
#endif // SKULLKINGSERVER_H
