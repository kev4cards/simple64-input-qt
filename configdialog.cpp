#include "configdialog.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>

ControllerTab::ControllerTab(unsigned int controller)
{
    QGridLayout *layout = new QGridLayout;
    QLabel *profileLabel = new QLabel("Profile");
    layout->addWidget(profileLabel, 0, 0);
    QComboBox *profileSelect = new QComboBox;
    layout->addWidget(profileSelect, 0, 1);
    QLabel *gamepadLabel = new QLabel("Gamepad");
    layout->addWidget(gamepadLabel, 1, 0);
    QComboBox *gamepadSelect = new QComboBox;
    layout->addWidget(gamepadSelect, 1, 1);
    QLabel *pakLabel = new QLabel("Pak");
    layout->addWidget(pakLabel, 2, 0);
    QComboBox *pakSelect = new QComboBox;
    layout->addWidget(pakSelect, 2, 1);
    setLayout(layout);
}

ProfileTab::ProfileTab()
{
    QGridLayout *layout = new QGridLayout;
    QComboBox *profileSelect = new QComboBox;
    QPushButton *buttonNew = new QPushButton("New Profile");
    connect(buttonNew, &QPushButton::released, [=]() {
        ProfileEditor editor("");
        editor.exec();
    });
    QPushButton *buttonEdit = new QPushButton("Edit Profile");
    connect(buttonEdit, &QPushButton::released, [=]() {
        ProfileEditor editor(profileSelect->currentText());
        editor.exec();
    });

    QPushButton *buttonDelete = new QPushButton("Delete Profile");
    connect(buttonDelete, &QPushButton::released, [=]() {
        settings->remove(profileSelect->currentText());
    });

    layout->addWidget(profileSelect, 1, 0);
    layout->addWidget(buttonNew, 0, 1);
    layout->addWidget(buttonEdit, 1, 1);
    layout->addWidget(buttonDelete, 1, 2);
    setLayout(layout);
}

