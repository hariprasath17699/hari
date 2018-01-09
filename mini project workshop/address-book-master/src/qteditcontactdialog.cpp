#include "contact.h"
#include "qtcontactform.h"
#include "qteditcontactdialog.h"
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>


QtEditContactDialog::QtEditContactDialog(Contact &c, 
                                        QWidget *parent,
                                        Qt::WindowFlags f) :
                                        QDialog(parent, f),
                                        contactForm(new QtContactForm()),
                                        contactToEdit(c)
{
    QVBoxLayout *mainContainer = new QVBoxLayout();
    mainContainer->addLayout(contactForm);

    QHBoxLayout *buttonContainer = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");
    QPushButton *searchButton = new QPushButton("Cancel");

    okButton->setStyleSheet("padding : 05px;border-radius:2%;background-color: brown;color:white");
    cancelButton->setStyleSheet("padding : 05px;border-radius:2%;background-color: green;color:white");
    searchButton->setStyleSheet("padding : 05px;border-radius:2%;background-color: blue;color:white");


    buttonContainer->addWidget(okButton);
    buttonContainer->addWidget(cancelButton);
    buttonContainer->addWidget(searchButton);
    mainContainer->addLayout(buttonContainer);

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    connect(searchButton, SIGNAL(clicked()), this, SLOT(reject()));

    fillForm();
    setLayout(mainContainer);
    setWindowTitle("Edit Contact");
}

void QtEditContactDialog::fillForm()
{
    contactForm->firstNameField->setText(contactToEdit.firstName.c_str());
    contactForm->lastNameField->setText(contactToEdit.lastName.c_str());
    contactForm->addressField->setText(contactToEdit.address.c_str());
    contactForm->phoneNumberField->setText(contactToEdit.phoneNumber.c_str());
    contactForm->emailField->setText(contactToEdit.email.c_str());
    contactForm->cityField->setText(contactToEdit.city.c_str());

}

void QtEditContactDialog::accept()
{
    contactToEdit.firstName = contactForm->firstNameField->text().toStdString();
    contactToEdit.lastName = contactForm->lastNameField->text().toStdString();
    contactToEdit.address = contactForm->addressField->text().toStdString();
    contactToEdit.phoneNumber = contactForm->phoneNumberField->text().toStdString();
    contactToEdit.email = contactForm->emailField->text().toStdString();
    contactToEdit.city = contactForm->cityField->text().toStdString();
    QDialog::accept();

}
