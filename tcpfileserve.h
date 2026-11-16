#ifndef TCPFILESERVE_H
#define TCPFILESERVE_H

#include <QDialog>
#include<QtNetwork>
#include<QtWidgets>
class TcpFileServe : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileServe(QWidget *parent = nullptr);
    ~TcpFileServe() override;

public slots:
    void startListening();
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QProgressBar     *serveProgressBar;
    QLabel           *serveStatusLabel;
    QPushButton      *startButton;
    QPushButton      *quitButton;
    QDialogButtonBox *buttonBox;

    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
    QFile *localFile;
    QString fileName;
    qint64 totalBytes;
    qint64 bytesReceived;
    qint64 fileNameSize;
    QByteArray inBlock;

};
#endif // TCPFILESERVE_H
