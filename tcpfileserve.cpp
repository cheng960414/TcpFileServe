#include "tcpfileserve.h"

TcpFileServe::TcpFileServe(QWidget *parent)
    : QDialog(parent)
{

    totalBytes =0;
    bytesReceived=0;
    fileNameSize=0;
    serveProgressBar = new QProgressBar;
    serveStatusLabel = new QLabel(tr("伺服器端就緒"));
    startButton = new QPushButton(tr("接收"));
    quitButton= new QPushButton(tr("退出"));
    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(serveProgressBar);
    mainLayout->addWidget(serveStatusLabel);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("接收檔案"));
    connect(startButton, &QPushButton::clicked, this, &TcpFileServe::startListening);
    connect(quitButton, &QPushButton::clicked, this, &TcpFileServe::close);
    connect(&tcpServer, &QTcpServer::newConnection, this, &TcpFileServe::acceptConnection);

}

TcpFileServe::~TcpFileServe(){

}

void TcpFileServe::startListening()
{
    startButton->setEnabled(false);
    bytesReceived = 0;
    fileNameSize = 0;

    while (!tcpServer.isListening() && !tcpServer.listen(QHostAddress::AnyIPv4, 16689)) {
        QMessageBox::StandardButton ret = QMessageBox::critical(
            this,
            tr("迴圈"),
            tr("無法啟動伺服器: %1.").arg(tcpServer.errorString()),
            QMessageBox::Retry | QMessageBox::Cancel
            );
        if (ret == QMessageBox::Cancel) {
            startButton->setEnabled(true);
            return;
        }
    }
    serveStatusLabel->setText(tr("監聽中..."));
}
void TcpFileServe::acceptConnection(){

}void TcpFileServe::updateServerProgress(){

}
void TcpFileServe::displayError(QAbstractSocket::SocketError socketError) {


}