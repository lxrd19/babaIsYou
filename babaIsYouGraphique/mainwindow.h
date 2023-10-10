#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "box.h"
#include "filemanager.h"
#include <Qwidget>
#include <QGridLayout>
#include <memory.h>
#include <QLabel>
#include <QKeyEvent>
#include "game.h"
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

/**
 * Main window class for the graphical user interface.
 */
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructs a MainWindow object.
     *
     * @param parent The parent widget.
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * Destroys the MainWindow object.
     */
    ~MainWindow();
    /**
     * Handles key press events.
     *
     * @param event The key event.
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     * Handles close events.
     *
     * @param event The close event.
     */
    void closeEvent(QCloseEvent *event);
protected:
    /**
     * Handles paint events.
     *
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event = nullptr);


private slots:
    /**
     * Saves the current game.
     */
    void saveGame();
    /**
     * Loads a game.
     */
    void loadGame();
private:
    /**
    * Maps the element names to corresponding QPixmap images.
     */
    std::map<std::string, QPixmap> imageMap{
        {"baba",  QPixmap("file/baba.png")},
        {"text_baba",  QPixmap("file/baba_text.png")},
        {"text_best",  QPixmap("file/best_text.png")},
        {"text_flag",  QPixmap("file/flag_text.png")},
        {"is",  QPixmap("file/is.png")},
        {"text_kill",  QPixmap("file/kill_text.png")},
        {"text_lava",  QPixmap("file/lava_text.png")},
        {"lava",  QPixmap("file/lava.png")},
        {"metal",  QPixmap("file/metal.png")},
        {"push",  QPixmap("file/push.png")},
        {"text_rock",  QPixmap("file/rock_text.png")},
        {"text_sink",  QPixmap("file/sink_text.png")},
        {"stop",  QPixmap("file/stop_text.png")},
        {"wall",  QPixmap("file/wall.png")},
        {"text_wall",  QPixmap("file/wall_text.png")},
        {"water",  QPixmap("file/water.png")},
        {"text_water",  QPixmap("file/water_text.png")},
        {"win",  QPixmap("file/win_text.png")},
        {"you",  QPixmap("file/you.png")},
        {"rock",  QPixmap("file/rock.png")},
        {"flag",  QPixmap("file/flag.png")},
        {"kill",  QPixmap("file/kill_text.png")},
        {"grass",  QPixmap("file/grass.png")},
        {"sink",  QPixmap("file/sink_text.png")}

    };
    std::shared_ptr<QPushButton> m_saveButton;
    std::shared_ptr<QPushButton> m_loadButton;

    /**
    * Initializes the save and load buttons.
    */
    void initButtons();
    /**
    * Initializes the board display based on the current game board.
    */
    void initBoardDisplay();

    /**
    * Updates the board display with the latest game board state.
    */
    void updateBoardDisplay();
    std::vector<std::vector<Box>> m_board;
    FileManager m_fileManager;
    Game m_game;
    std::shared_ptr<QGridLayout> m_layout;
    std::shared_ptr<QVBoxLayout> m_mainLayout;
    std::shared_ptr<QHBoxLayout> m_butonLayout;
};

inline void MainWindow::initButtons(){
    m_saveButton = std::make_shared<QPushButton>("Save");
    m_loadButton = std::make_shared<QPushButton>("Load");
    m_saveButton->setFixedSize(60, 30);
    m_loadButton->setFixedSize(60, 30);
    connect(m_saveButton.get(), &QPushButton::clicked, this, &MainWindow::saveGame);
    connect(m_loadButton.get(), &QPushButton::clicked, this, &MainWindow::loadGame);
    m_butonLayout->addWidget(m_saveButton.get());
    m_butonLayout->addWidget(m_loadButton.get());
    m_butonLayout->setAlignment(Qt::AlignLeft);
    m_mainLayout->addLayout(m_butonLayout.get());

}

inline void MainWindow::initBoardDisplay() {
    for (size_t i = 0; i < m_board.size(); ++i) {
        for (size_t j = 0; j < m_board[i].size(); ++j) {
            auto& box = m_board[i][j];
            if (!box.isEmpty()) {
                auto objects = box.getObjects();
                for (const auto& obj : objects) {
                    auto boxLabel = std::make_unique<QLabel>(this);
                    auto name = obj.getName();
                    boxLabel->setPixmap(imageMap[name]);
                    boxLabel->setFixedSize(50, 50);
                    m_layout->addWidget(boxLabel.get(), i, j);
                    boxLabel.release();
                }
            } else {
                auto emptyLabel = std::make_unique<QLabel>(this);
                emptyLabel->setFixedSize(50, 50);
                m_layout->addWidget(emptyLabel.get(), i, j);
                emptyLabel.release();
            }
        }
    }
    m_mainLayout->addLayout(m_layout.get());
    this->setLayout(m_mainLayout.get());
}


inline void MainWindow::updateBoardDisplay() {
    QLayoutItem* item;
    for (int i = m_layout->count() - 1; i >= 0; --i) {
        item = m_layout->takeAt(i);
        if (auto widget = item->widget()) {
            if (widget != m_saveButton.get() && widget != m_loadButton.get()) {
                m_layout->removeWidget(widget);
                delete widget;
            }
        }
        delete item;
    }
    m_board = m_game.getBoard();
    initBoardDisplay();
}


#endif // MAINWINDOW_H