ProfileEditor::ProfileEditor(QString profile)
{
    QGridLayout *layout = new QGridLayout;
    QLabel *profileNameLabel = new QLabel("Profile Name");
    QLineEdit *profileName = new QLineEdit;
    layout->addWidget(profileNameLabel, 0, 3);
    layout->addWidget(profileName, 0, 4);

    QFrame* lineH = new QFrame();
    lineH->setFrameShape(QFrame::HLine);
    lineH->setFrameShadow(QFrame::Sunken);
    layout->addWidget(lineH, 1, 0, 1, 8);

    QLabel *buttonLabelA = new QLabel("A");
    buttonLabelA->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushA = new QPushButton("value");
    layout->addWidget(buttonLabelA, 2, 0);
    layout->addWidget(buttonPushA, 2, 1);

    QLabel *buttonLabelB = new QLabel("B");
    buttonLabelB->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushB = new QPushButton("value");
    layout->addWidget(buttonLabelB, 3, 0);
    layout->addWidget(buttonPushB, 3, 1);

    QLabel *buttonLabelZ = new QLabel("Z");
    buttonLabelZ->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushZ = new QPushButton("value");
    layout->addWidget(buttonLabelZ, 4, 0);
    layout->addWidget(buttonPushZ, 4, 1);

    QLabel *buttonLabelStart = new QLabel("Start");
    buttonLabelStart->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushStart = new QPushButton("value");
    layout->addWidget(buttonLabelStart, 5, 0);
    layout->addWidget(buttonPushStart, 5, 1);

    QLabel *buttonLabelLTrigger = new QLabel("Left Trigger");
    buttonLabelLTrigger->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushLTrigger = new QPushButton("value");
    layout->addWidget(buttonLabelLTrigger, 6, 0);
    layout->addWidget(buttonPushLTrigger, 6, 1);

    QLabel *buttonLabelRTrigger = new QLabel("Right Trigger");
    buttonLabelRTrigger->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushRTrigger = new QPushButton("value");
    layout->addWidget(buttonLabelRTrigger, 7, 0);
    layout->addWidget(buttonPushRTrigger, 7, 1);

    QFrame* lineV = new QFrame();
    lineV->setFrameShape(QFrame::VLine);
    lineV->setFrameShadow(QFrame::Sunken);
    layout->addWidget(lineV, 2, 2, 6, 1);

    QLabel *buttonLabelDPadL = new QLabel("DPad Left");
    buttonLabelDPadL->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushDPadL = new QPushButton("value");
    layout->addWidget(buttonLabelDPadL, 2, 3);
    layout->addWidget(buttonPushDPadL, 2, 4);

    QLabel *buttonLabelDPadR = new QLabel("DPad Right");
    buttonLabelDPadR->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushDPadR = new QPushButton("value");
    layout->addWidget(buttonLabelDPadR, 3, 3);
    layout->addWidget(buttonPushDPadR, 3, 4);

    QLabel *buttonLabelDPadU = new QLabel("DPad Up");
    buttonLabelDPadU->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushDPadU = new QPushButton("value");
    layout->addWidget(buttonLabelDPadU, 4, 3);
    layout->addWidget(buttonPushDPadU, 4, 4);

    QLabel *buttonLabelDPadD = new QLabel("DPad Down");
    buttonLabelDPadD->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushDPadD = new QPushButton("value");
    layout->addWidget(buttonLabelDPadD, 5, 3);
    layout->addWidget(buttonPushDPadD, 5, 4);

    QFrame* lineV2 = new QFrame();
    lineV2->setFrameShape(QFrame::VLine);
    lineV2->setFrameShadow(QFrame::Sunken);
    layout->addWidget(lineV2, 2, 5, 6, 1);

    QLabel *buttonLabelCL = new QLabel("C Left");
    buttonLabelCL->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushCL = new QPushButton("value");
    layout->addWidget(buttonLabelCL, 2, 6);
    layout->addWidget(buttonPushCL, 2, 7);

    QLabel *buttonLabelCR = new QLabel("C Right");
    buttonLabelCR->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushCR = new QPushButton("value");
    layout->addWidget(buttonLabelCR, 3, 6);
    layout->addWidget(buttonPushCR, 3, 7);

    QLabel *buttonLabelCU = new QLabel("C Up");
    buttonLabelCU->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushCU = new QPushButton("value");
    layout->addWidget(buttonLabelCU, 4, 6);
    layout->addWidget(buttonPushCU, 4, 7);

    QLabel *buttonLabelCD = new QLabel("C Down");
    buttonLabelCD->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushCD = new QPushButton("value");
    layout->addWidget(buttonLabelCD, 5, 6);
    layout->addWidget(buttonPushCD, 5, 7);


    QLabel *buttonLabelStickL = new QLabel("Control Stick Left");
    buttonLabelStickL->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushStickL = new QPushButton("value");
    layout->addWidget(buttonLabelStickL, 6, 3);
    layout->addWidget(buttonPushStickL, 6, 4);

    QLabel *buttonLabelStickR = new QLabel("Control Stick Right");
    buttonLabelStickR->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushStickR = new QPushButton("value");
    layout->addWidget(buttonLabelStickR, 7, 3);
    layout->addWidget(buttonPushStickR, 7, 4);

    QLabel *buttonLabelStickU = new QLabel("Control Stick Up");
    buttonLabelStickU->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushStickU = new QPushButton("value");
    layout->addWidget(buttonLabelStickU, 6, 6);
    layout->addWidget(buttonPushStickU, 6, 7);

    QLabel *buttonLabelStickD = new QLabel("Control Stick Down");
    buttonLabelStickD->setAlignment(Qt::AlignCenter);
    QPushButton *buttonPushStickD = new QPushButton("value");
    layout->addWidget(buttonLabelStickD, 7, 6);
    layout->addWidget(buttonPushStickD, 7, 7);

    QFrame* lineH2 = new QFrame();
    lineH2->setFrameShape(QFrame::HLine);
    lineH2->setFrameShadow(QFrame::Sunken);
    layout->addWidget(lineH2, 8, 0, 1, 8);

    QPushButton *buttonPushSave = new QPushButton("Save and Close");
    layout->addWidget(buttonPushSave, 9, 0, 1, 2);
    QPushButton *buttonPushClose = new QPushButton("Close Without Saving");
    layout->addWidget(buttonPushClose, 9, 6, 1, 2);

    setLayout(layout);
}

ConfigDialog::ConfigDialog()
{
    unsigned int i;

    tabWidget = new QTabWidget;
    tabWidget->setUsesScrollButtons(0);
    for (i = 1; i < 5; ++i)
        tabWidget->addTab(new ControllerTab(i), "Controller " + QString::number(i));

    tabWidget->addTab(new ProfileTab(), tr("Manage Profiles"));
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);
    setWindowTitle(tr("Controller Configuration"));
}
