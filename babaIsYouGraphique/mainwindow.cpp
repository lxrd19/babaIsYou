#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    m_fileManager(),
    m_game(m_fileManager.readBoardFromFile("file/level_0.txt")),
    m_layout(std::make_shared<QGridLayout>()),
    m_mainLayout(std::make_shared<QVBoxLayout>()),
    m_butonLayout(std::make_shared<QHBoxLayout>()){
    m_board = m_game.getBoard();
    initButtons();
    initBoardDisplay();
    update();
    setFixedSize(800, 600);
    setFocus();
}


void MainWindow::saveGame() {
    m_game.save();
    auto msgBox = std::make_unique<QMessageBox>(this);
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setText("Level saved!");
    msgBox->show();
    QTimer::singleShot(1000, msgBox.get(), &QMessageBox::accept);
    msgBox.release();
    setFocus();

}

void MainWindow::loadGame() {
    try {
        m_game.load();
        updateBoardDisplay();
        auto msgBox = std::make_unique<QMessageBox>(this);
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText("Loading...");
        msgBox->show();
        QTimer::singleShot(1000, msgBox.get(), &QMessageBox::accept);
        msgBox.release();
    } catch (const std::runtime_error& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
    setFocus();
}


void MainWindow::closeEvent(QCloseEvent *event) {
    QFile file("file/save.txt");
    if (file.exists()) {
        file.remove();
    }
    QWidget::closeEvent(event);
}


MainWindow::~MainWindow() {}

void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);
    QWidget::paintEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Right:
        m_game.move(Direction::RIGHT);
        break;
    case Qt::Key_Left:
        m_game.move(Direction::LEFT);
        break;
    case Qt::Key_Up:
        m_game.move(Direction::UP);
        break;
    case Qt::Key_Down:
        m_game.move(Direction::DOWN);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
    updateBoardDisplay();
    initButtons();
}
