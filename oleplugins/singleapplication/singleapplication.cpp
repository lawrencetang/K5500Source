// "single_application.cpp"

#include <QTimer>
#include <QByteArray>

#include "singleapplication.h"

#ifdef ACTIVE_WINDOW_TO_TOP
#include <QLibrary>
#endif

SingleApplication::SingleApplication(int &argc, char *argv[], const QString uniqueKey) : QApplication(argc, argv)
{
    sharedMemory.setKey(uniqueKey);

    // when  can create it only if it doesn't exist
    if (sharedMemory.create(5000))
    {
        sharedMemory.lock();
        *(char*)sharedMemory.data() = '\0';
        sharedMemory.unlock();

        bAlreadyExists = false;
        m_bApiVarOk = InitAPIVar();

        // start checking for messages of other instances.
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(checkForMessage()));
        timer->start(200);
    }
    // it exits, so we can attach it?!
    else if (sharedMemory.attach()){
        bAlreadyExists = true;
    }
    else{
        // error
    }

}

// public slots.
void SingleApplication::checkForMessage()
{
    QStringList arguments;

    sharedMemory.lock();
    char *from = (char*)sharedMemory.data();

    while(*from != '\0'){
        int sizeToRead = int(*from);
        ++from;

        QByteArray byteArray = QByteArray(from, sizeToRead);
        byteArray[sizeToRead] = '\0';
        from += sizeToRead;

        arguments << QString::fromUtf8(byteArray.constData());
    }

    *(char*)sharedMemory.data() = '\0';
    sharedMemory.unlock();

    if(arguments.size()) emit messageAvailable( arguments );
}

// public functions.
bool SingleApplication::sendMessage(const QString &message)
{
    //we cannot send mess if we are master process!
    if (isMasterApp()){
        return false;
    }

    QByteArray byteArray;
    byteArray.append(char(message.size()));
    byteArray.append(message.toUtf8());
    byteArray.append('\0');

    sharedMemory.lock();
    char *to = (char*)sharedMemory.data();
    while(*to != '\0'){
        int sizeToRead = int(*to);
        to += sizeToRead + 1;
    }

    const char *from = byteArray.data();
    memcpy(to, from, qMin(sharedMemory.size(), byteArray.size()));
    sharedMemory.unlock();

    return true;
}

#ifdef ACTIVE_WINDOW_TO_TOP
bool SingleApplication::InitAPIVar() {
    QLibrary user32("user32");
    if (!user32.load()) {
        return false;
    }

    GetWindowThreadProcessId = (TYPE_GetWindowThreadProcessId)user32.resolve("GetWindowThreadProcessId");
    if (!GetWindowThreadProcessId) {
        return false;
    }
    GetForegroundWindow = (TYPE_GetForegroundWindow)user32.resolve("GetForegroundWindow");
    if (!GetForegroundWindow) {
        return false;
    }
    SetForegroundWindow = (TYPE_SetForegroundWindow)user32.resolve("SetForegroundWindow");
    if (!SetForegroundWindow) {
        return false;
    }
    SetFocus = (TYPE_SetFocus)user32.resolve("SetFocus") ;
    if (!SetFocus) {
        return false;
    }
    AttachThreadInput = (TYPE_AttachThreadInput)user32.resolve("AttachThreadInput") ;
    if (!AttachThreadInput) {
        return false;
    }
    QLibrary kernel32("kernel32");
    if (!kernel32.load()) {
        return false;
    }
    GetCurrentThreadId = (TYPE_GetCurrentThreadId)kernel32.resolve("GetCurrentThreadId");
    if (!GetCurrentThreadId) {
        return false;
    }
    return true;
}

void SingleApplication::BringWindowToTop(WId id) {
    if (m_bApiVarOk) {
        AttachThreadInput(GetWindowThreadProcessId(GetForegroundWindow(), NULL), GetCurrentThreadId(), true);
        SetForegroundWindow(id);
        SetFocus(id);
        AttachThreadInput(GetWindowThreadProcessId(GetForegroundWindow(), NULL), GetCurrentThreadId(), false);
    }
}
#endif
